#ifndef TAB_H
#define TAB_H
#include<ostream>


class TAB
{   //private:
private: unsigned time;
        char * url;

public:
        TAB();
        ~TAB();
        TAB(const TAB&);
        friend std::ostream & operator<<(std::ostream & os,const TAB &);
        void setURL(const char *);
        void refresh();
        TAB & operator=(const TAB&);
private:






};

#endif // TAB_H
