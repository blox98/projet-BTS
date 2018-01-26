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
    QMessageBox::information(this,"Lecture","Les paramètres ont été mis à jour");
}

void CIhmLampadaire::on_PbEnregistrer_clicked()
{
    QMessageBox::information(this,"Enregistrement","Les paramètres ont été enregistrer");
}

void CIhmLampadaire::on_pushButton_clicked()
{
    ui->lineId->setText("");
    ui->BoxJv->setCurrentText("Disabled [0]");
    ui->BoxCe->setCurrentText("Disabled [0]");
    ui->LineDh->setText("");
    ui->LineDl->setText("");
    ui->LineNi->setText("");
    QMessageBox::information(this,"Reset"," Restauration des paramètres par défaut");
}
