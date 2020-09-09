#ifndef CBRASHAPTIQUE_H
#define CBRASHAPTIQUE_H

#include <QGraphicsScene>
#include <QGraphicsView>
#include <QDesktopWidget>
#include <QApplication>
#include <QDebug>
#include <QMouseEvent>
#include <QtWidgets>
#include <QPoint>
#include "cgrip.h"

class CBrasHaptique : public QGraphicsView
{
    Q_OBJECT
    private:
        QGraphicsScene *scene1;
        //Largeur de l'écran
        int SSW;
        //Hauteur de l'écran
        int SSH;
        //Un bras est composé d'un grip
        CGrip *grip;
        double gripDiameter;
        QPoint offset;
        QPoint posGrip;
    public:
        CBrasHaptique();
        virtual ~CBrasHaptique();
        virtual void mousePressEvent(QMouseEvent * event);
        virtual void mouseReleaseEvent(QMouseEvent *event);
        virtual void mouseMoveEvent(QMouseEvent *event);

    signals:
        //Permet de récupérer la position du grip lors 
        //du déplacement de la souris
        void posGripChanged(QPoint p_posGrip);
        //Permet de récupérer la position du grip 
        //au relâchement du bouton gauche de la souris
        void posInit(QPoint p_posGrip);
};

#endif // CBRASHAPTIQUE_H
