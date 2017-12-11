#include<cstring>
#include "DynArr.h"
#include "functions.h"
#include "linkedlist.h"
#include "sorts.h"
bool Sorts:: biggerThan(const char * first, const char * second)
{
    int len = 0;
    if(strlen(first)>=strlen(second)) len=strlen(second);
    else len=strlen(first);
    for(int i=0;i<len;i++)
    {
        if(first[i]<second[i]) return false;
        if(first[i]>second[i])return true;
    }
    return false;
}

//ctor
Sorts::Sorts(const char* f, const char* aORd)
{
        if(!strcmp(aORd,"asc")) ascORdesc=true;
        else
            if(!strcmp(aORd,"desc")) ascORdesc=false;
            else throw 2;

    field=0;
    if(!strcmp(f,"name")) field=1;
    if(!strcmp(f,"age")) field=2;
    if(!strcmp(f,"subject")) field=3;
    if(!strcmp(f,"grade")) field=4;
    if(!strcmp(f, "date")) field=5;
    if(!field) throw 3;
}
void Sorts:: DOsort(DynArr & arr)
{
    switch(field)
    {
        case 1: heapSort(arr,arr.getSize());break;//case for name
        case 2: countingSortByAge(arr,arr.getSize());break; //case for age
        case 3: ascORdesc=(!ascORdesc); mergeSort(arr,arr.getSize());break;//sort for subject// sorry// changing ascORdesc because for heapSort the logic is opposite
        case 4: countingSortByGrade(arr,arr.getSize());break; //case for grade
        case 5: ascORdesc=(!ascORdesc); mergeSortByDate(arr,arr.getSize());break;
    }
}
void Sorts:: mmerge(DynArr &a, DynArr &left, DynArr &right,int leftsize, int rightsize, int arrsize)
{
    int i=0;
    int r=0;
    int k=0;
    while(i<leftsize && r<rightsize)
    {
        //if(left[i]>right[r])
        if( (biggerThan(left[i].getSubject(),right[r].getSubject()) && ascORdesc ) || // bi implicatoin <=>
            (!biggerThan(left[i].getSubject(),right[r].getSubject()) && !ascORdesc))// from this depends whether it is desc or asc
        {
            a[k]=left[i];
            i++;k++;
        }
        else//if(right[r]<=left[i])
        {
            a[k]=right[r];
            r++;k++;
        }
        }

        while(i<leftsize)
        {
            a[k]=left[i]; i++;k++;
        }
        while(r<rightsize)
        {
            a[k]=right[r];r++;k++;
        }
    }
void Sorts:: mergeSort(DynArr &a,int arrsize)
{
    if(arrsize<2) return;

    int mid=arrsize/2;
    int leftsize=(arrsize)/2;
    int rightsize=(arrsize+1)/2;

    DynArr left(leftsize);
    DynArr right(rightsize);
    for(int i=0;i<mid;i++)
    {
        left[i]=a[i];
    }
    for(int i=mid;i<arrsize;i++)
    {
        right[i-mid]=a[i];
    }
    mergeSort(left,leftsize);
    mergeSort(right,rightsize);
    mmerge(a,left,right, leftsize, rightsize, arrsize);
}

void Sorts:: heapify(DynArr & arr, int n, int i)
{

    int largest = i;
    int l = 2*i + 1;
    int r = 2*i + 2;
    //find the largest between right child, left child and parent
    if (l < n && (
                (biggerThan(arr[l].getName(),arr[largest].getName()) && ascORdesc ) || //bi implication max heap or min heap
                (!biggerThan(arr[l].getName(),arr[largest].getName()) && !ascORdesc)))//from this line depends whether it is desc or asc
    largest = l;

    if (r < n && (
                (biggerThan(arr[r].getName(),arr[largest].getName()) && ascORdesc ) || //bi implication
                (!biggerThan(arr[r].getName(),arr[largest].getName()) && !ascORdesc)))//from this line depends whether it is desc or asc
    largest = r;

    if (largest != i)// if the largest is not in its position
    {
     Rec temp = arr[i];
     arr[i]=arr[largest];//swap
     arr[largest]=temp;
     heapify(arr, n, largest); //heapify down after we disordered the tree
   }

}


