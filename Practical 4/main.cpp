#include "NewDatabaseGrammar.h"
#include "ORM.h"
#include "SQLGrammar.h"

int main()
{
    SQLGrammar sql(5,5);
    sql.insertData("Thomas");
    sql.insertData("Michael");
    sql.insertData("Javier");
    sql.insertData("John");
    sql.insertData("George");
    sql.insertData("Timothy");

    std::cout << sql.SQLQuery() << std::endl;
    
    return 0;
}