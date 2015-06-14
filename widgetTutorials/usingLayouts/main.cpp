#include <QtGui>

int main(int argc, char *argv[]){
	QApplication app(argc, argv);
	QWidget window;
	
	QLabel *label = new QLabel( QApplication::translate("windowlayout", "Name:") );
	QLineEdit *lineEdit = new QLineEdit();
	
	QHBoxLayout *layout = new QHBoxLayout();
	layout->addWidget( label );
	layout->addWidget( lineEdit );
	
	//window.resize(320, 240);
	window.setLayout( layout );
	window.show();
	//window.setWindowTitle( QApplication::translate("childwidget", "Child widget") );
	
	// adding the child widget
	//QPushButton *button = new QPushButton( QApplication::translate("childwidget", "Press me"), &window );
	//button->move(100, 100);
	//button->show();
	
	return app.exec();
}