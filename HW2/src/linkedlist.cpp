#include "linkedlist.h"
#include<iostream>

using namespace std;
linkedlist::linkedlist()
{
    pHead=nullptr;
    pTail=nullptr;
    ssize=0;
}
linkedlist::linkedlist(const linkedlist& other)
{
    copyFrom(other);
}
linkedlist & linkedlist::operator=(const linkedlist & other)
{
    if(this!=&other)
    {

            copyFrom(other);
    }
    return *this;
}
linkedlist::linkedlist(Rec &x)
{
    pHead=new Node(x,nullptr);
    pTail=pHead;
    ssize=1;
}
linkedlist::~linkedlist()
{
    //dtor
    while(pHead!=nullptr)
    {
    Node * phelpHead=pHead;
    pHead=pHead->pNext;
    delete phelpHead;
    }
}
void linkedlist::addLast(Rec & d)
{
    Node* phelp=new Node(d,nullptr);

    if(ssize){
    pTail->pNext=phelp;
    pTail=phelp;
    ssize++;
    }else{
    pHead=phelp;
    pTail=phelp;
    ssize++;
    }
}
void linkedlist::popFirst(Rec & r)
{ //when we call this function we have to be sure that linkedlist is not empty
    r = pHead->d;
    pHead=pHead->pNext;
    ssize--;
}


void linkedlist::print()
{
    Node * phelpHead=pHead;
    while(phelpHead!=nullptr)
    {
        phelpHead->d.print();
        phelpHead=phelpHead->pNext;
    }
}

bool linkedlist::isEmpty()
{
return ssize==0;
}
void linkedlist::copyFrom(const linkedlist& other)
{
    Node * phelpHead=other.pHead;
    while(phelpHead!=nullptr)
    {
        this->addLast(phelpHead->d);
        phelpHead=phelpHead->pNext;
    }
}
