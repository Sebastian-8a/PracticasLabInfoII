#ifndef PARTICULA_H
#define PARTICULA_H

#include <QGraphicsItem> //crear y manejar 2D
#include <QRectF> //Rectángulo que limita
#include <QPainter> //Pintar o renderizar formas
#include <QKeyEvent>

class Particle : public QGraphicsItem
{
public:
    Particle(qreal initialX, qreal initialY);       //Donde va a aparecer
    QRectF boundingRect() const;            //
    void paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget);     //me permite pintarla
    void moveLeft();
    void moveRight();
    void moveUp();
    void moveDown();

protected:
    void keyPressEvent(QKeyEvent* event); //permite a las clases derivadas que la anulen y manejen eventos de teclado de manera personalizada

private:
    qreal velocity;
    qreal minX;
    qreal maxX;
    qreal minY;
    qreal maxY;
};

#endif // PARTICULA_H
