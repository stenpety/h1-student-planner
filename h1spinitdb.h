#ifndef H1SPINITDB_H
#define H1SPINITDB_H

#include <QtSql>

/**
 * @brief addSemester - adds a new Semester to the data base
 * @param query - query to reuse
 * @param semesterID - ID e.g. 2019-SM1
 * @param startDate - starting date
 * @param endDate - finishing date
 */
void addSemester(QSqlQuery &query, const QString &semesterID, const QDate &startDate, const QDate &endDate) {
    query.addBindValue(semesterID);
    query.addBindValue(startDate);
    query.addBindValue(endDate);

    query.exec();
}

/**
 * @brief addSubject - adds a new subject to the database
 * @param query - query to reuse
 * @param code - subject code e.g. COMP90025
 * @param title - subject title
 * @param numAssts - number of assessments
 * @param finalScore - final grade for the subject
 * @param semesterId - foreign key, semester when subject is taken
 */
void addSubject(QSqlQuery &query, const QString &code, const QString &title,
                const int numAssts, const double finalScore, const QVariant &semesterId) {
    query.addBindValue(code);
    query.addBindValue(title);
    query.addBindValue(numAssts);
    query.addBindValue(finalScore);
    query.addBindValue(semesterId);

    query.exec();
}

/**
 * @brief addAssessment - add a new assessment to the database
 * @param query - query to reuse
 * @param id - assessment id
 * @param relDate - release date
 * @param dlDate - deadkine date
 * @param maxScore - max allocated score
 * @param score - score for the assessment
 * @param submitted - submitted or not
 */
void addAssessment(QSqlQuery &query, const QString &id, const QDate relDate, const QDate dlDate,
                   const double maxScore, const double score, const bool submitted) {
    query.addBindValue(id);
    query.addBindValue(relDate);
    query.addBindValue(dlDate);
    query.addBindValue(maxScore);
    query.addBindValue(score);
    query.addBindValue(submitted);

    query.exec();
}

void databaseConnect(const QString &dbFileName) {
    const QString DRIVER ("QSQLITE");

    if (QSqlDatabase::isDriverAvailable(DRIVER)) {
        QSqlDatabase db = QSqlDatabase::addDatabase(DRIVER);

        db.setDatabaseName(dbFileName);
        if (!db.open()) {
            qWarning() << "Database connect ERROR: " << db.lastError().text();
        }
    } else {
        qWarning() << "Database connect ERROR: no driver " << DRIVER << " available";
    }
}

void createTablesDb() {
    QSqlQuery query;

    query.prepare("CREATE TABLE setevik (id INTEGER PRIMARY KEY, name TEXT, vk TEXT, story TEXT, company INTEGER)");
    if (!query.exec()) {
        qWarning() << "Database create tables (setevik) ERROR: " << query.lastError().text();
    }

    query.prepare("CREATE TABLE companies (id INTEGER PRIMARY KEY, name TEXT, vk TEXT, keyword TEXT)");
    if (!query.exec()) {
        qWarning() << "Database create tables (companied) ERROR: " << query.lastError().text();
    }

    query.prepare("CREATE TABLE timers (id INTEGER PRIMARY KEY, name INTEGER, start_date INTEGER, duration INTEGER, description TEXT, penalty TEXT)");
    if (!query.exec()) {
        qWarning() << "Database create tables (timers) ERROR: " << query.lastError().text();
    }

}

void initiSetevikDB(const QString &dbFileName) {

    bool dbFileExists = (QFileInfo::exists(dbFileName) && QFileInfo(dbFileName).isFile());
    databaseConnect(dbFileName);

    // TODO: check tables, NOT file existense
    if (!dbFileExists) {
        createTablesDb();
        std::cout << "DB tables created" << std::endl;
    }
}
QSqlError initDB() {
    QSqlDatabase db = QSqlDatabase::addDatabase("QSQLITE");


    return QSqlError();
}

#endif // H1SPINITDB_H
