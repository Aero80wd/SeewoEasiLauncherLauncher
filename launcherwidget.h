#ifndef LAUNCHERWIDGET_H
#define LAUNCHERWIDGET_H
#include<QProcess>
#include <QWidget>
#include <QPropertyAnimation>
#include<QShowEvent>
#include<QFont>
#include<QFontDatabase>
#include<QDir>
#include<windows.h>
#include<QJsonDocument>
#include<QJsonObject>
#include<QMessageBox>
#include<QTimer>
#include<QTextCodec>
#include<QCoreApplication>
using namespace std;
QT_BEGIN_NAMESPACE
namespace Ui {
class LauncherWidget;
}
QT_END_NAMESPACE

class LauncherWidget : public QWidget
{
    Q_OBJECT

public:
    LauncherWidget(QWidget *parent = nullptr);
    ~LauncherWidget();
    void showAni();
    void readConfigFile();
    QJsonObject configs;
    QString CONFIG_FILE = QCoreApplication::applicationDirPath() + "/config.json";
    QString SWENLAUNCHER_EXEC;

    void startseewo(QString file_path = "");

    QPropertyAnimation* back_show;

private:
    Ui::LauncherWidget *ui;
};
#endif // LAUNCHERWIDGET_H
