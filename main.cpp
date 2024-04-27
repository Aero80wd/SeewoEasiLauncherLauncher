#include "launcherwidget.h"
#pragma execution_character_set("gbk")
#include <QApplication>
int main(int argc, char *argv[])
{

    qDebug() << argc;
    QApplication a(argc, argv);
    QTextCodec::setCodecForLocale(QTextCodec::codecForName("UTF-8"));

    LauncherWidget w;
    QScreen *scr = a.primaryScreen();
    int scr_w = scr->size().width();
    int scr_h = scr->size().height();
    w.move((scr_w - w.width()) / 2, (scr_h - w.height()) / 2);
    w.show();

    w.showAni();
    if (argc == 2){
        QString filePath = QString::fromLocal8Bit(argv[1]);
        w.startseewo(filePath);
    }else{
        w.startseewo();
    }

    return a.exec();
}
