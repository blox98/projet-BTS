#ifndef CIHMLAMPADAIRE_H
#define CIHMLAMPADAIRE_H

#include <QMainWindow>
#include <QtSerialPort/QtSerialPort>
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

    void on_pushButton_clicked();

    void on_pReset_clicked();

    void on_pbEffacer_clicked();

private:
    Ui::CIhmLampadaire *ui;
};

#endif // CIHMLAMPADAIRE_H
