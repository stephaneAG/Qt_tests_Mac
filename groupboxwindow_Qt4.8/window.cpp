/****************************************************************************
 **
 ** Copyright (C) 2013 Digia Plc and/or its subsidiary(-ies).
 ** Contact: http://www.qt-project.org/legal
 **
 ** This file is part of the examples of the Qt Toolkit.
 **
 ** $QT_BEGIN_LICENSE:BSD$
 ** You may use this file under the terms of the BSD license as follows:
 **
 ** "Redistribution and use in source and binary forms, with or without
 ** modification, are permitted provided that the following conditions are
 ** met:
 **   * Redistributions of source code must retain the above copyright
 **     notice, this list of conditions and the following disclaimer.
 **   * Redistributions in binary form must reproduce the above copyright
 **     notice, this list of conditions and the following disclaimer in
 **     the documentation and/or other materials provided with the
 **     distribution.
 **   * Neither the name of Digia Plc and its Subsidiary(-ies) nor the names
 **     of its contributors may be used to endorse or promote products derived
 **     from this software without specific prior written permission.
 **
 **
 ** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
 ** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
 ** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
 ** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
 ** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
 ** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
 ** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
 ** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
 ** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
 ** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
 ** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
 **
 ** $QT_END_LICENSE$
 **
 ****************************************************************************/

 #include <QtGui>

 #include "window.h"

 Window::Window(QWidget *parent)
     : QWidget(parent)
 {
     QGridLayout *grid = new QGridLayout;
     grid->addWidget(createFirstExclusiveGroup(), 0, 0);
     grid->addWidget(createSecondExclusiveGroup(), 1, 0);
     grid->addWidget(createNonExclusiveGroup(), 0, 1);
     grid->addWidget(createPushButtonGroup(), 1, 1);
     setLayout(grid);

     setWindowTitle(tr("Group Boxes"));
     resize(480, 320);
 }

 QGroupBox *Window::createFirstExclusiveGroup()
 {
     QGroupBox *groupBox = new QGroupBox(tr("Exclusive Radio Buttons"));

     QRadioButton *radio1 = new QRadioButton(tr("&Radio button 1"));
     QRadioButton *radio2 = new QRadioButton(tr("R&adio button 2"));
     QRadioButton *radio3 = new QRadioButton(tr("Ra&dio button 3"));

     radio1->setChecked(true);

     QVBoxLayout *vbox = new QVBoxLayout;
     vbox->addWidget(radio1);
     vbox->addWidget(radio2);
     vbox->addWidget(radio3);
     vbox->addStretch(1);
     groupBox->setLayout(vbox);

     return groupBox;
 }

 QGroupBox *Window::createSecondExclusiveGroup()
 {
     QGroupBox *groupBox = new QGroupBox(tr("E&xclusive Radio Buttons"));
     groupBox->setCheckable(true);
     groupBox->setChecked(false);

     QRadioButton *radio1 = new QRadioButton(tr("Rad&io button 1"));
     QRadioButton *radio2 = new QRadioButton(tr("Radi&o button 2"));
     QRadioButton *radio3 = new QRadioButton(tr("Radio &button 3"));
     radio1->setChecked(true);
     QCheckBox *checkBox = new QCheckBox(tr("Ind&ependent checkbox"));
     checkBox->setChecked(true);

     QVBoxLayout *vbox = new QVBoxLayout;
     vbox->addWidget(radio1);
     vbox->addWidget(radio2);
     vbox->addWidget(radio3);
     vbox->addWidget(checkBox);
     vbox->addStretch(1);
     groupBox->setLayout(vbox);

     return groupBox;
 }

 QGroupBox *Window::createNonExclusiveGroup()
 {
     QGroupBox *groupBox = new QGroupBox(tr("Non-Exclusive Checkboxes"));
     groupBox->setFlat(true);

     QCheckBox *checkBox1 = new QCheckBox(tr("&Checkbox 1"));
     QCheckBox *checkBox2 = new QCheckBox(tr("C&heckbox 2"));
     checkBox2->setChecked(true);
     QCheckBox *tristateBox = new QCheckBox(tr("Tri-&state button"));
     tristateBox->setTristate(true);
     tristateBox->setCheckState(Qt::PartiallyChecked);

     QVBoxLayout *vbox = new QVBoxLayout;
     vbox->addWidget(checkBox1);
     vbox->addWidget(checkBox2);
     vbox->addWidget(tristateBox);
     vbox->addStretch(1);
     groupBox->setLayout(vbox);

     return groupBox;
 }

 QGroupBox *Window::createPushButtonGroup()
 {
     QGroupBox *groupBox = new QGroupBox(tr("&Push Buttons"));
     groupBox->setCheckable(true);
     groupBox->setChecked(true);

     QPushButton *pushButton = new QPushButton(tr("&Normal Button"));
     QPushButton *toggleButton = new QPushButton(tr("&Toggle Button"));
     toggleButton->setCheckable(true);
     toggleButton->setChecked(true);
     QPushButton *flatButton = new QPushButton(tr("&Flat Button"));
     flatButton->setFlat(true);

     QPushButton *popupButton = new QPushButton(tr("Pop&up Button"));
     QMenu *menu = new QMenu(this);
     menu->addAction(tr("&First Item"));
     menu->addAction(tr("&Second Item"));
     menu->addAction(tr("&Third Item"));
     menu->addAction(tr("F&ourth Item"));
     popupButton->setMenu(menu);

     QAction *newAction = menu->addAction(tr("Submenu"));
     QMenu *subMenu = new QMenu(tr("Popup Submenu"));
     subMenu->addAction(tr("Item 1"));
     subMenu->addAction(tr("Item 2"));
     subMenu->addAction(tr("Item 3"));
     newAction->setMenu(subMenu);

     QVBoxLayout *vbox = new QVBoxLayout;
     vbox->addWidget(pushButton);
     vbox->addWidget(toggleButton);
     vbox->addWidget(flatButton);
     vbox->addWidget(popupButton);
     vbox->addStretch(1);
     groupBox->setLayout(vbox);

     return groupBox;
 }