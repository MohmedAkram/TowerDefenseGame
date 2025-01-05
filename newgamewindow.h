#ifndef NEWGAMEWINDOW_H
#define NEWGAMEWINDOW_H

#include <QDialog>

namespace Ui {
class newgamewindow;
}

class newgamewindow : public QDialog
{
    Q_OBJECT

public:
    explicit newgamewindow(QWidget *parent = nullptr);
    ~newgamewindow();

private slots:
    void on_Nextlevelbutton_clicked();

private:
    Ui::newgamewindow *ui;
};

#endif // NEWGAMEWINDOW_H
