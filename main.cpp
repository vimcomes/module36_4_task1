#include <QApplication>
#include <QSlider>
#include <QVBoxLayout>
#include <QPainter>
#include <QPaintEvent>
#include <iostream>

class ImageCircle : public QWidget
{
private:
    QPixmap turquoiseCircle;
    QPixmap greenCircle;
    QPixmap yellowCircle;
    QPixmap redCircle;
    QPixmap currentCircle;
public:
    explicit ImageCircle(QWidget *parent)
    {
        setParent(parent);
        //my wife asked me to add a turquoise color ;)
        turquoiseCircle = QPixmap("..\\turquoise.png");
        greenCircle = QPixmap("..\\green.png");
        yellowCircle = QPixmap("..\\yellow.png");
        redCircle = QPixmap("..\\red.png");
        currentCircle = turquoiseCircle;
    }

    void paintEvent(QPaintEvent *e) override
    {
        QPainter p(this);
        p.drawPixmap(e->rect(), currentCircle);
    }

    void setTurquoise()
    {
        currentCircle = turquoiseCircle;
        update();
    }

    void setGreen()
    {
        currentCircle = greenCircle;
        update();
    }

    void setYellow()
    {
        currentCircle = yellowCircle;
        update();
    }
    void setRed()
    {
        currentCircle = redCircle;
        update();
    }
};

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    auto window = new QWidget;
    window->setFixedSize(225,245);
    auto slider = new QSlider(Qt::Horizontal);
    slider->move(1000,500);
    slider->setMinimum(0);
    slider->setMaximum(99);
    auto circle = new ImageCircle(nullptr);
    auto layout = new QVBoxLayout(window);
    layout->addWidget(slider);
    layout->addWidget(circle);
    QObject::connect(slider, &QSlider::valueChanged, [slider, circle]()
    {
        if(slider->value() >= 0 && slider->value() <= 24)
        {
            circle->setTurquoise();
        } else if (slider->value() >= 25 && slider->value() <= 49) {
            circle -> setGreen();
        } else if (slider->value() >= 50 && slider->value() <= 74) {
            circle->setYellow();
        } else {
            circle->setRed();
        }
    });
    window->show();
    return QApplication::exec();
}
//#include <main.moc>