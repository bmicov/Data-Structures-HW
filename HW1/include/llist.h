#ifndef LLIST_H
#define LLIST_H
#include "TAB.h"


class llist
{
    public:
        llist();
        ~llist();
        TAB& getCurrent();
        void addAfterCurr(TAB &);
        void removeCurr();
        void moveForwardCurr();
        void moveBackCurr();
        void print();




    private:
    //void copyFrom(const llist& other);
    llist(const llist &);
    llist & operator=(const llist&);
    struct Node
    {
    Node * pNext;
    TAB data;
    Node * pPrev;
    Node(Node*n,TAB d,Node*p):pNext(n),data(d),pPrev(p){}
    ~Node(){}
    };
    Node* head;
    Node* current;

};

#endif // LLIST_H
