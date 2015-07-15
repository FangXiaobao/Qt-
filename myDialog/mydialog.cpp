#include<QtGui>
#include<QLabel>
#include<QLineEdit>
#include<QHBoxLayout>
#include<QVBoxLayout>

#include"mydialog.h"
#include<QCheckBox>
#include<QPushButton>

MyDialog::MyDialog(QWidget *parent) :QDialog(parent)
{
    this->label = new QLabel(tr("想要查什么？"));
    this->lineEdit = new QLineEdit;
    label->setBuddy(lineEdit);

    this->caseCheckBox = new QCheckBox(tr("大小写敏感"));
    this->backwordCheckBox = new QCheckBox(tr("向后查找"));

    this->findButton = new QPushButton(tr("点击查找"));
    findButton->setDefault(true);
    findButton->setEnabled(false);

    this->closeButton = new QPushButton(tr("点击关闭"));

    connect(lineEdit,SIGNAL(textChanged(const QString&)),
            this,SLOT(enableFindButton(const QString &)));
    connect(findButton,SIGNAL(clicked()),
            this,SLOT(findClicked()));
    connect(closeButton,SIGNAL(clicked()),
            this,SLOT(close()));

    QHBoxLayout *topLeftLayout = new QHBoxLayout;
    topLeftLayout->addWidget(label);
    topLeftLayout->addWidget(lineEdit);

    QVBoxLayout *leftLayout = new QVBoxLayout;
    leftLayout->addLayout(topLeftLayout);
    leftLayout->addWidget(caseCheckBox);
    leftLayout->addWidget(backwordCheckBox);

    QVBoxLayout *rightLayout = new QVBoxLayout;
    rightLayout->addWidget(findButton);
    rightLayout->addWidget(closeButton);
    rightLayout->addStretch();

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addLayout(leftLayout);
    mainLayout->addLayout(rightLayout);

    setLayout(mainLayout);
    setWindowTitle(tr("查找对话框"));
    setFixedHeight(sizeHint().height());
}

MyDialog::~MyDialog()
{

}

void MyDialog::findClicked()
{
    QString string = lineEdit->text();
    Qt::CaseSensitivity cs = caseCheckBox->isChecked()?
                Qt::CaseSensitive:Qt::CaseInsensitive;
    if(backwordCheckBox->isChecked())
    {
        findNext(string,cs);

    }
    else
    {
        findPrevious(string,cs);
    }

}

void MyDialog::enableFindButton(const QString &text)
{
    findButton->setEnabled(!text.isEmpty());

}


























