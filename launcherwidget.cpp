#include "launcherwidget.h"
#include "ui_launcherwidget.h"
#include <iostream>
LauncherWidget::LauncherWidget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::LauncherWidget)
{
    ui->setupUi(this);
    back_show = new QPropertyAnimation(ui->background,"geometry");
    back_show->setStartValue(QRect(ui->background->pos().x()-ui->background->width()/2,ui->background->pos().y()-ui->background->height()/2,ui->background->width()*2,ui->background->height()*2));
    back_show->setEndValue(QRect(ui->background->pos().x(),ui->background->pos().y(),ui->background->width(),ui->background->height()));
    back_show->setEasingCurve(QEasingCurve::InOutSine);
    back_show->setDuration(700);
    int fontId = QFontDatabase::addApplicationFont(":/fonts/title.ttf");
    QString fontName = QFontDatabase::applicationFontFamilies(fontId).at(0);
    QFont font(fontName, 72);
    ui->title->setFont(font);
    int fontId2 = QFontDatabase::addApplicationFont(":/fonts/yuanshen.ttf");
    QString fontName2 = QFontDatabase::applicationFontFamilies(fontId2).at(0);
    QFont font2(fontName2, 12);
    ui->label_2->setFont(font2);
    int fontId3 = QFontDatabase::addApplicationFont(":/fonts/yuanshen.ttf");
    QString fontName3 = QFontDatabase::applicationFontFamilies(fontId3).at(0);
    QFont font3(fontName3, 16);
    ui->label_3->setFont(font3);
    ui->title->hide();
    ui->label->hide();
    ui->label->setTime(1000);
    ui->label_2->hide();
    ui->label_2->setTime(1300);
    ui->label_3->hide();
    setWindowFlags(Qt::FramelessWindowHint | Qt::WindowStaysOnTopHint);    //隐藏标题栏（无边框）
    setAttribute(Qt::WA_StyledBackground);      //启用样式背景绘制
    setAttribute(Qt::WA_TranslucentBackground); //背景透明
    readConfigFile();
}

LauncherWidget::~LauncherWidget()
{
    delete ui;
}
void LauncherWidget::showAni(){
    back_show->setDirection(QAbstractAnimation::Forward);
    back_show->start();
    ui->title->Anishow();
    ui->label->Anishow();
    ui->label_2->Anishow();
    ui->label_3->Anishow();

}
void LauncherWidget::readConfigFile(){
    QFile file(CONFIG_FILE);
    file.open(QIODevice::ReadOnly | QIODevice::Text);
    QString value = file.readAll();
    file.close();

    QJsonParseError parseJsonErr;
    QJsonDocument document = QJsonDocument::fromJson(value.toUtf8(), &parseJsonErr);
    if (! (parseJsonErr.error == QJsonParseError::NoError)) {
        QFile file2(CONFIG_FILE);
        file2.open(QIODevice::WriteOnly | QIODevice::Text);
        QJsonObject temp;
        temp.insert("title","希沃白板");
        temp.insert("cap","Launcher By Aero8m\n抵制不良作风，拒绝摆烂心态，注意自我保护，谨防受骗上当，适度教学益脑，拖堂教学伤身，合理安排时间，享受快乐学习。\nCopyright © 2011-2024 Guangzhou Shirui. All Rights Reserved");
        temp.insert("exec","C:\\Program Files (x86)\\Seewo\\EasiNote5\\swenlauncher\\backup\\swenlauncher.exe");
        temp.insert("background","");
        QJsonDocument temp_doc;
        temp_doc.setObject(temp);
        file2.write(temp_doc.toJson());
        file2.close();
        QFile file(CONFIG_FILE);
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        QString value = file.readAll();
        file.close();

        QJsonParseError parseJsonErr;
        QJsonDocument document = QJsonDocument::fromJson(value.toUtf8(), &parseJsonErr);
    }
    configs = document.object();
    ui->title->setText(configs.value("title").toString());
    ui->label_2->setText(configs.value("cap").toString());
    SWENLAUNCHER_EXEC = configs.value("exec").toString();
    qDebug() << "border-image: url(\"" + configs.value("background").toString() + "\");";
    ui->background->setStyleSheet("border-image: url(\"" + configs.value("background").toString() + "\");");
}
void LauncherWidget::startseewo(QString file_path){
    QEventLoop loop;//定义一个新的事件循环
    QTimer::singleShot(5000, &loop, SLOT(quit()));//创建单次定时器，槽函数为事件循环的退出函数
    loop.exec();//事件循环开始执行，程序会卡在这里，直到定时时间到，本循环被退出
    QString start_command =  SWENLAUNCHER_EXEC;
    if (start_command == ""){
        delete this;
    }
    if (file_path != ""){
        start_command = "\"\"" + start_command + "\" \"" + file_path + "\"\"";
    }else{
        start_command = "\"" + start_command + "\" -m Display -iwb";
    }
    qDebug() << start_command;
    // const char* str= start_command.toStdString().c_str();
    qDebug() << start_command.toStdWString().c_str();
    _wsystem(start_command.toStdWString().c_str());
    delete this;
    qApp->exit();
}
