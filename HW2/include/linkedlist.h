#ifndef LINKEDLIST_H
#define LINKEDLIST_H
#include<cstring>
#include<fstream>
#include "Rec.h"
using namespace std;
class linkedlist
{

private:
    struct Node
    {
        Node(const Rec r, Node* pN) : pNext(pN)
        {
           d=r;
        }


    Rec d;
    Node* pNext;
    };

private:
    Node * pHead;
    Node * pTail;
    int ssize;
    public:
        linkedlist();
        linkedlist(Rec&);//with only one element

        ~linkedlist();



public:
    void addLast(Rec &);
    void popFirst(Rec &);
    void print();
    bool isEmpty();
    linkedlist(const linkedlist &);
    linkedlist & operator=(const linkedlist &);
    void copyFrom(const linkedlist &);
private:


};


#endif // LINKEDLIST_H
