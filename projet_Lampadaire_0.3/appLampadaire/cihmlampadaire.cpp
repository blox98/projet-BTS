#include "cihmlampadaire.h"
#include "ui_cihmlampadaire.h"

using namespace std;

CIhmLampadaire::CIhmLampadaire(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::CIhmLampadaire)
{
    ui->setupUi(this);
    QList<QSerialPortInfo> listPsi;  // liste des ports série existant
         listPsi = QSerialPortInfo::availablePorts();  // récupère les ports série disponibles
         for(int i=0 ; i<listPsi.size() ; i++){
             ui->boxPorts->addItem(listPsi.at(i).portName() + " " + listPsi.at(i).description());
             qDebug() << "Port disponible : " << listPsi.at(i).portName() + " " << listPsi.at(i).description();
         }
    mPs = new QSerialPort(this);

    mPs->setPortName("COM5");
    mPs->setBaudRate(QSerialPort::Baud9600);
    mPs->setDataBits(QSerialPort::Data8);
    mPs->setParity(QSerialPort::NoParity);
    mPs->setStopBits(QSerialPort::OneStop);
    mPs->setFlowControl(QSerialPort::NoFlowControl);
    slots
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


void CIhmLampadaire::on_pConnecter_clicked()
{


           // ouverture de la liaison data
    if (ui->pConnecter->text()=="Connecter"){






         if (mPs->open(QIODevice::ReadWrite)) {

             qDebug( "Connecter au COM5");
             ui->txtConsole->append("Connecter au COM5");
             ui->pConnecter->setText("Deconnecter");

         } else{
             qDebug("Impossible de se connecter au COM5") ;
             ui->txtConsole->append("Impossible de se connecter au COM5");

         }

    }else
    {
        mPs->close();
        ui->pConnecter->setText("Connecter");
        qDebug("Deconnecter du COM5");
        ui->txtConsole->append("Deconnecter du COM5");
    }
}
