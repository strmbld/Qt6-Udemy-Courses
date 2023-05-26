#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

class MainWindow : public QMainWindow
{
    Q_OBJECT

private:
    QSize sizeHint() const override;
    QAction* quitAction;

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

signals:

};

#endif // MAINWINDOW_H
