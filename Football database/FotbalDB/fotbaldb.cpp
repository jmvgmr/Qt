#include "fotbaldb.h"
#include "ui_fotbaldb.h"

FotbalDB::FotbalDB(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::FotbalDB)
{
    ui->setupUi(this);

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName("../hraciDB.db");

    if(db.open())
        qDebug() << "Database byla pripojena.";
    else
        qDebug() << "Database nebyla nalezena.";

    QStringList list = db.tables();

    ui->comboBoxHrac->clear();
    ui->comboBoxHrac->addItem("");
    ui->comboBoxHrac->addItems(hledatHraci());

    ui->comboBoxKlub->clear();
    ui->comboBoxKlub->addItem("");
    ui->comboBoxKlub->addItems(hledatKluby());

    ui->comboBoxKriteria->clear();
    ui->comboBoxKriteria->addItem("");
    QStringList kriteria = {"Věk", "Goly", "Asistence", "Žluté karty", "Červené karty"};
    ui->comboBoxKriteria->addItems(kriteria);

    ui->comboBoxEditHrac->clear();
    ui->comboBoxEditHrac->addItem("");
    ui->comboBoxEditHrac->addItems(hledatHraci());
/*
    ui->comboBoxSmazatHrac->clear();
    ui->comboBoxSmazatHrac->addItem("");
    ui->comboBoxSmazatHrac->addItems(hledatHraci());

    ui->comboBoxCoEditovat->clear();
    ui->comboBoxCoEditovat->addItem("");
    QStringList co_editovat = {"Jméno", "Klub", "Národnost", "Pozice", "Věk", "Goly", "Asistence", "Žluté karty", "Červené karty"};
    ui->comboBoxCoEditovat->addItems(co_editovat);
    */
    blank();
}

FotbalDB::~FotbalDB()
{
    delete ui;
}

void FotbalDB::blank(){
    ui->comboBoxHrac->clear();
    ui->comboBoxHrac->addItem("");
    ui->comboBoxHrac->addItems(hledatHraci());

    ui->comboBoxKlub->clear();
    ui->comboBoxKlub->addItem("");
    ui->comboBoxKlub->addItems(hledatKluby());

    ui->comboBoxKriteria->clear();
    ui->comboBoxKriteria->addItem("");
    QStringList kriteria = {"Věk", "Goly", "Asistence", "Žluté karty", "Červené karty"};
    ui->comboBoxKriteria->addItems(kriteria);

    ui->comboBoxEditHrac->clear();
    ui->comboBoxEditHrac->addItem("");
    ui->comboBoxEditHrac->addItems(hledatHraci());

    ui->comboBoxSmazatHrac->clear();
    ui->comboBoxSmazatHrac->addItem("");
    ui->comboBoxSmazatHrac->addItems(hledatHraci());

    ui->comboBoxCoEditovat->clear();
    ui->comboBoxCoEditovat->addItem("");
    QStringList co_editovat = {"Jméno", "Klub", "Národnost", "Pozice", "Věk", "Goly", "Asistence", "Žluté karty", "Červené karty"};
    ui->comboBoxCoEditovat->addItems(co_editovat);

    ui->textBrowserHrac->clear();
    ui->textBrowserKlub->clear();
    ui->textBrowserVyhledavani->clear();
}

QStringList FotbalDB::hledatHraci()
{
    QSqlQuery *zobrazit_hraci = new QSqlQuery;
    QString prikaz = "SELECT Jméno FROM hraci ORDER BY Jméno";
    zobrazit_hraci->prepare(prikaz);
    zobrazit_hraci->exec();
    QStringList hraci;
    while (zobrazit_hraci->next()) {
        QString hrac = zobrazit_hraci->value(0).toString();
        hraci.append(hrac);
    }
    return hraci;
}

QStringList FotbalDB::hledatKluby()
{
    QSqlQuery *zobrazit_kluby = new QSqlQuery;
    QString prikaz = "SELECT Klub FROM hraci ORDER BY Klub";
    zobrazit_kluby->prepare(prikaz);
    zobrazit_kluby->exec();
    QStringList kluby;
    while (zobrazit_kluby->next()) {
        QString klub = zobrazit_kluby->value(0).toString();
        kluby.append(klub);
    }
    kluby.removeDuplicates();
    return kluby;
}

