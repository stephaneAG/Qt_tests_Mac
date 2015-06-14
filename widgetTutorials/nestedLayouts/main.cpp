#include <QtGui>

int main(int argc, char *argv[]){
	QApplication app(argc, argv);
    QWidget window;

    QLabel *queryLabel = new QLabel(
         QApplication::translate("nestedlayouts", "Query:"));
    QLineEdit *queryEdit = new QLineEdit();
    QTableView *resultView = new QTableView();

    QHBoxLayout *queryLayout = new QHBoxLayout();
    queryLayout->addWidget(queryLabel);
    queryLayout->addWidget(queryEdit);

    QVBoxLayout *mainLayout = new QVBoxLayout();
    mainLayout->addLayout(queryLayout);
    mainLayout->addWidget(resultView);
    window.setLayout(mainLayout);
	
	// set up the model and configure the view
	QStandardItemModel model;
	model.setHorizontalHeaderLabels(
			QStringList() << QApplication::translate("nestedlayouts", "Name")
						  << QApplication::translate("nestedlayouts", "Office")
									);
	
	QList<QStringList> rows = QList<QStringList>()
					<< (QStringList() << "Stephane GARNIER" << "666")
					<< (QStringList() << "Quentin DEMUTH" << "42")
					<< (QStringList() << "Antoine Hensseman" << "04");
					
	foreach( QStringList row, rows ){
		QList<QStandardItem *> items;
		foreach( QString text, row )
			items.append( new QStandardItem( text ) );
		model.appendRow( items );
	}								
	
	resultView->setModel( &model );
	resultView->verticalHeader()->hide();
	resultView->horizontalHeader()->setStretchLastSection(true);
	
	window.setWindowTitle( QApplication::translate("nestedlayouts", "Nested layouts") );
	window.show();
	
	
	return app.exec();
}