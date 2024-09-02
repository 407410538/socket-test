#include "database.h"
#include <iostream>

Database::Database(const std::string &db_name) {
    if (sqlite3_open(db_name.c_str(), &db)) {
        std::cerr << "Can't open database: " << sqlite3_errmsg(db) << std::endl;
    } else {
        std::cout << "Opened database successfully" << std::endl;
        createTable();
    }
}

Database::~Database() {
    sqlite3_close(db);
}

void Database::createTable() {
    const char* sql = "CREATE TABLE IF NOT EXISTS DATA("
                      "ID INTEGER PRIMARY KEY AUTOINCREMENT,"
                      "TEXT TEXT NOT NULL);";
    char *errMsg = nullptr;

    if (sqlite3_exec(db, sql, nullptr, 0, &errMsg) != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    } else {
        std::cout << "Table created successfully" << std::endl;
    }
}

void Database::insertData(const std::string &data) {
    std::string sql = "INSERT INTO DATA (TEXT) VALUES ('" + data + "');";
    char *errMsg = nullptr;

    if (sqlite3_exec(db, sql.c_str(), nullptr, 0, &errMsg) != SQLITE_OK) {
        std::cerr << "SQL error: " << errMsg << std::endl;
        sqlite3_free(errMsg);
    } else {
        std::cout << "Record inserted successfully" << std::endl;
    }
}