void FotbalDB::on_pushButtonZobrazitHrac_clicked()
{
    ui->textBrowserHrac->clear();
    QSqlQuery *hledat = new QSqlQuery;

    QString hrac_hledan = ui->comboBoxHrac->currentText();

    QString prikaz_0 = "SELECT id FROM hraci WHERE Jméno = '" + hrac_hledan + "'";
    QString prikaz_1 = "SELECT Jméno FROM hraci WHERE Jméno = '" + hrac_hledan + "'";
    QString prikaz_2 = "SELECT Klub FROM hraci WHERE Jméno = '" + hrac_hledan + "'";
    QString prikaz_3 = "SELECT Národnost FROM hraci WHERE Jméno = '" + hrac_hledan + "'";
    QString prikaz_4 = "SELECT Věk FROM hraci WHERE Jméno = '" + hrac_hledan + "'";
    QString prikaz_5 = "SELECT Pozice FROM hraci WHERE Jméno = '" + hrac_hledan + "'";
    QString prikaz_6 = "SELECT Goly FROM hraci WHERE Jméno = '" + hrac_hledan + "'";
    QString prikaz_7 = "SELECT Asistence FROM hraci WHERE Jméno = '" + hrac_hledan + "'";
    QString prikaz_8 = "SELECT Žlutékarty FROM hraci WHERE Jméno = '" + hrac_hledan + "'";
    QString prikaz_9 = "SELECT Červenékarty FROM hraci WHERE Jméno = '" + hrac_hledan + "'";

    hledat->prepare(prikaz_0);
    hledat->exec();
    hledat->first();
    QString id = hledat->value(0).toString();
    hledat->prepare(prikaz_1);
    hledat->exec();
    hledat->first();
    QString jmeno = hledat->value(0).toString();
    hledat->prepare(prikaz_2);
    hledat->exec();
    hledat->first();
    QString klub = hledat->value(0).toString();
    hledat->prepare(prikaz_3);
    hledat->exec();
    hledat->first();
    QString narodnost = hledat->value(0).toString();
    hledat->prepare(prikaz_4);
    hledat->exec();
    hledat->first();
    QString vek = hledat->value(0).toString();
    hledat->prepare(prikaz_5);
    hledat->exec();
    hledat->first();
    QString pozice = hledat->value(0).toString();
    hledat->prepare(prikaz_6);
    hledat->exec();
    hledat->first();
    QString goly = hledat->value(0).toString();
    hledat->prepare(prikaz_7);
    hledat->exec();
    hledat->first();
    QString asistence = hledat->value(0).toString();
    hledat->prepare(prikaz_8);
    hledat->exec();
    hledat->first();
    QString zlute = hledat->value(0).toString();
    hledat->prepare(prikaz_9);
    hledat->exec();
    hledat->first();
    QString cervene = hledat->value(0).toString();

    QString zobrazit =  "Jmeno : " + jmeno + "\n"
                        "Klub : " + klub + "\n"
                        "Narodnost : " + narodnost + "\n"
                        "Vek : " + vek + "\n"
                        "Pozice: " + pozice + "\n"
                        "Goly : " + goly + "\n"
                        "Asistence : " + asistence + "\n"
                        "Zlute karty : " + zlute + "\n"
                        "Cervene karty : " + cervene + "\n";
    ui->textBrowserHrac->setText(zobrazit);

    //QPixmap fot("../hracifot/" + id + ".png");
    //qDebug << fot;
    //int v = ui->fotka->width();
    //int s = ui->fotka->height();
    //ui->fotka->setPixmap(fot.scaled(v,s,Qt::KeepAspectRatio);
}

void FotbalDB::on_pushButtonZobrazitKlub_clicked()
{
    ui->textBrowserKlub->clear();
    QSqlQuery *hledat = new QSqlQuery;

    QString klub_hledan = ui->comboBoxKlub->currentText();
    QString prikaz = "SELECT Jméno FROM hraci WHERE Klub = '" + klub_hledan + "'";

    //qDebug() << prikaz;
    hledat->prepare(prikaz);
    hledat->exec();
    QString hraci = "";
    while(hledat->next()){
        QString jm = hledat->value(0).toString();
        hraci += "" + jm + "\n";
    }
    //hraci.chop(2);

    QString zobrazit =  "Hraci " + klub_hledan + ":\n" + hraci + "";

    ui->textBrowserKlub->setText(zobrazit);
}

