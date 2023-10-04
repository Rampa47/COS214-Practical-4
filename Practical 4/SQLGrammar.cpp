#include "SQLGrammar.h"

SQLGrammar::SQLGrammar(int maxRows, int maxCols): ORM(maxRows, maxCols)
{
    newData = new NewDatabaseGrammar();

    database = new std::string * [maxRows];

    for(int i = 0; i < maxRows; i++)
    {
        database[i] = new std::string[maxCols];

        for(int j = 0; j < maxCols; j++)
        {
            database[i][j] = "";
        }
    }
}

SQLGrammar::~SQLGrammar()
{
    if(database != nullptr)
    {
        for(int i = 0; i < maxRows; i++)
        {
            if(database[i] != nullptr)
            {
                delete [] database[i];
            }
        }

        delete [] database;
    }

    if(newData != nullptr)
    {
        delete newData;
    }
}

void SQLGrammar::insertData(std::string name)
{
    for(int i = 0; i < maxRows; i++)
    {
        for(int j = 0; j < maxCols; j++)
        {
            if(database[i][j] == "")
            {
                database[i][j] = name;
                return;
            }
        }
    }
}

std::string SQLGrammar::debug()
{
    std::string info = "";

    bool endOfList = false;

    std::cout << "Here is the list of names in the database: " << std::endl;

    for(int i = 0; i < maxRows; i++)
    {
        for(int j = 0; j < maxCols; j++)
        {
            if(database[i][j] != "")
            {
                info += database[i][j] + " ";
            }
            else
            {
                endOfList = true;
                break;
            }
        }
        
        if(endOfList)
        {
            break;
        }
        else
        {
            info += "\n";
        }
    }

    return info;
}

std::string SQLGrammar::SQLQuery()
{
    std::string query;

    std::string fullQuery;

    std::string finalQuery = "";

    std::string name = newData->makeQuery();

    query = name.substr(0, 'e');

    fullQuery = name.substr('S', '*');

    finalQuery.append(query);

    finalQuery.append(fullQuery);

    return finalQuery;
}