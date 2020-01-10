#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    int a;
    int b;

private slots:

    void on_main_btn_clicked();

    void on_lineEdit_editingFinished();

    void on_lineEdit_2_editingFinished();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
