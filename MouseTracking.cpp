#include<QApplication>
#include<QLabel>
#include<QEvent>
#include<QMouseEvent>
class EventLabel : public QLabel
{
public:
    void mouseMoveEvent(QMouseEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void mouseReleaseEvent(QMouseEvent *event);
};


void EventLabel::mouseMoveEvent(QMouseEvent *event)
{
    QString msg;
    msg.sprintf("<center><h>Move:%d,%d</h></center>",
                event->x(),event->y());

    this->setText(msg);
}

void EventLabel::mousePressEvent(QMouseEvent *event)
{
    QString msg;
    msg.sprintf("<center><h>Press:%d,%d</h></center>",
                event->x(),event->y());
    this->setText(msg);
}

void EventLabel::mouseReleaseEvent(QMouseEvent *event)
{
    QString msg;
    msg.sprintf("<center><h>Release:%d,%d</h></center>",
                event->x(),event->y());

    this->setText(msg);
}



int main(int argc,char* argv[])
{
    QApplication app(argc,argv);
    EventLabel *label = new EventLabel;
    label->resize(300,300);
    label->setWindowTitle("鼠标跟踪");

    label->show();
label->setMouseTracking(true);
    return app.exec();
}












