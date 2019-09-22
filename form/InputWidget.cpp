//
// Created by sam on 2019/9/22.
//

#include "InputWidget.h"
#include <QFileDialog>
InputWidget::InputWidget(QWidget *parent) : QWidget(parent) {
    m_ui.setupUi(this);
    initGUI();
    initSignalAndSlots();
}

void InputWidget::Slot_PushButtonRecognition_Clicked() {

}

void InputWidget::Slot_PushButtonCompound_Clicked() {

}

void InputWidget::Slot_PushButtonFile_Clicked() {
    auto filenames = QFileDialog::getOpenFileName(this);
    m_ui.lineEdit->setText(filenames);
}

void InputWidget::initGUI() {

}

void InputWidget::initSignalAndSlots() {
    connect(m_ui.pushButton_file,SIGNAL(clicked()),this,SLOT(Slot_PushButtonFile_Clicked()));
    connect(m_ui.pushButton_recognition,SIGNAL(clicked()),this,SLOT(Slot_PushButtonRecognition_Clicked()));
    connect(m_ui.pushButton_compound,SIGNAL(clicked()),this,SLOT(Slot_PushButtonCompound_Clicked()));
}
