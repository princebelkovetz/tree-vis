#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QGraphicsScene>
#include <QDebug>
#include <Vertex.h>
#include <Tree.h>
#include <cmath>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_keyAdderButton_clicked();

    void on_pushButton_2_clicked();

    void on_horizontalSlider_sliderMoved(int position);

private:
    Ui::MainWindow *ui;
    QGraphicsScene *scene;
    Tree *dekartTree;
    int lastIndex;
    long double curScale;
};
#endif // MAINWINDOW_H
