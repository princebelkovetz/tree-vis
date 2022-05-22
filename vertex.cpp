#include "Vertex.h"

Vertex::Vertex(): QGraphicsItem()
{

}

Vertex::Vertex(int _x, int _y, int _lenX, int _lenY, int _id): QGraphicsItem()
{
    x = _x;
    y = _y;
    lenX = _lenX;
    lenY = _lenY;
    id = _id;
}

Vertex::~Vertex()
{

}

void Vertex::paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget)
{
    QPen pen = QPen();
    pen.setColor(Qt::black);
    pen.setWidth(2);
    painter->setPen(pen);

    QBrush brush = QBrush();
    brush.setStyle(Qt::SolidPattern);
    brush.setColor(Qt::white);
    painter->setBrush(brush);

    QFont font = QFont("gotham", 15);
    painter->setFont(font);

    painter->drawEllipse(x, y, lenX, lenY);
    painter->drawText(QRect(x, y, lenX, lenY), Qt::AlignCenter, std::to_string(id).c_str());
}

QRectF Vertex::boundingRect() const
{
    return QRect(x, y, lenX, lenY);
}
