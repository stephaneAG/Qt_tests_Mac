#include <QtGui>

int main(int argc, char *argv[]){
	QApplication app(argc, argv);
	QWidget window;
	window.resize(320, 240);
	window.show();
	window.setWindowTitle( QApplication::translate("childwidget", "Child widget") );
	
	// adding the child widget
	QPushButton *button = new QPushButton( QApplication::translate("childwidget", "Press me"), &window );
	button->move(100, 100);
	button->show();
	
	return app.exec();
}