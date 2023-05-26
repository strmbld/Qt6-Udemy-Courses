#include <QPushButton>
#include <QAction>
#include <QApplication>
#include <QMenuBar>
#include <QStatusBar>

#include "mainwindow.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow{parent}
{
    QPushButton* button = new QPushButton("Hello", this);
    setCentralWidget(button);

    quitAction = new QAction("Quit"); // release memory
    connect(quitAction, &QAction::triggered, [&](){ QApplication::quit(); });

    QMenu* fileMenu = menuBar()->addMenu("File");
    fileMenu->addAction(quitAction);
    menuBar()->addMenu("Edit");
    menuBar()->addMenu("Window");
    menuBar()->addMenu("Settings");
    menuBar()->addMenu("Help");

    statusBar()->showMessage("Uploading file ...", 3000);
}

MainWindow::~MainWindow()
{
    delete quitAction;
}


QSize MainWindow::sizeHint() const
{
    return QSize(800, 500);
}
