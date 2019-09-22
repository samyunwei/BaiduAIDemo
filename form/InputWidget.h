//
// Created by sam on 2019/9/22.
//

#ifndef AICOURSECPP_INPUTWIDGET_H
#define AICOURSECPP_INPUTWIDGET_H

#include "ui_form.h"

class InputWidget: public QWidget {
    Q_OBJECT
public:
    explicit InputWidget(QWidget *parent);

public slots:

    void Slot_PushButtonFile_Clicked();
    void Slot_PushButtonRecognition_Clicked();
    void Slot_PushButtonCompound_Clicked();
private:
    Ui::Form m_ui;

    void initGUI();
    void initSignalAndSlots();
};


#endif //AICOURSECPP_INPUTWIDGET_H
