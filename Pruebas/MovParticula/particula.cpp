#include "particula.h"

#include "qgraphicsscene.h"
#include <QKeyEvent>
#include <QDebug>
#include <QGraphicsPixmapItem>      //incluir imágenes o archivos
#include <QPixmap>




Particle::Particle(qreal initialX, qreal initialY) : velocity(10.0),minX(0), maxX(800), minY(0), maxY(600)
{
    setPos(initialX, initialY);         //En que posición va a estar
    setFlag(ItemIsFocusable);           //puede recibir inputs de teclado
}

QRectF Particle::boundingRect() const
{
    return QRectF(0, 0, 800, 800); // Ajusta límites visuales
}

void Particle::paint(QPainter* painter, const QStyleOptionGraphicsItem* option, QWidget* widget)
{
    painter->setBrush(Qt::blue);
    painter->drawEllipse(10, 10, 20, 20); // Tamaño y ub de la elipse
}

void Particle::moveLeft()
{
    setPos(x() - velocity, y());
}

void Particle::moveRight()
{
    setPos(x() + velocity, y());
}

void Particle::moveUp()
{
    setPos(x(), y() - velocity);
}

void Particle::moveDown()
{
    setPos(x(), y() + velocity);
}

void Particle::keyPressEvent(QKeyEvent* event)
{


    //qreal newX = x();
    //qreal newY = y();
    switch (event->key())
    {
    case Qt::Key_A:
        qDebug() << "Tecla: " << event->key();
        moveLeft();
        break;
    case Qt::Key_D:
        moveRight();
        qDebug() << "Tecla: " << event->key();
        break;
    case Qt::Key_W:
        moveUp();
        qDebug() << "Tecla: " << event->key();
        break;
    case Qt::Key_S:
        moveDown();
        qDebug() << "Tecla: " << event->key();
        break;
    default:
        break;
    }
    /*if (newX >= minX && newX <= maxX && newY >= minY && newY <= maxY){
        setPos(newX, newY);
        qDebug() << "Current position: " << x() << ", " << y();
        qDebug() << "Boundaries: minX=" << minX << " maxX=" << maxX << " minY=" << minY << " maxY=" << maxY;

    }*/


    scene()->update();          //Actualizar el cambio

}
