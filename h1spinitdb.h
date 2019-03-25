#ifndef H1SPINITDB_H
#define H1SPINITDB_H

#include <QtSql>

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
