#include "debuglinklist.h"

Iddnode* dbgCreateIddnode(unsigned ID)
{
	Iddnode* n = calloc(sizeof(Iddnode), 1);
	n->ID = ID;
	return n;
}
dnode* dbgCreatednode()
{
	dnode* n = calloc(sizeof(dnode), 1);
	return n;
}
Idsnode* dbgCreateIdsnode(unsigned ID)
{
	Idsnode* n = calloc(sizeof(Idsnode), 1);
	n->ID = ID;
	return n;
}
snode* dbgCreateSnode()
{
	snode* n = calloc(sizeof(snode), 1);
	return n;
}

void debugSortDList(Iddnode** head)
{
	Iddnode* cpnt = *head;
	while (cpnt)
	{
		printf("%p <-(%p:%u)-> %p\n", cpnt->prev, cpnt, cpnt->ID, cpnt->next);
		cpnt = cpnt->next;
	}
}
void debugDList(dnode** head)
{
	dnode* cpnt = *head;
	while (cpnt)
	{
		printf("%p <-(%p)-> %p\n", cpnt->prev, cpnt, cpnt->next);
		cpnt = cpnt->next;
	}
}
void debugSortSlist(Idsnode** head)
{
	Idsnode* cpnt = *head;
	while (cpnt)
	{
		printf("(%p:%u)->%p\n", cpnt, cpnt->ID, cpnt->next);
		cpnt = cpnt->next;
	}
}
void debugSlist(snode** head) {
	snode* cpnt = *head;
	while (cpnt)
	{
		printf("(%p)->%p\n", cpnt, cpnt->next);
		cpnt = cpnt->next;
	}
}

void initDebugging()
{
	int option = -1;
	do
	{
		printf("debugging linked list\n");
		printf("testSDL: 0\ntestSSL: 1\ntestDL: 2\ntestSL 3\nquit: -1\n");
		option = -1;
		printf("Enter 0-3: ");
		scanf_s("%d", &option);
		printf("\n");
		switch (option)
		{
		case 0:
			testSDL();
			break;
		case 1:
			testSSL();
			break;
		case 2:
			testDL();
			break;
		case 3:
			testSL();
			break;
		default:
			break;
		} 
	} while (option > 0);
}
void testSDL() {
	printf("Sorted Doubled linked list tests\n");
	printf(
		"Add  Node: a X\nDel  Node: d X\nFind Node: f X\n"
	);
	Iddnode* head=0;
	int res = 0;
	char action = 0;
	unsigned int id = 0;

	do {
		Iddnode* node = 0;
		action = 0;
		id = 0;
		res = scanf_s("%c %u", &action,1,&id);
		switch (action) {
		case 'a':
			node = dbgCreateIddnode(id);
			addSortDlist(&head, node);
			debugSortDList(&head);
			printf("------------------------------------------\n");
			break;
		case 'd':
			node = removeSortDlist(&head, id);
			if (node)
				free(node);
			debugSortDList(&head);
			printf("------------------------------------------\n");
			break;
		case 'f':
			node = findSortDlist(&head, id);
			if (node)
			{
				printf("%p <- (%p:%u) -> %p\n", node->prev, node, node->ID, node->next);
				debugSortDList(&head);
			}
			else {
				printf("not found!\n");
			}
			printf("------------------------------------------\n");
			break;
		case 'q':
			res = -1;
			break;
		}
	} while (res>0);
	printf("leaving test\n");
}
void testSSL() {
	printf("Sorted Single linked list test\n");
	printf(
		"Add  Node: a X\nDel  Node: d X\nFind Node: f X\n"
	);
	Idsnode* head = 0;
	char action = 0;
	unsigned int id = 0;
	int res = 0;
	do {
		Idsnode* node = 0;
		action = 0;
		id = 0;
		res = scanf_s("%c %u", &action,1, &id);
		switch (action) {
		case 'a':
			node = dbgCreateIdsnode(id);
			addSortSlist(&head, node);
			debugSortSlist(&head);
			printf("-------------------------------------\n");
			break;
		case 'd':
			node = removeSortSlist(&head, id);
			if (node)
				free(node);

			debugSortSlist(&head);
			printf("--------------------------------------\n");
			break;
		case 'f':
			node = findSortSlist(&head, id);
			if (node)
			{
				printf("(%p:%d) -> %p\n", node, node->ID, node->next);
			}
			else {
				printf("Not Found\n");
			}
			debugSortSlist(&head);
			printf("---------------------------------------\n");
			break;
		case 'q':
			res = -1;
			break;
		}
	} while (res>0);
}
void testDL() {
	printf("NonSorted double linked list test\n");
	printf(
		"Add  Node: a\nDel  Node: d X\n"
	);
	dnode* head = 0;
	char action = 0;
	int res = 0;
	void* p = 0;
	do {
		dnode* node = 0;
		res = scanf_s("%c", &action, 1);
		switch (action) {
		case 'a':
			node = dbgCreatednode();
			addFirstDlist(&head, node);
			debugDList(&head);
			printf("---------------------------------------\n");
			break;
		case 'd':
			scanf_s("%p", &p);
			node = removeDlist(&head, (dnode*)p);
			if (node)
				free(node);
			debugDList(&head);
			printf("----------------------------------------\n");
			break;
		case 'q':
			res = 0;
			break;
		}
	} while (res > 0);
	return;
}
void testSL() {
	printf("NonSorted linked list test\n");
	printf(
		"Add  Node: a\nDel  Node: d X\n"
	);
	snode* head = 0;
	char action = 0;
	int res = 0;
	void* p = 0;
	do {
		snode* node = 0;
		res = scanf_s("%c", &action, 1);
		switch (action) {
		case 'a':
			node = dbgCreatednode();
			addFirstSlist(&head, node);
			debugSlist(&head);
			printf("-----------------------------------\n");
			break;
		case 'd':
			scanf_s("%p", &p);
			node = removeSlist(&head, (dnode*)p);
			if (node)
				free(node);

			debugSlist(&head);
			printf("-------------------------------------\n");
			break;
		case 'q':
			res = 0;
			break;
		}
	} while (res > 0);
	return;
	return;
}