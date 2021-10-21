#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    webview = new QWebEngineView;
    ui->horizontalLayout_2->addWidget(webview);


    connect(webview, SIGNAL(loadStarted()),
            SLOT(startLoading()));
    connect(webview, SIGNAL(loadProgress(int)),
            SLOT(loading(int)));
    connect(webview, SIGNAL(loadFinished(bool)),
            SLOT(loaded(bool)));

    QUrl url = QUrl("google.com");
    url.setScheme("http");
    webview->page()->load(url);

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::loadUrl()
{
    QUrl url = QUrl(ui->lineEdit->text());
    url.setScheme("http");
    webview->page()->load(url);
}


void MainWindow::on_forward_But_clicked()
{
    webview->forward();
}


void MainWindow::on_back_But_clicked()
{
    webview->back();
}


void MainWindow::on_go_But_clicked()
{
    loadUrl();
}


void MainWindow::on_lineEdit_returnPressed()
{
    loadUrl();
}

void MainWindow::startLoading()
{
    ui->progressBar->show();

}

void MainWindow::loading(int progress)
{
    ui->progressBar->setValue(progress);
}

void MainWindow::loaded()
{
    ui->progressBar->hide();
}

void MainWindow::on_refresh_But_clicked()
{
   if(ui->progressBar->value()==100)
   {
       webview->reload();
   }
   else
   {
       webview->stop();
   }
}


void MainWindow::on_home_But_clicked()
{
    QUrl url = QUrl("google.com");
    url.setScheme("http");
    webview->page()->load(url);

}

