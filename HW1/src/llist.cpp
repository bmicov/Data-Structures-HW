#include "llist.h"
#include<iostream>

llist::llist()
{
    TAB a;
    a.setURL("about:blank");
    Node* b=new Node(nullptr,a,nullptr);
    head=b;
  //  tail=b;
    current=b;
}

void llist::addAfterCurr(TAB& t)
{
    Node *n=new Node(current->pNext, t, current);
        if(current->pNext!=nullptr)
        {
            current->pNext->pPrev=n;
            current->pNext=n;
        }else
        {
            current->pNext=n;
        }
    current=n;

}
void llist::moveBackCurr()
{
    if(current->pPrev!=nullptr)
    current= current->pPrev;
}
void llist::moveForwardCurr()
{
    if(current->pNext!=nullptr)
    current= current->pNext;
}
void llist::removeCurr()
{
    if(current->pNext!=nullptr)
    {
        if(current->pPrev==nullptr)//if we are removing first and it is not the only one
        {
            current->pNext->pPrev=current->pPrev;
            Node* phelp=current;
            current=current->pNext;
            head=current;
           delete phelp;
        }else{ //if we are removing in the middle
            current->pPrev->pNext=current->pNext;
            current->pNext->pPrev=current->pPrev;
            Node* phelp=current;
            current=current->pNext;
            delete phelp;
        }
    }
    else
        if(current->pNext==nullptr&&current->pPrev!=nullptr)// if we are removing last and it is not the only one
        {
        current->pPrev->pNext=current->pNext;
        Node* phelp=current;
        current=current->pPrev;
        delete phelp;
        }
        else // if there is only one elem
        {
            delete current;
            TAB a;
            a.setURL("about:blank");
            Node* b=new Node(nullptr,a,nullptr);
            head=b;
            //tail=b;
            current=b;
        }
}
void llist::print()
{
    Node * copyHEAD=head;
    while(copyHEAD!=nullptr)
    {
        if(copyHEAD==current)
        std::cout<<">";
        std:: cout<<copyHEAD->data;
        copyHEAD=copyHEAD->pNext;
    }
}
llist::~llist()
{
    while(head!=nullptr)
    {
       Node * help=head;
        head=head->pNext;
        delete help;
    }
}
TAB&llist::getCurrent()
{
    return (current->data);
}


