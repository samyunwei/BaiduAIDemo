//
// Created by sam on 2019/9/22.
//

#include "SoundController.h"
#include "speech.h"

std::mutex SoundController::m_mutex;
SoundController *SoundController::m_instance = nullptr;

SoundController::SoundController() : m_setting(nullptr), m_client(nullptr) {
    m_setting = new QSettings("./private/key.ini", QSettings::IniFormat, nullptr);
    m_setting->beginGroup("pem_key");
    std::string app_id = m_setting->value("APP_ID").toString().toStdString();
    std::string api_key = m_setting->value("API_KEY").toString().toStdString();
    std::string secret_key = m_setting->value("SECRET_KEY").toString().toStdString();
    m_client = std::make_shared<aip::Speech>(app_id, api_key, secret_key);
}

SoundController *SoundController::getInstance() {
    m_mutex.lock();
    if (!m_instance) {
        m_instance = new SoundController();
    }
    m_mutex.unlock();
    return m_instance;
}

int SoundController::RecongnitionSound(const QString &file, const QString &type, QString &result) {
    std::string file_content;
    aip::get_file_content(file.toStdString().c_str(), &file_content);
    Json::Value rep = m_client->recognize(file_content, type.toStdString(), 16000, aip::null);
    if (rep["err_no"].asInt() != 0) {
        result = QString::fromStdString(rep["err_msg"].asString());
        return rep["err_no"].asInt();
    }
    auto res = rep["result"];
    result = "";
    for (const auto &re : res) {
        result.append(QString::fromStdString(re.asString() + "\n"));
    }
    return 0;
}

int SoundController::CompoundSound(QString input, QString output_file) {
    std::ofstream ofile;
    std::string file_ret;
    std::map<std::string, std::string> options;
    options["spd"] = "9";

    // 合成成功的二进制数据写入文件中
    ofile.open(output_file.toStdString(), std::ios::out | std::ios::binary);

    // 不带可选参数调用
    Json::Value result = m_client->text2audio(input.toStdString(), aip::null, file_ret);

    // 带可选参数调用, 参数参考参数列表中的可选参数
    // Json::Value result = client.text2audio("百度语音合成测试", options, file_ret);

    // 如果file_ret为不为空则说明合成成功，返回mp3文件内容回结果
    if (!file_ret.empty()) {
        ofile << file_ret;
    } else {
        // 服务端合成错误
        std::cout << result.toStyledString();
        return result["err_no"].asInt();
    }
    return 0;
}


