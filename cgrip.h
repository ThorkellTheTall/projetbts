#ifndef CGRIP_H
#define CGRIP_H
#include <QGraphicsEllipseItem>
#include <QBrush>
#include <QDebug>
#include <QPainter>
#include <QGraphicsSceneDragDropEvent>
#include <QMimeData>

class CGrip : public QGraphicsObject
{
    Q_OBJECT
    Q_PROPERTY(QPointF position READ pos WRITE setPos)
    private:
        double m_diameter;
        double m_posX;
        double m_posY;
        double m_fX;
        double m_fY;
        QRgb m_color;
        bool dragOver;
    public:
        CGrip();
        CGrip(double p_diameter,double p_posX,double p_posY);
        ~CGrip();
        void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr);
        double getPosX();
        double getPosY();
        QRectF boundingRect() const;
};

#endif // CGRIP_H
