#include "Rec.h"
#include<iostream>
#include<fstream>
#include<cstring>
#include<cmath>
#include<new>
unsigned toNumber(const char* str)
{
    unsigned num=0;
    for(int i=0;i<strlen(str);i++)
    num=num+getDigit(str[i])*pow(10,strlen(str)-i-1);//...
    return num;
}
Rec::Rec()
{
    name=nullptr;
    subject=nullptr;
    age=0;
    grade=0;
}
Rec::Rec(const char* n, unsigned a,const char* s, unsigned g, const char* d)
{
    setSubject(s);


    try{
        setName(n);
        }catch(std::bad_alloc &e)
    {
        delete[] subject;
        throw;
    }
    age=a;
    grade=g;
    if(!setDate(d))
    throw 1;

}
Rec::~Rec()
{
delete[] name;
delete[] subject;
}
void Rec::setName(const char * n)//have to free before use
{
    int len=strlen(n);
    name=new char[len+1];
    strcpy(name, n);
}
void Rec::setSubject(const char * s)
{
    int len=strlen(s);
    subject=new char[len+1];
    strcpy(subject, s);
}
bool Rec::setDate(const char * d)
{
    return date.readDate(d);
}
void Rec::copyFrom(const Rec& other)
{       if(other.name&&other.subject){
        setSubject(other.subject);
        setName(other.name);
        }else {
        name=nullptr;
        subject=nullptr;
        }
        age=other.age;
        grade=other.grade;
        date=other.date;
}
Rec & Rec::operator=(const Rec& other)
{
    if(this!=&other)
    {
        delete[] subject;
        delete[] name;
        copyFrom(other);
    }
    return * this;
}
Rec::Rec(const Rec& other)
{
    copyFrom(other);
}
void Rec::print()
{
    std::cout<<name<<" "<<subject<<" "<<age<<" "<<grade<<" ";
    date.print();
}
std::ifstream & operator>>(std::ifstream & ifs, Rec & r)
{
char buff[256];
ifs.getline(buff, 256);
if(!ifs)return ifs;
r.separateAndFill(buff);
return ifs;
}
void Rec::separateAndFill(char * str)
{
char * arr[5];
int i=0;
char *token = std::strtok(str, ",");
    while (token != NULL) {
        arr[i]=token;
        i++;
        token = std::strtok(NULL, ",");

}
setName(arr[0]);
age=toNumber(arr[1]);
try{
setSubject(arr[2]);
}catch(std::bad_alloc& e)
{
    delete[] name;
    throw;
}
grade=toNumber(arr[3]);
if(!setDate(arr[4])) throw 1; //because ctor also throws if data is not valid
//Rec(arr[0],toNumber(arr[1]),arr[2],toNumber(arr[3]),arr[4]);
}

const char* Rec:: getName() const
{
    return name;
}
const char * Rec::getSubject() const
{
    return subject;
}
unsigned Rec::getAge() const
{
    return age;
}
unsigned Rec::getGrade()const
{
    return grade;
}
Date & Rec::getDate()
{
    return date;
}
