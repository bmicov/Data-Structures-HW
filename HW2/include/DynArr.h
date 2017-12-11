#ifndef DYNARR_H
#define DYNARR_H
#include "Rec.h"

class DynArr
{
    public:
        DynArr();
        DynArr(unsigned k);
        DynArr(const DynArr & other);
        DynArr & operator=(const DynArr & other);
        void add(const Rec& rec);
        void resizeArr(double k);//k=2
        void print();
        void fillArr(char * fileName);
        void swapArr(unsigned i, unsigned j);
        Rec& operator[](unsigned i);
        unsigned getSize();
        ~DynArr();

    private:
    Rec * records;
    unsigned ssize;
    unsigned capacity;
    void copyFrom(const DynArr& other);

};

#endif // DYNARR_H
