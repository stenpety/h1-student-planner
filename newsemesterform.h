#ifndef NEWSEMESTERFORM_H
#define NEWSEMESTERFORM_H

#include <QWidget>

namespace Ui {
class NewSemesterForm;
}

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
