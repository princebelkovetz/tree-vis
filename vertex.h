#ifndef VERTEX_H
#define VERTEX_H

#include <QGraphicsItem>
#include <QPainter>
#include <string>

class Vertex: public QGraphicsItem
{
public:
    Vertex();
    Vertex(int _x, int _y, int _lenX, int _lenY, int _id);
    ~Vertex();

protected:
    void paint(QPainter *painter, const QStyleOptionGraphicsItem *option, QWidget *widget = nullptr) override;
    QRectF boundingRect() const override;
private:
    int x, y, lenX, lenY, id;
};

#endif // VERTEX_H
