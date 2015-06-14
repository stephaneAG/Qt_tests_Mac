// configwindow.h - digital neurophone using Qt 4.8

#ifndef CONFIGWINDOW_H
#define CONFIGWINDOW_H

#include <QMainWindow>

class QAction;
class QMenu;
// TODO: add class canvas (..)

class ConfigWindow : public QMainWindow {
	
	Q_OBJECT // necessary macro for Qt objects (..)
	
	public:
			ConfigWindow(); // the class constructor
			
	protected:
			//void closeEvent( QCloseEvent *event );
			
	private slots:
			void about(); // wip/debug: test slot displaying the app's about stuff (..)
			
	private:
			void createActions();
			void createMenus();
			//void createToolBars();
			//void createStatusBar();
			
			QMenu *basicMenu;
			QMenu *helpMenu;
			
			QAction *exitAct;
			QAction *aboutAct;
	
};

#endif