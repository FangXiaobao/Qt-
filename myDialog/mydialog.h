#ifndef MYDIALOG_H
#define MYDIALOG_H
#include<QDialog>
class QLabel;
class QPushButton;
class QLineEdit;
class QCheckBox;

class MyDialog : public QDialog
{
    Q_OBJECT;

public:
    MyDialog(QWidget *parent = 0);
     ~MyDialog();


signals:
    void findNext(const QString &str,Qt::CaseSensitivity);
    void findPrevious(const QString &str,Qt::CaseSensitivity);

private slots:
    void findClicked();
    void enableFindButton(const QString &text);

private:
    QLabel *label;
    QPushButton *findButton;
    QPushButton *closeButton;
    QLineEdit *lineEdit;
    QCheckBox *caseCheckBox;
    QCheckBox *backwordCheckBox;

};
#endif
