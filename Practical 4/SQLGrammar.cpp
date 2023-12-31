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

std::string SQLGrammar::print()
{
    std::string info = "";

    bool endOfList = false;

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

std::string SQLGrammar::search(std::string name)
{
    bool found = false;
    int rowIndex = 0, colIndex = 0;

    for(int i = 0; i < maxRows; i++)
    {
        for(int j = 0; j < maxCols; j++)
        {
            if(database[i][j] == name)
            {
                rowIndex = i;
                colIndex = j;
                found = true;
                break;
            }
        }
    }

    if(found)
    {
        std::string item = database[rowIndex][colIndex];

        return item;
    }
    else
    {
        return "Name not in database";
    }
}


std::string SQLGrammar::SQLQuery()
{
    std::string query;

    std::string fullQuery;

    std::string finalQuery = "";

    std::string name = newData->makeQuery();

    for(int i = 0; i < name.length(); i++)
    {
        if(name[i] == 'S' || name[i] == 'G')
        {
            for(int j = i; j < name.length(); j++)
            {
                fullQuery += name[j];
            }

            break;
        }
        else
        {
            query += name[i];
        }
    }

    finalQuery.append(fullQuery);

    finalQuery.append(" ");

    finalQuery.append(query);

    std::cout << finalQuery << std::endl;

    return QueryResults(finalQuery);
}

std::string SQLGrammar::QueryResults(std::string query)
{
    int expression = 0;

    std::string select = "SELECT";

    std::string groupBy = "GROUP BY";

    size_t querySearch = query.find(select);

    size_t nameSearch = query.find(groupBy);

    if(querySearch != std::string::npos)
    {
        expression = 1;
    }
    else if(nameSearch != std::string::npos)
    {
        expression = 2;
    }

    switch(expression) //Remember that the cases are based on whether you are selecting a name or a group of names
    {
        case 1:
        {
            char all = '*';

            size_t found = query.find(all);

            std::string name = "name";

            size_t items = query.find(name);

            std::string object;

            if(found != std::string::npos)
            {
                std::cout << "Here are all the names in the database: " << std::endl;

                std::cout << print() << std::endl;   
            }
            else if(items != std::string::npos)
            {
                std::cout << "Please enter the name that you are looking for: ";
                std::cin >> object;

                return search(object);
            }

            break;
        }

        case 2:
        {
            std::string list = "";

            char letter;

            std::cout << "Please enter the first letter of the names you want to find: ";
            std::cin >> letter;

            for(int i = 0; i < maxRows; i++)
            {
                for(int j = 0; j < maxCols; j++)
                {
                    if(database[i][j][0] == letter)
                    {
                        list += database[i][j] + " ";
                    }
                }
            }

            if(list == "")
            {
                return "No names starting with the chosen letter are in the database.";
            }
            else
            {
                return list;
            }

            break;
        }
    }

    return "";
}