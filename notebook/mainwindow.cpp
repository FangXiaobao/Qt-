#include"mainwindow.h"
#include<QTextEdit>
#include<QMainWindow>
#include<QAction>
#include<QMenu>
#include<QToolBar>
#include<QStatusBar>
#include<QMenuBar>
#include<QMessageBox>
#include<QFileDialog>
#include<QtGui>

//mainwindow构造函数
MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
    setWindowTitle(tr("方小宝的专属NoteBook"));
    //打开动作
    openAction = new QAction(QIcon(":/images/open-file.png"),tr("打开"),this);
    openAction->setShortcut(QKeySequence::Open);
    openAction->setStatusTip(tr("点击打开文件"));

    //保存动作
    saveAction = new QAction(QIcon(":/images/spellchecker.png"),tr("保存"),this);
    saveAction->setShortcut(QKeySequence::Save);
    saveAction->setStatusTip(tr("点击保存文件"));
    //关闭动作
    closeAction = new QAction(QIcon(":/images/delete-file.png"),tr("关闭"),this);
    closeAction->setStatusTip(tr("点击关闭记事本"));

    //关于工作
    aboutAction = new QAction(QIcon(":/images/email-info.png"),tr("关于"),this);
    aboutAction->setStatusTip(tr("显示作者信息"));

    //创建菜单栏
    QMenu *open = menuBar()->addMenu(tr("打开"));
    open->addAction(openAction);

    QMenu *save = menuBar()->addMenu(tr("保存"));
    save->addAction(saveAction);

    QMenu *about = menuBar()->addMenu(tr("关于"));
    about->addAction(aboutAction);


    //创建工具栏
    QToolBar *toolBar = addToolBar(tr("工具栏"));
    toolBar->addAction(openAction);
    toolBar->addAction(saveAction);
    toolBar->addAction(aboutAction);
    toolBar->addAction(closeAction);

    //状态栏
    QStatusBar *statusBar = new QStatusBar;
    setStatusBar(statusBar);

    //添加文本框
    textEdit = new QTextEdit(this);
    setCentralWidget(textEdit);



    connect(openAction,SIGNAL(triggered()),
                     this,SLOT(openFile()));
    connect(saveAction,SIGNAL(triggered()),
                     this,SLOT(saveFile()));
    connect(aboutAction,SIGNAL(triggered()),
                     this,SLOT(aboutAuthor()));
    connect(closeAction,SIGNAL(triggered()),
                     this,SLOT(quit()));
}



MainWindow::~MainWindow()
{

}

void MainWindow::openFile()
{
    QString path = QFileDialog::getOpenFileName(this,
                                                    tr("打开文件"),
                                                    ".",
                                                    tr("Text Files(*.txt)"));
        if(!path.isEmpty()) {
            QFile file(path);
            if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                QMessageBox::warning(this, tr("Read File"),
                                     tr("无法打开文件:\n%1").arg(path));
                return;
            }
            QTextStream in(&file);
            textEdit->setText(in.readAll());
            file.close();
        } else {
            QMessageBox::warning(this, tr("Path"),
                                 tr("请选择一个文件."));
        }

}

void MainWindow::saveFile()
{
    QString path = QFileDialog::getSaveFileName(this,
                                                    tr("保存文件"),
                                                    ".",
                                                    tr("Text Files(*.txt)"));
        if(!path.isEmpty()) {
            QFile file(path);
            if (!file.open(QIODevice::WriteOnly | QIODevice::Text)) {
                QMessageBox::warning(this, tr("Write File"),
                                           tr("无法保存文件:\n%1").arg(path));
                return;
            }
            QTextStream out(&file);
            out << textEdit->toPlainText();
            file.close();
        } else {
            QMessageBox::warning(this, tr("Path"),
                                 tr("你没有保存文件."));
        }

}

void MainWindow::aboutAuthor()
{
    QMessageBox::information(this,tr("关于作者"),tr("中国计量学院"
                                                "信息学院<br>方浩然"));

}




















