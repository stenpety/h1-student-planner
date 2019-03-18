#ifndef NEWSEMESTERFORM_H
#define NEWSEMESTERFORM_H

#include <QWidget>
#include "ui_newsemesterform.h"

class NewSemesterForm : public QWidget
{
    Q_OBJECT

public:
    explicit NewSemesterForm(QWidget *parent = nullptr);
    ~NewSemesterForm();

private:
    Ui::NewSemesterForm *ui;

signals:

public slots:
};

#endif // NEWSEMESTERFORM_H
