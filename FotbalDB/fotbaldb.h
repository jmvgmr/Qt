#ifndef FOTBALDB_H
#define FOTBALDB_H

#include <QMainWindow>
#include <QtSql>
#include <QSqlTableModel>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QSqlRecord>
#include <QPixmap>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class FotbalDB; }
QT_END_NAMESPACE

class FotbalDB : public QMainWindow
{
    Q_OBJECT

public:
    FotbalDB(QWidget *parent = nullptr);
    ~FotbalDB();

private slots:
    void on_pushButtonZobrazitHrac_clicked();

    void on_pushButtonZobrazitKlub_clicked();

    void on_pushButtonZobrazitVyhledavani_clicked();

    void on_pushButtonPridat_clicked();

    void on_pushButtonEditovat_clicked();

    void on_pushButtonSmazat_clicked();

    void blank();

    QStringList hledatHraci();

    QStringList hledatKluby();

private:
    Ui::FotbalDB *ui;

    QSqlDatabase db;
    QSqlQueryModel *model = new QSqlQueryModel();
};
#endif // FOTBALDB_H
