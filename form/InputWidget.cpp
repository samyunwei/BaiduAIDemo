//
// Created by sam on 2019/9/22.
//

#include "InputWidget.h"
#include <QFileDialog>
#include "SoundController.h"
#include <QMessageBox>
#include <QProcess>
#include <QApplication>
InputWidget::InputWidget(QWidget *parent) : QWidget(parent) {
    m_ui.setupUi(this);
    initGUI();
    initSignalAndSlots();
}

void InputWidget::Slot_PushButtonRecognition_Clicked() {
    auto c_ptr = SoundController::getInstance();
    if (c_ptr != nullptr) {
        m_ui.plainTextEdit_result->clear();
        QString result;
        auto ret = c_ptr->RecongnitionSound(m_ui.lineEdit_file->text(), m_ui.comboBox_format->currentText().toLower(),
                                            result);
        if (ret != 0) {
            QMessageBox::information(this, "错误", result);
            return;
        }
        m_ui.plainTextEdit_result->setPlainText(result);
    }

}

void InputWidget::Slot_PushButtonCompound_Clicked() {
    auto c_ptr = SoundController::getInstance();
    QString output_file = QApplication::applicationDirPath() + tr("/res/output.mp3");
    if (c_ptr != nullptr) {
        auto ret = SoundController::getInstance()->CompoundSound(m_ui.plainTextEdit_compoud->toPlainText(),
                                                                 output_file);
        if (ret != 0) {
            QMessageBox::information(this, tr("错误"), tr("合成失败！"));
            return;
        }
        QMessageBox::information(this, tr("成功"), tr("合成成功,开始播放！"));
        /**
         * 根据操作系统有关，不用QSound了，不好用。
         */
        QProcess::execute("play " + output_file);
    }
}

void InputWidget::Slot_PushButtonFile_Clicked() {
    auto filenames = QFileDialog::getOpenFileName(this);
    m_ui.lineEdit_file->setText(filenames);
}

void InputWidget::initGUI() {

}

void InputWidget::initSignalAndSlots() {
    connect(m_ui.pushButton_file,SIGNAL(clicked()),this,SLOT(Slot_PushButtonFile_Clicked()));
    connect(m_ui.pushButton_recognition,SIGNAL(clicked()),this,SLOT(Slot_PushButtonRecognition_Clicked()));
    connect(m_ui.pushButton_compound,SIGNAL(clicked()),this,SLOT(Slot_PushButtonCompound_Clicked()));
}
