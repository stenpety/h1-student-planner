#include "assignments.h"
#include "ui_assignments.h"

Assignments::Assignments(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Assignments) {

    ui->setupUi(this);
    setupDbModel();
    setupTable();

    connect(ui->newAsstPushButton, &QPushButton::pressed, this, &Assignments::showNewAssignmentForm);
}

Assignments::~Assignments() {
    delete ui;
}

void Assignments::setupDbModel() {
    assignmentsModel = new QSqlRelationalTableModel(ui->assignmentsTableView);
    assignmentsModel->setEditStrategy(QSqlTableModel::OnManualSubmit);
    assignmentsModel->setTable("assignments");

    /* Set model headers */
    /* id INTEGER PRIMARY KEY, title VARCHAR, relDate DATE, dlDate DATE, maxScore DOUBLE, score DOUBLE, submitted BOOLEAN, subject INTEGER) */
    assignmentsModel->setHeaderData(assignmentsModel->fieldIndex("title"), Qt::Horizontal, tr("Assignment"));
    assignmentsModel->setHeaderData(assignmentsModel->fieldIndex("relDAte"), Qt::Horizontal, tr("Released"));
    assignmentsModel->setHeaderData(assignmentsModel->fieldIndex("dlDAte"), Qt::Horizontal, tr("Dead line"));
    assignmentsModel->setHeaderData(assignmentsModel->fieldIndex("maxScore"), Qt::Horizontal, tr("Max score"));
    assignmentsModel->setHeaderData(assignmentsModel->fieldIndex("score"), Qt::Horizontal, tr("Score"));
    assignmentsModel->setHeaderData(assignmentsModel->fieldIndex("submitted"), Qt::Horizontal, tr("Submitted"));
    assignmentsModel->setHeaderData(assignmentsModel->fieldIndex("subject"), Qt::Horizontal, tr("Subject"));

    /* Connect foreign key to semesters table */
    assignmentsModel->setRelation(7, QSqlRelation("subjects", "id", "title"));


    if (!assignmentsModel->select()) {
        QMessageBox::critical(this, "Unable to setup model",
                              "Error creating table model: " + assignmentsModel->lastError().text());
        return;
    }
    assignmentsModel->sort(1, Qt::AscendingOrder);
}

void Assignments::setupTable() {
    ui->assignmentsTableView->setModel(assignmentsModel);
    assignmentsDelegate = new QSqlRelationalDelegate(ui->assignmentsTableView);
    ui->assignmentsTableView->setItemDelegate(assignmentsDelegate);

    ui->assignmentsTableView->setColumnHidden(assignmentsModel->fieldIndex("id"), true);
    ui->assignmentsTableView->setSelectionMode(QAbstractItemView::SingleSelection);
    ui->assignmentsTableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    assignmentsMapper = new QDataWidgetMapper();
    assignmentsMapper->setSubmitPolicy(QDataWidgetMapper::ManualSubmit);
    assignmentsMapper->setModel(assignmentsModel);
    assignmentsMapper->setItemDelegate(assignmentsDelegate);

    connect(ui->assignmentsTableView->selectionModel(), &QItemSelectionModel::currentRowChanged,
            assignmentsMapper, &QDataWidgetMapper::setCurrentModelIndex);

    selectInAssignmentsTable(0);
}

void Assignments::selectInAssignmentsTable(const int index) {
    assignmentsMapper->setCurrentIndex(index);
    ui->assignmentsTableView->selectRow(index);
}

/* Slots */
void Assignments::showNewAssignmentForm() {
    auto newAssignment = new NewAssignment();
    if (newAssignment->exec()) {
        int rowCount = assignmentsModel->rowCount();
        assignmentsModel->insertRows(rowCount, 1);
        assignmentsModel->setData(assignmentsModel->index(rowCount, 1), newAssignment->getTitle());
        assignmentsModel->setData(assignmentsModel->index(rowCount, 2), newAssignment->getRelDate());
        assignmentsModel->setData(assignmentsModel->index(rowCount, 3), newAssignment->getDlDate());
        assignmentsModel->setData(assignmentsModel->index(rowCount, 4), newAssignment->getMaxScore());
        assignmentsModel->setData(assignmentsModel->index(rowCount, 5), newAssignment->getScore());
        assignmentsModel->setData(assignmentsModel->index(rowCount, 6), newAssignment->getSubmitted());
        assignmentsModel->setData(assignmentsModel->index(rowCount, 7), newAssignment->getSubject());
        assignmentsModel->submitAll();

        ui->assignmentsTableView->resizeColumnsToContents();
    }
    delete newAssignment;
}

void Assignments::deleteAssignment() {

}
