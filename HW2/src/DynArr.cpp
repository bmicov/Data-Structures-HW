#include "DynArr.h"
#include "Rec.h"
#include <fstream>
#include <new>

DynArr::DynArr()
{
records=nullptr;
ssize=0;
capacity=0;
}
DynArr::DynArr(unsigned k)
{
    records = new Rec[k];
    ssize=0;
    capacity=k;
}
DynArr::~DynArr()
{
    delete[] records;
}
DynArr::DynArr(const DynArr& other)
{
copyFrom(other);
}
DynArr& DynArr::operator=(const DynArr& other)
{
    if(this!=&other)
    {
        delete[] records;
        copyFrom(other);
    }
    return *this;
}
void DynArr::copyFrom(const DynArr & other)
{
    records=new Rec[ssize];
    for(int i=0; i<ssize; i++)
    {
        records[i]=other.records[i];
    }
    ssize=other.ssize;
    capacity=other.capacity;
}
void DynArr::resizeArr(double k)
{
    Rec * temp= new Rec[ssize];
    for(int i=0;i<ssize;i++)
    {
        temp[i]=records[i];
    }
    //delete[] records; ?????????
    capacity=ssize*k;
    records=new Rec[capacity];
    for(int i=0;i<ssize;i++)
    {
        records[i]=temp[i];
    }
    delete[] temp;

}
void DynArr::add(const Rec& rec)
{
    if(ssize==0&& capacity==0)
    {
        records=new Rec[1];
        records[0]=rec;
        ssize++;capacity++;
    }
    else{
    if(capacity==ssize)
    try{
    resizeArr(2);
    }catch(std::bad_alloc &bae)
    {
        resizeArr(1.5);
    }
    records[ssize]=rec;
    ssize++;
    }
}
void DynArr::print()
{
    for(int i=0;i<ssize;i++)
    {
        records[i].print();
        std::cout<<std::endl;
    }
}
void DynArr::fillArr(char * fileName)
{
    std::ifstream ifs(fileName);
    Rec tempRec;
}
Rec& DynArr::operator[](unsigned indexx)
{
    if(indexx>=capacity)throw std::out_of_range("index out of range");
    return records[indexx];

}
void DynArr::swapArr(unsigned i, unsigned j)
{
    Rec t;
    t=records[i];
    records[i]=records[j];
    records[j]=t;
}
unsigned DynArr::getSize()
{
return ssize;
}
