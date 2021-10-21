#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtWebEngineWidgets/QtWebEngineWidgets>
#include <QDebug>
#include <QFile>
QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void loadUrl();
private slots:


    void on_forward_But_clicked();

    void on_back_But_clicked();

    void on_go_But_clicked();

    void on_lineEdit_returnPressed();
    void startLoading();
    void loading(int progress);
    void loaded();
    void on_refresh_But_clicked();

    void on_home_But_clicked();

private:
    Ui::MainWindow *ui;
    QWebEngineView *webview;
};
#endif // MAINWINDOW_H
