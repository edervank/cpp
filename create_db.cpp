#include <sqlite3.h>
#include <iostream>
using namespace std;

int main(int argc, char* argv[]){
     sqlite3 *db;
   int rc;

   rc = sqlite3_open("test.db", &db);
    return 0;
}