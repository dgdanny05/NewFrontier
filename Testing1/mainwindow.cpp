#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFileDialog>
#include <QProcess>


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
    QString fileName = QFileDialog::getOpenFileName(this,
        //tr("Open File"), "", tr("Image Files (*.png *.jpg *.bmp)"));
    tr("Open File"), "", tr("Select a file *"));

    
  //  QProcess *process = new QProcess(this);
//C:\Program Files (x86)\Adobe\Acrobat Reader DC\Reader
    QString adobe = "C:/Program Files (x86)/Adobe/Acrobat Reader DC/Reader/AcroRd32.exe";
    QStringList arguments;
       arguments <<"//a page=1 "+fileName;

    QProcess process;
    process.start(adobe,arguments,QIODevice::ReadOnly);


    ui->pushButton->setText(fileName);
}
