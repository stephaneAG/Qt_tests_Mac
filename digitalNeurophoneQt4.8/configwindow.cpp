// configwindow.cpp - digital neurophone using Qt 4.8

#include <QtGui>

#include "configwindow.h"

ConfigWindow::ConfigWindow(){ // the class's constructor
	createActions();
	createMenus();
	//createStatusBar();
}

//void ConfigWindow::closeEvent( QCloseEvent *event ){
//	event->accept();
//}

void ConfigWindow::about(){
	
	QMessageBox::about( this, tr("About the Digital Neurophone app"),
						tr("The <b>Digital Neurophone</b> app can be used to"
						   " transmit sounds generated from math formulas or music files"
						   " to someone's brain using ultrasounds, therefore bypassing"
						   " the cholchea and the inner ear to effectively produce sound") 
					   );
	
}

void ConfigWindow::createActions(){
	
	exitAct = new QAction( tr("E&xit"), this );
	exitAct->setShortcuts( QKeySequence::Quit );
	exitAct->setStatusTip( tr("Exit the app") );
	connect( exitAct, SIGNAL( triggered() ), this, SLOT( close() ) );
	
	aboutAct = new QAction( tr("&About"), this );
	aboutAct->setStatusTip( tr("About the app") );
	connect( aboutAct, SIGNAL( triggered() ), this, SLOT( about() ) );
	
}

void ConfigWindow::createMenus(){
	
	basicMenu = menuBar()->addMenu( tr("&File") );
	helpMenu->addAction( exitAct );
	
	menuBar()->addSeparator();
	
	helpMenu = menuBar()->addMenu( tr("&Help") );
	helpMenu->addAction( aboutAct );
	
}

//void ConfigWindow::createStatusBar(){
//	statusBar()->showMessage( tr('Ready') );
//}

