#ifndef SQL_GRAMMAR_H
#define SQL_GRAMMAR_H
#include "ORM.h"
#include "NewDatabaseGrammar.h"

class NewDatabaseGrammar;

class SQLGrammar : public ORM
{
    public:
        // Constructor(s)
        SQLGrammar(int maxRows, int maxCols);
        // Destructor
        ~SQLGrammar();
        // Special functions
        std::string SQLQuery();
        std::string QueryResults();
        void insertData(std::string name);
        std::string debug();

    private:
        std::string ** database;
        NewDatabaseGrammar * newData;
};

#endif