void Sorts:: heapSort(DynArr &arr ,int n)
{
    for(int i=n/2-1;i>=0;i--)//heapify for each parent
        heapify(arr,n,i);
    for(int i=n-1; i>=0; i--)
    {
        Rec temp = arr[i];
        arr[i]=arr[0];//swap the biggest and the last
        arr[0]=temp;
        heapify(arr,i, 0);//heapify after swap
    }
}

void Sorts:: countingSortByGrade(DynArr & arr, int n)// this is some kind of bucket sort, but we know that grades ar integers
{
    int maxGrade=0;
    for(int i=0;i<n;i++)
        if(arr[i].getGrade()>maxGrade)// we need max to make array of linked lists
            maxGrade=arr[i].getGrade();
    linkedlist * listArray = new linkedlist[maxGrade+1];
    for(int i=0;i<n;i++)
        listArray[arr[i].getGrade()].addLast(arr[i]);

       int helpCounter=0;
        Rec helpRecord;

    if(ascORdesc)
        for(int i=0; i<=maxGrade;i++)
            while(!listArray[i].isEmpty())              //looks like it is with greater compl. than N, but it is not.
            {                                           // K grades * M records for each grade = N
                listArray[i].popFirst(helpRecord); // pop from list for grade i
                arr[helpCounter]=helpRecord;
                helpCounter++;                // add to original array
            }
    else
         for(int i=maxGrade; i>=0;i--)
            while(!listArray[i].isEmpty())              //looks like it is with greater compl. than N, but it is not.
            {                                           // K grades * M records for each grade = N
                listArray[i].popFirst(helpRecord); // pop from list for grade i
                arr[helpCounter]=helpRecord;
                helpCounter++;                // add to original array
            }
delete[] listArray;
}
void Sorts:: countingSortByAge(DynArr & arr, int n)// this is some kind of bucket sort, but we know that grades ar integers
{
    int maxAge=0;
    for(int i=0;i<n;i++)
        if(arr[i].getAge()>maxAge)// we need max to make array of linked lists
            maxAge=arr[i].getAge();
    linkedlist * listArray = new linkedlist[maxAge+1];
    for(int i=0;i<n;i++)
        listArray[arr[i].getAge()].addLast(arr[i]);

       int helpCounter=0;
        Rec helpRecord;

    if(ascORdesc)
        for(int i=0; i<=maxAge;i++)
            while(!listArray[i].isEmpty())              //looks like it is with greater compl. than N, but it is not.
            {                                           // K different ages * M records for each grade = N
                listArray[i].popFirst(helpRecord); // pop from list for grade i
                arr[helpCounter]=helpRecord;
                helpCounter++;                // add to original array
            }
    else
         for(int i=maxAge; i>=0;i--)
            while(!listArray[i].isEmpty())              //looks like it is with greater compl. than N, but it is not.
            {                                           // K different ages * M records for each grade = N
                listArray[i].popFirst(helpRecord); // pop from list for grade i
                arr[helpCounter]=helpRecord;
                helpCounter++;                // add to original array
            }
delete[] listArray;
}

void Sorts:: mmergeByDate(DynArr &a, DynArr &left, DynArr &right,int leftsize, int rightsize, int arrsize)
{
    int i=0;
    int r=0;
    int k=0;
    while(i<leftsize && r<rightsize)
    {
        //if(left[i]>right[r])
        if( ((right[r].getDate() < left[i].getDate()) && ascORdesc ) || // bi implicatoin <=>
            (!(right[r].getDate() < left[i].getDate()) && !ascORdesc))// from this depends whether it is desc or asc
        {
            a[k]=left[i];
            i++;k++;
        }
        else//if(right[r]<=left[i])
        {
            a[k]=right[r];
            r++;k++;
        }
        }

        while(i<leftsize)
        {
            a[k]=left[i]; i++;k++;
        }
        while(r<rightsize)
        {
            a[k]=right[r];r++;k++;
        }
    }
void Sorts:: mergeSortByDate(DynArr &a,int arrsize)
{
    if(arrsize<2) return;

    int mid=arrsize/2;
    int leftsize=(arrsize)/2;
    int rightsize=(arrsize+1)/2;

    DynArr left(leftsize);
    DynArr right(rightsize);
    for(int i=0;i<mid;i++)
    {
        left[i]=a[i];
    }
    for(int i=mid;i<arrsize;i++)
    {
        right[i-mid]=a[i];
    }
    mergeSortByDate(left,leftsize);
    mergeSortByDate(right,rightsize);
    mmergeByDate(a,left,right, leftsize, rightsize, arrsize);
}
