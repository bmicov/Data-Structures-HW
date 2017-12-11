#include "Date.h"
#include<iostream>
unsigned getDigit(const char d)
{
    int dig;
    dig=d-'0';
    if(dig<0 || dig>9) return 10;
    else return dig;
}
Date::Date(unsigned y, unsigned m, unsigned d)
{
        this->y=y;
        this->m=m;
        this->d=d;
}
Date::Date(): y(0), m(0), d(0){}

bool Date::readDate(const char* dateStr)
{
            d=getDigit(dateStr[8])*10+getDigit(dateStr[9]);
            m=getDigit(dateStr[5])*10+getDigit(dateStr[6]);
            y=getDigit(dateStr[0])*1000 + getDigit(dateStr[1])*100
                + getDigit(dateStr[2])*10 + getDigit(dateStr[3]);

        if (d>31 || m>12 || dateStr[4]!='-' || dateStr[7]!='-')
        {
            d=0;m=0;y=0;
            return false;
        }
        return true;

}
bool Date::operator<(const Date & other)
{
    if(y<other.y) return true;
    else if(y==other.y)
            if(m<other.m) return true;
            else if(m==other.m)
                    if(d<other.d) return true;
    return false;
}
bool Date::operator==(const Date & other)
{
    return ((y==other.y) && (m=other.m) && (d=other.d));
}
bool Date::operator>(const Date & other)
{
    return (!(*this<other && *this==other));
}
void Date::print()
{
std::cout<<d<<'-'<<m<<'-'<<y;
}