void FotbalDB::on_pushButtonZobrazitVyhledavani_clicked()
{
    ui->textBrowserVyhledavani->clear();

    QString vetsi_mensi;
    QString hledani;
    QString kriteria = ui->comboBoxKriteria->currentText();
    QString hodnota = ui->spinBox->text();
    QSqlQuery *hledat = new QSqlQuery;

    if (ui->radioButtonMensi->isChecked())
        vetsi_mensi = "<";
    else if (ui->radioButtonVetsi->isChecked())
        vetsi_mensi = ">";

    if (kriteria == "Žluté karty")
        hledani = "Žlutékarty";
    else if (kriteria == "Červené karty")
        hledani = "Červenékarty";
    else
        hledani = kriteria;

    QString seznam;
    QString klub;
    QString narodnost;
    QString vek;
    QString pozice;
    QString goly;
    QString asistence;
    QString zlute;
    QString cervene;
    QString prikaz =    "SELECT Jméno, Klub, Národnost, Věk, Pozice, Goly, Asistence, Žlutékarty, Červenékarty"
                        " FROM hraci WHERE " + hledani + " " + vetsi_mensi + " " + hodnota + " ORDER BY " + hledani + "";
    hledat->prepare(prikaz);
    hledat->exec();
    while (hledat->next()) {
        QString jmeno = hledat->value(0).toString();
        if (ui->checkBoxKlub->isChecked())
            klub = "   Klub : " + hledat->value(1).toString() + "\n";
        if (ui->checkBoxNarodnost->isChecked())
            narodnost = "   Narodnost : " + hledat->value(2).toString() + "\n";
        if (ui->checkBoxVek->isChecked())
            vek = "   Vek : " + hledat->value(3).toString() + "\n";
        if (ui->checkBoxPozice->isChecked())
            pozice = "   Pozice :" + hledat->value(4).toString() + "\n";
        if (ui->checkBoxGoly->isChecked())
            goly = "   Goly : " + hledat->value(5).toString() + "\n";
        if (ui->checkBoxAsistence->isChecked())
            asistence = "   Asistence : " + hledat->value(6).toString() + "\n";
        if (ui->checkBoxZlute->isChecked())
            zlute = "   Zlute karty : " + hledat->value(7).toString() + "\n";
        if (ui->checkBoxCervene->isChecked())
            cervene = "   Cervene karty : " + hledat->value(8).toString() + "\n";

        seznam += "" + jmeno + " \n" + klub + narodnost + vek + pozice + goly + asistence + zlute + cervene + "\n";
        klub.clear();
        narodnost.clear();
        vek.clear();
        pozice.clear();
        goly.clear();
        asistence.clear();
        zlute.clear();
        cervene.clear();
    }
    ui->textBrowserVyhledavani->setText(seznam);
}

void FotbalDB::on_pushButtonPridat_clicked()
{
    QString jmeno = ui->lineEditJmeno->text();
    QString klub = ui->lineEditKlub->text();
    QString narodnost = ui->lineEditNarodnost->text();
    QString vek = ui->lineEditVek->text();
    QString pozice = ui->lineEditPozice->text();
    QString goly = ui->lineEditGoly->text();
    QString asistence = ui->lineEditAsistence->text();
    QString zlute = ui->lineEditZlute->text();
    QString cervene = ui->lineEditCervene->text();

    QSqlQuery *pridat = new QSqlQuery;
    QString max_id_prikaz = "SELECT MAX(id)+1 FROM hraci";
    pridat->prepare(max_id_prikaz);
    pridat->exec();
    pridat->first();
    QString max_id = pridat->value(0).toString();

    QString pridat_prikaz = "INSERT INTO hraci (id, Jméno, Věk, Národnost, Klub, Pozice, Goly, Asistence, Žlutékarty, Červenékarty) "
                            "VALUES ('" + max_id + "', '" + jmeno + "', '" + vek + "', '" + narodnost + "', '" + klub + "', '" + pozice + "', '" + goly + "', '" + asistence + "', '" + zlute + "', '" + cervene + "')";
    pridat->prepare(pridat_prikaz);
    pridat->exec();

    ui->lineEditJmeno->clear();
    ui->lineEditVek->clear();
    ui->lineEditNarodnost->clear();
    ui->lineEditKlub->clear();
    ui->lineEditGoly->clear();
    ui->lineEditAsistence->clear();
    ui->lineEditZlute->clear();
    ui->lineEditCervene->clear();
    ui->lineEditPozice->clear();
/*
    ui->comboBoxHrac->clear();
    ui->comboBoxHrac->addItems(hledatHraci());
    ui->comboBoxKlub->clear();
    ui->comboBoxKlub->addItems(hledatKluby());
    ui->comboBoxEditHrac->clear();
    ui->comboBoxEditHrac->addItems(hledatHraci());
    ui->comboBoxSmazatHrac->clear();
    ui->comboBoxSmazatHrac->addItems(hledatHraci());
*/
    blank();
    QMessageBox::information(nullptr, "PRIDANI!", "Uspesne pridan.");
}

