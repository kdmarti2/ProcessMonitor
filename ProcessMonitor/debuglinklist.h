#ifndef DEBUG_LINK_LIST_H
#define DEBUG_LINK_LIST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "linklist.h"


Iddnode* dbgCreateIddnode(unsigned ID);
dnode* dbgCreatednode();
Idsnode* dbgCreateIdsnode(unsigned ID);
snode* dbgCreateSnode();

Iddnode* SDL;
Idsnode* SSL;
dnode* DL;
snode* SL;

void debugSortDList(Iddnode** head);
void debugDList(dnode** head);
void debugSortSlist(Idsnode** head);
void debugSlist(snode** head);


void initDebugging();

void testSDL();
void testSSL();
void testDL();
void testSL();

#endif

