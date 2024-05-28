#include <sqlite3.h>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
   sqlite3 *db;
   int rc;
   rc = sqlite3_open("test.db", &db);
   if (rc != SQLITE_OK) {
      cerr << "Error opening database: " << sqlite3_errmsg(db) << endl;
      sqlite3_close(db);
      return 1;
   }

   // Cria a consulta SQL
   const char *sql = "CREATE TABLE PEOPLE (ID INT PRIMARY KEY NOT NULL, NAME TEXT NOT NULL);";

   // Executa a consulta SQL
   rc = sqlite3_exec(db, sql, NULL, 0, NULL);
   if (rc != SQLITE_OK) {
       std::cerr << "Erro ao executar a consulta SQL: " << sqlite3_errmsg(db) << std::endl;
       sqlite3_close(db);
       return 1;
   }
   sqlite3_close(db);
   return 0;
}

