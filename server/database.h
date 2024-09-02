#ifndef DATABASE_H
#define DATABASE_H

#include <sqlite3.h>
#include <string>

class Database {
public:
    Database(const std::string &db_name);
    ~Database();
    void insertData(const std::string &data);

private:
    sqlite3 *db;
    void createTable();
};

#endif // DATABASE_H