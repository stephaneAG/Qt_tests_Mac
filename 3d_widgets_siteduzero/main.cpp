#include <QApplication>
#include <QtGui>
#include <QWebView>

// R: add ' QT += webkit ' to the .pro file

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
 
    QWebView *web = new QWebView();
    web->load(QUrl("http://www.siteduzero.com"));
    web->show();
 
    QGraphicsScene scene;
    scene.setSceneRect(0 , 0, 1000, 800);
 
    QGraphicsProxyWidget *proxy = new QGraphicsProxyWidget();
    proxy->setWidget(web);
    scene.addItem(proxy);
 
    QTransform matrix;
    matrix.rotate(45, Qt::YAxis);
    proxy->setTransform(matrix);
 
    QGraphicsView view(&scene);
    view.show();
 
    view.setWindowTitle("Ma première scène");
    return app.exec();
}

/*
#include <QApplication>
#include <QtGui>
 
int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
 
    QPushButton *bouton = new QPushButton("Mon bouton entre en scène !");
    QGraphicsScene scene;
    scene.setSceneRect(-150, -150, 300, 300); // override the default, centered, positionning of the scene
    QGraphicsProxyWidget *proxy = new QGraphicsProxyWidget();
    proxy->setWidget(bouton);
    scene.addItem(proxy);
 
 	// simple translation
    //proxy->setPos(150, 200);
    
    // transformations using a matrix	
    QTransform matrix;
    matrix.translate(150, 200)
    proxy->setTransform(matrix);
 
    QGraphicsView view(&scene);
    view.show();
 
    return app.exec();
}
*/