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
 * @param title - assessment title
 * @param relDate - release date
 * @param dlDate - deadkine date
 * @param maxScore - max allocated score
 * @param score - score for the assessment
 * @param submitted - submitted or not
 */
void addAssessment(QSqlQuery &query, const QString &title, const QDate relDate, const QDate dlDate,
                   const double maxScore, const double score, const bool submitted) {
    query.addBindValue(title);
    query.addBindValue(relDate);
    query.addBindValue(dlDate);
    query.addBindValue(maxScore);
    query.addBindValue(score);
    query.addBindValue(submitted);

    query.exec();
}

/**
 * @brief databaseConnect - connect to SQLite database
 * @param dbFileName - file for SQLite database
 */
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

/**
 * @brief createTablesDb - creates pre-defined tables in the db
 */
void createTablesDb() {
    QSqlQuery query;

    query.prepare("CREATE TABLE semesters (id INTEGER PRIMARY KEY, semesterID VARCHAR, startDate DATE, endDate DATE)");
    if (!query.exec()) {
        qWarning() << "Database create tables (semester) ERROR: " << query.lastError().text();
    }

    query.prepare("CREATE TABLE subjects (id INTEGER PRIMARY KEY, code VARCHAR, title VARCHAR, numAssts INTEGER, finalScore DOUBLE, semester INTEGER)");
    if (!query.exec()) {
        qWarning() << "Database create tables (subjects) ERROR: " << query.lastError().text();
    }

    query.prepare("CREATE TABLE assessments (id INTEGER PRIMARY KEY, title VARCHAR, relDate DATE, dlDate DATE, maxScore DOUBLE, score DOUBLE, submitted BOOLEAN)");
    if (!query.exec()) {
        qWarning() << "Database create tables (timers) ERROR: " << query.lastError().text();
    }

}

/**
 * @brief initDB - initialises database
 * @param dbFileName - file to store db
 */
void initDB(const QString &dbFileName) {

    bool dbFileExists = (QFileInfo::exists(dbFileName) && QFileInfo(dbFileName).isFile());
    databaseConnect(dbFileName);

    // TODO: check tables, NOT file existense
    if (!dbFileExists) {
        createTablesDb();
    }
}

#endif // H1SPINITDB_H
