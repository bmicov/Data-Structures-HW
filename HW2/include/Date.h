#ifndef DATE_H
#define DATE_H
#include "functions.h"

class Date
{
    public:
    Date(unsigned y, unsigned m, unsigned d);
    Date();
    Date(const char * dateStr);
    void print();
    bool readDate(const char* dateStr);
    bool operator<(const Date &);
    bool operator>(const Date & other);
    bool operator==(const Date &);
    private:

    unsigned y;
    unsigned m;
    unsigned d;
};

#endif // DATE_H
