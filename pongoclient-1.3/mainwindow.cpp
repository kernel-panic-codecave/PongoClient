#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QProcess>
#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_pushButton_clicked()
{
    QString Command = ui->lineEdit->text();
    QString path = "/usr/lib/PongoClient";
    QString command("python");
    QStringList params = {"issue_cmd.py", Command};

    QProcess *process = new QProcess();
    process->startDetached(command, params, path);
    process->waitForFinished();
    process->close();
    if(process->Crashed)
    {
        QMessageBox::critical(
          this,
          tr("Issue command"),
          tr("There was an error. Check the terminal"));
    }
    ui->lineEdit->setText("");
}

void MainWindow::on_actionUpload_triggered()
{
    QString file_upload = QFileDialog::getOpenFileName(this, "Choose File To Upload To Device", "//");
    QString path = "/usr/lib/PongoClient";
    QString command("python");
    QStringList params = {"upload_data.py", file_upload};

    QProcess *process = new QProcess();
    process->startDetached(command, params, path);
    process->waitForFinished();
    process->close();
    if(process->Crashed)
    {
        QMessageBox::critical(
          this,
          tr("Upload data"),
          tr("There was an error. Check the terminal"));
    }
}

void MainWindow::on_actionLoad_triggered()
{
    QString module_load = QFileDialog::getOpenFileName(this, "Choose Module To Upload To Device", "//");
    QString path = "/usr/lib/PongoClient";
    QString command("python");
    QStringList params = {"module_load.py", module_load};

    QProcess *process = new QProcess();
    process->startDetached(command, params, path);
    process->waitForFinished();
    process->close();
    if(process->Crashed)
    {
        QMessageBox::critical(
          this,
          tr("Load module"),
          tr("There was an error. Check the terminal"));
    }
}

void MainWindow::on_lineEdit_returnPressed()
{
    MainWindow::on_pushButton_clicked();
}

void MainWindow::on_actionLoad_Boot_triggered()
{
    QString module_load_boot = QFileDialog::getOpenFileName(this, "Choose Module To Upload To Device", "//");
    QString path = "/usr/lib/PongoClient";
    QString command("python");
    QStringList params = {"module_load_boot.py", module_load_boot};

    QProcess *process = new QProcess();
    process->startDetached(command, params, path);
    process->waitForFinished();
    process->close();
    if(process->Crashed)
    {
        QMessageBox::critical(
          this,
          tr("Load module and boot"),
          tr("There was an error. Check the terminal"));
    }
}

void MainWindow::on_actionCheckra1n_triggered()
{
    QString path = "/usr/lib/PongoClient";
    QString command("checkra1n");
    QStringList params = {"-p", "-g"};

    QProcess *process = new QProcess();
    process->startDetached(command, params, path);
    process->waitForFinished();
    process->close();
    if(process->Crashed)
    {
        QMessageBox::critical(
          this,
          tr("Checkra1n"),
          tr("There was an error. Check the terminal"));
    }
}
