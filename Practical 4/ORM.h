#ifndef ORM_H
#define ORM_H
#include <iostream>
#include <string>

class ORM
{
    public:
        ORM(int, int);
        virtual ~ORM();
        virtual std::string SQLQuery() = 0;
        virtual void insertData(std::string name) = 0;

    protected:
        int maxRows;
        int maxCols;
};

#endif