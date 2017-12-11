#ifndef REC_H
#define REC_H
#include "Date.h"
#include<iostream>
class Rec
{
    public:
        Rec();
        Rec & operator=(const Rec &);
        Rec(const Rec &);
        ~Rec();
        Rec(const char* n, unsigned a,const char* s, unsigned g, const char* d);
        void print();
        friend std::ifstream& operator>>(std::ifstream & ifs, Rec& r);
        const char * getName() const;
        const char * getSubject() const;
        unsigned getAge() const;
        unsigned getGrade() const;
        Date & getDate();
        void separateAndFill(char*str);

    private:
        void setName(const char *);
        void setSubject(const char *);
        bool setDate(const char*);
        void copyFrom(const Rec& other);

    private:
    char * name;
    char * subject;
    unsigned age;
    unsigned grade;
    Date date;

};

#endif // REC_H
