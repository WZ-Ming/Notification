#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QCheckBox>
#include <QComboBox>
#include <QDateTimeEdit>
#include <QDate>
#include <QWidget>
#include <QHBoxLayout>
#include <QCloseEvent>
#include <QShowEvent>
#include <QLineEdit>
#include <QMessageBox>
#include <QMenu>
#include <QDebug>
#include <QAction>
#include <QTimer>
#include <QJsonDocument>
#include <QJsonObject>
#include <QSharedPointer>
#include <QJsonArray>
#include <QFile>
#include <QSystemTrayIcon>
#include "ui_MainWindow.h"

#include "src/component/oneRowTableItem.h"

QT_BEGIN_NAMESPACE
namespace Ui
{
    class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:
    void closeEvent(QCloseEvent *event) override;
    void showEvent(QShowEvent *event) override;

private:
    void _initTableWidget();
    void _initSystemTrayIcon();
    void _updateDateTimeList();
    void _loadDataJsonFile();
    void _saveDataJsonFile();
    void _clearTableWidgetAndData();
    void _tableWidgetAddOneRow(QSharedPointer<oneTableRowItem> tableItems);
    void _showInfoWidget(int index);

    void on_addOneRow();
    void on_save();
    void on_delete();
    void on_checkTime();

private:
    Ui::MainWindow *ui;
    QTimer *m_timer = nullptr;
    QSystemTrayIcon *m_systemTrayIcon = nullptr;

    const QString m_saveDataFilePath = QApplication::applicationDirPath() + "/saveData.json";
    // const QStringList m_tableHeaderLables = {QString(), "频率", "时间", "事件"};

    QList<QSharedPointer<oneTableRowItem>> m_tableItemWidgetList;
    QList<QPair<int, QDateTime>> m_dateTimeList;
};

#endif // MAINWINDOW_H
