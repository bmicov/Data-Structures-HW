#include <iostream>
#include <cstring>
#include "Browser.h"
using namespace std;
void test(Browser &b)
{
    for(int i=0;i<=10;i++)
    {
        b.INSERT("asd");
        b.PRINT();
        cout<<endl;
        b.BACK();
        b.PRINT();cout<<endl;
    }
    b.PRINT();
}
int main()
{

    Browser b;
    char command[200];
    char * ptr=command;
    do{
    cin.getline(command, 200);
    if(command[0]=='$' && command[1]==' ')
    {
        if(command[2]=='G' && command[3]=='O' && command[4]==' ')
        {
        ptr+=5;
        b.GO(ptr);
        ptr-=5;
        }else if(command[2]=='I' && command[3]=='N' && command[4]=='S' && command[5]=='E' && command[6]=='R' && command[7]=='T' && command[8]==' ')
                {
                ptr+=9;
                b.INSERT(ptr);
                ptr-=9;
                }
                else if(command[2]=='F' && command[3]=='O' && command[4]=='R' && command[5]=='W' && command[6]=='A' && command[7]=='R' && command[8]=='D' &&command[9]=='\0')
                        {
                        b.FORWARDD();}
                        else if(command[2]=='B' && command[3]=='A' && command[4]=='C' && command[5]=='K'&&command[6]=='\0')
                                {b.BACK();}
                                else if(command[2]=='R' && command[3]=='E' && command[4]=='M' && command[5]=='O' && command[6]=='V' && command[7]=='E'&&command[8]=='\0')
                                    {b.REMOVE();}
                                    else if(command[2]=='P' && command[3]=='R' && command[4]=='I' && command[5]=='N' && command[6]=='T'&&command[7]=='\0')
                                            {b.PRINT();}
    }
    }while(strcmp(command,"stop"));




    return 0;
}
