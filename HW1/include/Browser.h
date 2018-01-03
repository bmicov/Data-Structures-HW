#ifndef BROWSER_H
#define BROWSER_H


#include "llist.h"


class Browser
{
    public:
        Browser();
        ~Browser();
    //interface

    void GO(const char *);
    void INSERT(const char *);
    void BACK();
    void FORWARDD();
    void REMOVE();
    void PRINT();



    private:
    Browser(const Browser&);
    Browser & operator=(const Browser&);
    llist *l;
    //struct of tabs

};
#endif // BROWSER_H
