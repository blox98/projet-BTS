#ifndef CIHMLAMPADAIRE_H
#define CIHMLAMPADAIRE_H

#include <QMainWindow>
#include <QDebug>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QMessageBox>

#include <QTranslator>
namespace Ui {
class CIhmLampadaire;
}

class CIhmLampadaire : public QMainWindow
{
    Q_OBJECT

public:
    explicit CIhmLampadaire(QWidget *parent = 0);
    ~CIhmLampadaire();

private slots:
  //  void on_PbLire_clicked(bool checked);

    void on_PbLire_clicked();

    void on_PbEnregistrer_clicked();

    void on_pReset_clicked();

    void on_pbEffacer_clicked();

    void on_pConnecter_clicked();

    void on_boxPorts_activated(const QString &arg1);

    void on_boxPorts_highlighted(const QString &arg1);

private:
    Ui::CIhmLampadaire *ui;
    QSerialPort *mPs;

};

#endif // CIHMLAMPADAIRE_H
