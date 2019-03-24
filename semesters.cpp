#include "semesters.h"
#include "ui_semesters.h"

Semesters::Semesters(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Semesters) {
    ui->setupUi(this);

    setupDbModel();
    setupTable();

    connect(ui->newSemesterButton, &QPushButton::pressed, this, &Semesters::showNewSemesterForm);
}

Semesters::~Semesters() {
    delete ui;
}

void Semesters::setupDbModel() {
    semestersModel = new QSqlRelationalTableModel(ui->semestersTableView);
    semestersModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    semestersModel->setTable("semesters");

    /* Set model headers */
    semestersModel->setHeaderData(semestersModel->fieldIndex("semesterID"), Qt::Horizontal, tr("Semester"));
    semestersModel->setHeaderData(semestersModel->fieldIndex("startDate"), Qt::Horizontal, tr("Start Date"));
    semestersModel->setHeaderData(semestersModel->fieldIndex("endDate"), Qt::Horizontal, tr("End Date"));

    if (!semestersModel->select()) {
        QMessageBox::critical(this, "Unable to setup model",
                              "Error creating table model: " + semestersModel->lastError().text());
        return;
    }
    semestersModel->sort(1, Qt::AscendingOrder);
}

void Semesters::setupTable() {
    ui->semestersTableView->setModel(semestersModel);
    semestersDelegate = new QSqlRelationalDelegate(ui->semestersTableView);
    ui->semestersTableView->setItemDelegate(semestersDelegate);

    ui->semestersTableView->setColumnHidden(semestersModel->fieldIndex("id"), true);
    ui->semestersTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->semestersTableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    semestersMapper = new QDataWidgetMapper();
    semestersMapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
    semestersMapper->setModel(semestersModel);
    semestersMapper->setItemDelegate(semestersDelegate);

    connect(ui->semestersTableView->selectionModel(), &QItemSelectionModel::currentRowChanged,
            semestersMapper, &QDataWidgetMapper::setCurrentModelIndex);
    selestInSemestersTable(0);
}

void Semesters::selestInSemestersTable(const int index) {
    semestersMapper->setCurrentIndex(index);
    ui->semestersTableView->selectRow(index);
}

void Semesters::showNewSemesterForm() {
    auto newSemester = new NewSemester();
    if (newSemester->exec()) {
        QMessageBox::about(this, tr("Success"),
                tr(newSemester->getSemesterLineEditText().toStdString().c_str()) );
    }
}

void Semesters::deleteSemester() {
    //TODO: implement delete
}
