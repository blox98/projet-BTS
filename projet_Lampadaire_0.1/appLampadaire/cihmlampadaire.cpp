#include "cihmlampadaire.h"
#include "ui_cihmlampadaire.h"

CIhmLampadaire::CIhmLampadaire(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CIhmLampadaire)
{
    ui->setupUi(this);
}

CIhmLampadaire::~CIhmLampadaire()
{
    delete ui;
}

void CIhmLampadaire::on_PbLire_clicked()
{
    ui->lineId->setText("5555");
    ui->BoxJv->setCurrentText("Disabled [0]");
    ui->BoxCe->setCurrentText("Enabled [1]");
    ui->LineDh->setText("0");
    ui->LineDl->setText("ffff");
    ui->LineNi->setText("Maître");
    ui->txtGeo->setText("L'isle sur la Sorgue, Lycée Alphonse Benoit");
    ui->txtCom->setText("Module maître du projet BTS SN du Lycée Alphonse Benoit");
    ui->txtConsole->append("Les paramètres ont été mis à jour");
    QMessageBox::information(this,"Lecture","Les paramètres ont été mis à jour");
}

void CIhmLampadaire::on_PbEnregistrer_clicked()
{
    ui->txtConsole->append("Les paramètres ont été enregistrer");
    QMessageBox::information(this,"Enregistrement","Les paramètres ont été enregistrer");
}

void CIhmLampadaire::on_pReset_clicked()
{
    QMessageBox::StandardButton reply;
      reply =  QMessageBox::question(this, "Attention", "Vous etes sur le point de restaurer les paramètres par défaut", QMessageBox::No|QMessageBox::Yes);
      if (reply == QMessageBox::Yes) {
        ui->lineId->setText("");
        ui->BoxJv->setCurrentText("Disabled [0]");
        ui->BoxCe->setCurrentText("Disabled [0]");
        ui->LineDh->setText("");
        ui->LineDl->setText("");
        ui->LineNi->setText("");
        ui->txtGeo->setText("");
        ui->txtCom->setText("");
        ui->txtConsole->append("Restauration des paramètres par défaut");
        QMessageBox::information(this,"Reset"," Restauration des paramètres par défaut");
      }
}

void CIhmLampadaire::on_pbEffacer_clicked()
{
    ui->txtConsole->setText("");
}
