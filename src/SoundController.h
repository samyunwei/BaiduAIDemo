//
// Created by sam on 2019/9/22.
//

#ifndef AICOURSECPP_SOUNDCONTROLLER_H
#define AICOURSECPP_SOUNDCONTROLLER_H

#include <mutex>
#include <QObject>
#include <QSettings>

#include <memory>

namespace aip {
    class Speech;
}
class SoundController {
public:
    static SoundController *getInstance();

    int RecongnitionSound(const QString &file, const QString &type, QString &result);

    int CompoundSound(QString input, QString output_file);

private:
    explicit SoundController();

private:
    static std::mutex m_mutex;
    static SoundController *m_instance;
    QSettings *m_setting;
    std::shared_ptr<aip::Speech> m_client;
};


#endif //AICOURSECPP_SOUNDCONTROLLER_H
