#include"TAB.h"
#include<ctime>
#include<cstring>

TAB::TAB()
{
    time = std::time(0);
    url=new char;
    url="";
}
void TAB::refresh()
{
    time=std::time(0);
}

TAB::~TAB()
{
    delete[] url;
}
TAB::TAB(const TAB & other)
{
    time=other.time;
    setURL(other.url);
}
TAB & TAB::operator=(const TAB & other)
{
    if(this!=&other)
    {
        delete[] url;
        setURL(other.url);
        time=other.time;
    }
    return *this;
}
void TAB::setURL(const char* u)
{
    int n=strlen(u);

    url=new char[n+1];
    strcpy(url,u);
}
std::ostream & operator<<(std::ostream &os, const TAB &t)
{
    os<<t.url;
    os<<" ";
    os<<t.time;
    os<<"\n";
}
