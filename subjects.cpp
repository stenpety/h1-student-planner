#include "subjects.h"
#include "ui_subjects.h"

Subjects::Subjects(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Subjects)
{
    ui->setupUi(this);

    setupDbModel();
    setupTable();

    connect(ui->newSubjectButton, &QPushButton::pressed, this, &Subjects::showNewSubjectForm);
    connect(ui->editSubjectButton, &QPushButton::pressed, this, &Subjects::showEditSubjectForm);
    connect(ui->deleteSubjectButton, &QPushButton::pressed, this, &Subjects::deleteSubject);
}

Subjects::~Subjects()
{
    delete ui;
}

void Subjects::setupDbModel() {
    subjectsModel = new QSqlRelationalTableModel(ui->subjectsTableView);
    subjectsModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    subjectsModel->setTable("subjects");

    /* Set model headers */
    /* (id INTEGER PRIMARY KEY, code VARCHAR, title VARCHAR, numAssts INTEGER, finalScore DOUBLE, semester INTEGER) */
    subjectsModel->setHeaderData(subjectsModel->fieldIndex("code"), Qt::Horizontal, tr("Code"));
    subjectsModel->setHeaderData(subjectsModel->fieldIndex("title"), Qt::Horizontal, tr("Subject"));
    subjectsModel->setHeaderData(subjectsModel->fieldIndex("numAssts"), Qt::Horizontal, tr("Assignments"));
    subjectsModel->setHeaderData(subjectsModel->fieldIndex("finalScore"), Qt::Horizontal, tr("Grade"));
    subjectsModel->setHeaderData(subjectsModel->fieldIndex("semester"), Qt::Horizontal, tr("Semester"));

    /* Connect foreign key to semesters table */
    subjectsModel->setRelation(5, QSqlRelation("semesters", "id", "semesterID"));


    if (!subjectsModel->select()) {
        QMessageBox::critical(this, "Unable to setup model",
                              "Error creating table model: " + subjectsModel->lastError().text());
        return;
    }
    subjectsModel->sort(1, Qt::AscendingOrder);
}

void Subjects::setupTable() {
    ui->subjectsTableView->setModel(subjectsModel);
    subjectsDelegate = new QSqlRelationalDelegate(ui->subjectsTableView);
    ui->subjectsTableView->setItemDelegate(subjectsDelegate);

    ui->subjectsTableView->setColumnHidden(subjectsModel->fieldIndex("id"), true);
    ui->subjectsTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->subjectsTableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    subjectsMapper = new QDataWidgetMapper();
    subjectsMapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
    subjectsMapper->setModel(subjectsModel);
    subjectsMapper->setItemDelegate(subjectsDelegate);

    connect(ui->subjectsTableView->selectionModel(), &QItemSelectionModel::currentRowChanged,
            subjectsMapper, &QDataWidgetMapper::setCurrentModelIndex);

    selectInSubjectsTable(0);
}

void Subjects::selectInSubjectsTable(const int index) {
    subjectsMapper->setCurrentIndex(index);
    ui->subjectsTableView->selectRow(index);
}

/* Slots */
void Subjects::showNewSubjectForm() {
    auto newSubject = new NewSubject();
    if (newSubject->exec()) {
        int rowCount = subjectsModel->rowCount();
        subjectsModel->insertRows(rowCount, 1);
        subjectsModel->setData(subjectsModel->index(rowCount, 1), newSubject->getSubjectCode());
        subjectsModel->setData(subjectsModel->index(rowCount, 2), newSubject->getTitle());
        subjectsModel->setData(subjectsModel->index(rowCount, 3), newSubject->getNumAsst());
        subjectsModel->setData(subjectsModel->index(rowCount, 4), 0.0);
        subjectsModel->setData(subjectsModel->index(rowCount, 5), newSubject->getSemester());
        subjectsModel->submitAll();

        ui->subjectsTableView->resizeColumnsToContents();
    }
    delete newSubject;
}

void Subjects::showEditSubjectForm() {

}

void Subjects::deleteSubject() {

}
