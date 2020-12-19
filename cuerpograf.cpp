#include "cuerpograf.h"

cuerpograf::cuerpograf(float x, float y, float vx, float vy, float m, float r):escala(0.05)
{
    esf = new cuerpo(x,y,vx,vy,m,r);
}

QRectF cuerpograf::boundingRect() const
{
    return QRectF(-1*escala*esf->getR(),-1*escala*esf->getR(),2*escala*esf->getR(),2*escala*esf->getR());
}

void cuerpograf::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    painter->setBrush(Qt::yellow);
    painter->drawEllipse(boundingRect());
}

void cuerpograf::setEscala(float s)
{
    escala = s;
}

void cuerpograf::actualizar(float dt)
{
    esf->actualizar(dt);
    setPos(esf->getPX()*escala+500,esf->getPY()*escala*-1+300);
}

void cuerpograf::guardar_datos(string datos, string nombre)
{
    fstream k("../lab_6/doc/Space.txt",fstream::out); // Se crea el archivo o se abre en modo escritura
    k << datos;
    k.close();
}

cuerpo *cuerpograf::getEsf()
{
    return esf;
}
