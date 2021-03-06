#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    scene = new QGraphicsScene();
    ui->graphicsView->setScene(scene);

    dekartTree = new Tree();

    lastIndex = 0;

    ui->horizontalSlider->setSliderPosition(50);

    curScale = 1.0;
}

MainWindow::~MainWindow()
{
    delete ui;
    delete dekartTree;
}


void draw(Node* cur, int x, int y, QGraphicsScene* scene){
    if (cur == nullptr)
        return;

    if (cur->leftSon != nullptr) {
        int w = cur->leftSon->wRight + 1;
        scene->addLine(x, y, x - 50 * w, y + 75);
        draw(cur->leftSon, x - 50 * w, y + 75, scene);
    }
    if (cur->rightSon != nullptr) {
        int w = cur->rightSon->wLeft + 1;
        scene->addLine(x, y, x + 50 * w, y + 75);
        draw(cur->rightSon, x + 50 * w, y + 75, scene);
    }

    Vertex *v = new Vertex(x - 25, y - 25, 50, 50, cur->key);
    scene->addItem(v);
}



void MainWindow::on_keyAdderButton_clicked()
{
    lastIndex++;
    dekartTree->add(lastIndex);
    dekartTree->recalc();
    scene->clear();
    draw(dekartTree->root, 500, 100, scene);
    qDebug() << lastIndex << '\n';
}


void MainWindow::on_pushButton_2_clicked()
{
    ui->graphicsView->scale(0.75, 0.75);
}


void MainWindow::on_horizontalSlider_sliderMoved(int position)
{
    long double dScale = pow(0.95, 50 - position) / curScale;
    ui->graphicsView->scale(dScale, dScale);
    curScale *= dScale;
}

