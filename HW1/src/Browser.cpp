#include "Browser.h"


Browser::Browser()
{
  l = new llist;
}

Browser::~Browser()
{
    delete l;
}
void Browser::GO(const char*url)
{
    l->getCurrent().setURL(url);
    l->getCurrent().refresh();
}

void Browser::INSERT(const char*url)
{
    TAB t;
    t.setURL(url);
    l->addAfterCurr(t);
}

void Browser::BACK()
{
    l->moveBackCurr();
}

void Browser::FORWARDD()
{
    l->moveForwardCurr();
}

void Browser::REMOVE()
{
    l->removeCurr();
}

void Browser::PRINT()
{
    l->print();
}