void FotbalDB::on_pushButtonEditovat_clicked()
{
    if (ui->comboBoxEditHrac->currentText() != "" && ui->comboBoxCoEditovat->currentText() != ""){
        QSqlQuery *editovat = new QSqlQuery;
        QString co_editovat;
        QString zmena = ui->lineEditCoEditovat->text();
        QString hrac_k_editaci = ui->comboBoxEditHrac->currentText();

        if (ui->comboBoxCoEditovat->currentText() == "Žluté karty")
            co_editovat = "Žlutékarty";
        else if (ui->comboBoxCoEditovat->currentText() == "Červené karty")
            co_editovat = "Červenékarty";
        else
            co_editovat = ui->comboBoxCoEditovat->currentText();

        QString editovat_prikaz = "UPDATE hraci SET " + co_editovat + " = '" + zmena + "' WHERE Jméno = '" + hrac_k_editaci + "'";
        editovat->prepare(editovat_prikaz);
        editovat->exec();

        ui->lineEditCoEditovat->clear();
/*
        ui->comboBoxHrac->clear();
        ui->comboBoxHrac->addItem("");
        ui->comboBoxHrac->addItems(hledatHraci());
        ui->comboBoxKlub->clear();
        ui->comboBoxKlub->addItem("");
        ui->comboBoxKlub->addItems(hledatKluby());
        ui->comboBoxEditHrac->clear();
        ui->comboBoxEditHrac->addItem("");
        ui->comboBoxEditHrac->addItems(hledatHraci());
        ui->comboBoxSmazatHrac->clear();
        ui->comboBoxSmazatHrac->addItem("");
        ui->comboBoxSmazatHrac->addItems(hledatHraci());
        ui->comboBoxCoEditovat->clear();
        ui->comboBoxCoEditovat->addItem("");
        QStringList co_editovat_c = {"Jméno", "Klub", "Národnost", "Pozice", "Věk", "Goly", "Asistence", "Žluté karty", "Červené karty"};
        ui->comboBoxCoEditovat->addItems(co_editovat_c);
*/
        blank();
        QMessageBox::information(nullptr, "Editace:", "Uspesne editovan.");
    }
    else
        QMessageBox::warning(nullptr, "POZOR!", "Zadejte co chcete editovat a tok, ktery chcete editovat.");
}

void FotbalDB::on_pushButtonSmazat_clicked()
{
    if (ui->comboBoxSmazatHrac->currentText() != ""){
        QString hrac = ui->comboBoxSmazatHrac->currentText();
        QSqlQuery *smazat = new QSqlQuery;

        QMessageBox::StandardButton mazani;
        mazani = QMessageBox::question(this, "POZOR!", "Opravdu chcete smazat tento hrac a vsechny jeho udaje?",
                                       QMessageBox::Ok|QMessageBox::Cancel);
        if (mazani == QMessageBox::Ok){
            QString smazat_prikaz = "DELETE FROM hraci WHERE Jméno = '" + hrac + "'";

            qDebug() << smazat_prikaz;
            smazat->prepare(smazat_prikaz);
            smazat->exec();
/*
            ui->comboBoxHrac->clear();
            ui->comboBoxHrac->addItem("");
            ui->comboBoxHrac->addItems(hledatHraci());
            ui->comboBoxKlub->clear();
            ui->comboBoxKlub->addItem("");
            ui->comboBoxKlub->addItems(hledatKluby());
            ui->comboBoxEditHrac->clear();
            ui->comboBoxEditHrac->addItem("");
            ui->comboBoxEditHrac->addItems(hledatHraci());
            ui->comboBoxSmazatHrac->clear();
            ui->comboBoxSmazatHrac->addItem("");
            ui->comboBoxSmazatHrac->addItems(hledatHraci());
            */
            blank();
        }
    }
    else
        QMessageBox::warning(NULL,"POZOR!","Zadejte hrac, který chcete smazat");

}
