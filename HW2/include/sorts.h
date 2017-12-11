//HEAPSORT, MERGESORT, COUNTINGSORT with linkedlist
//I use mergesort to sort subjects, because it is stable and this guarantee that equal elements will not be swapped(it is not expected to have lots of different subjects)
//I use counting sort to sort grades and age, becase it is 0(n) complexity, and the numbers we are sorting are consecutive (2,3,4,5,6) etc.

#include "DynArr.h"
class Sorts
{
private:
void mergeSort(DynArr &,int);// true is ASCENDING, false is DESCENDING
void heapSort(DynArr &, int);// true is ASCENDING, false is DESCENDING
void countingSortByGrade(DynArr&, int);//true is ASCENDING, false is DESCENDING
void countingSortByAge(DynArr&, int);//true is ASCENDING, false is DESCENDING
void mergeSortByDate(DynArr&, int);//true is ASCENDING, FALSE is DESCENDING

void mmergeByDate(DynArr&, DynArr&, DynArr&, int,int,int);
void mmerge(DynArr&,DynArr&,DynArr&,int, int, int);
void heapify(DynArr&, int, int);
bool biggerThan(const char*, const char*);

//ctor
private:
bool ascORdesc;
int field;// 1-name 2-age 3-subject 4-grade 5-date


public:
Sorts(const char *, const char*);
void DOsort(DynArr&);
};
