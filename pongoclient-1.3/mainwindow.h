#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QProcess>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

private slots:
    void on_pushButton_clicked();

    void on_actionUpload_triggered();

    void on_actionLoad_triggered();

    void on_lineEdit_returnPressed();

    void on_actionLoad_Boot_triggered();

    void on_actionCheckra1n_triggered();

private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
