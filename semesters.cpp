#include "semesters.h"
#include "ui_semesters.h"

Semesters::Semesters(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Semesters) {
    ui->setupUi(this);

    setupDbModel();
    setupTable();

    /* New semester */
    connect(ui->newSemesterButton, &QPushButton::pressed, this, &Semesters::showNewSemesterForm);

    /* Delete semester */
    connect(ui->deleteSemesterButton, &QPushButton::pressed, this, &Semesters::deleteSemester);
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
    selectInSemestersTable(0);
}

void Semesters::selectInSemestersTable(const int index) {
    semestersMapper->setCurrentIndex(index);
    ui->semestersTableView->selectRow(index);
}

void Semesters::showNewSemesterForm() {
    auto newSemester = new NewSemester();
    if (newSemester->exec()) {
        int rowCount = semestersModel->rowCount();
        semestersModel->insertRows(rowCount, 1);
        semestersModel->setData(semestersModel->index(rowCount, 1), newSemester->getSemesterLineEditText());
        semestersModel->setData(semestersModel->index(rowCount, 2), newSemester->getStartDate());
        semestersModel->setData(semestersModel->index(rowCount, 3), newSemester->getEndDate());
        semestersModel->submitAll();

        ui->semestersTableView->resizeColumnsToContents();
    }
    delete newSemester;
}

void Semesters::deleteSemester() {
    /* Index to delete = currently selected row */
    int rowToDelete = semestersMapper->currentIndex();

    /* Deletion dialog */
    QMessageBox::StandardButton deleteDialog;
    QString semesterToDelete = semestersModel->record(rowToDelete).value(1).toString();
    deleteDialog = QMessageBox::question(this, "Delete semester", "Delete " + semesterToDelete + "?\nAre you sure?",
                                         QMessageBox::Yes|QMessageBox::No);
    if (deleteDialog == QMessageBox::Yes) {


        if (!(semestersModel->removeRow(rowToDelete))) {
            QMessageBox::critical(this, "Unable to delete semester",
                                  "Error deleting semester: " +
                                  semestersModel->lastError().text());
            return;
        }
        /* Apply changes to the DB */
        semestersModel->submitAll();
        semestersMapper->submit();

        if (semestersModel->rowCount() > 0) {
            selectInSemestersTable(rowToDelete);
        } else {
            selectInSemestersTable(-1);
        }

        ui->semestersTableView->resizeColumnsToContents();
    }
}
