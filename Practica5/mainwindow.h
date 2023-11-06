#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>       //agergar escena de gráficos
#include <QGraphicsEllipseItem>
#include <QTimer>           //reloj para dar movimiento automático


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


public slots:
    void moverObjeto();             //evento por el timer


private:
    Ui::MainWindow *ui;
    QGraphicsScene *escena;
    QGraphicsEllipseItem *elipse;
    QTimer *tiempo;


};
#endif // MAINWINDOW_H
