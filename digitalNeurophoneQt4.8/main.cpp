// digital neurophone app using Qt c++
// 12/08/2013 by StephaneAG

#include <QApplication>
//#include <QMainWIndow>

// includes of the external files
#include "configwindow.h"
//#include "canvaswindow.h"

int main( int argc, char * argv[]){
	
	// to init resources, we'd use the following ( -> we need an 'application.qrc' file for that (..) )
	//Q_INIT_RESOURCES( application );
	
	QApplication app(argc, argv);
	
	// basic parameters of the status bar (..)
	app.setOrganizationName("Seeds Design");
	app.setApplicationName("Digital Neurophone v0.1a");
	
	// simplest setup ever -> we create a basic QWindow widget (..)
	//QMainWindow mainWin; // basic test with Qt original class for main windows objects (..)
	ConfigWindow mainWin;
	
#if defined( Q_OS_SYMBIAN )
	mainWin.showMaximized();
#else
	mainWin.show();
#endif
	
	// as usual, end the loop returning 'app.exec()'
	return app.exec();
	
}