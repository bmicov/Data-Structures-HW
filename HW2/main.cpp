#include <iostream>
#include "DynArr.h"
#include "Rec.h"
#include <fstream>
#include <cstring>
#include "sorts.h"
#include "linkedlist.h"

using namespace std;
int main(int argc, char *argv[])
{
DynArr myArr;
ifstream ifs("file.csv");
string firstLine;
getline(ifs,firstLine);

Rec a;



try{
while(ifs>>a)
myArr.add(a);
Sorts firstSort("date","asc");
firstSort.DOsort(myArr);
}catch(int i){
    if(i==1) {cerr<<"Error: Invalid date";return -1;}
    if(i==2) {cerr<<"Error: asc or desc";return -1;}
    if(i==3) {cerr<<"Error: No such field";return -1;}
}
myArr.print();


}
