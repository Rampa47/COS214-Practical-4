#include "NewDatabaseGrammar.h"

NewDatabaseGrammar::NewDatabaseGrammar(){}

std::string NewDatabaseGrammar::makeQuery()
{
    std::string query;

    std::cout << "Please enter the query you wish to make: " << std::endl;
    std::getline(std::cin, query);

    return query;
}