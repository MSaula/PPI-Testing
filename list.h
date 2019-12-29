#ifndef _LIST_H_
#define _LIST_H_

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include "person.h"

#define ERR_LIST_CREATE "ERROR: Creating list.\n"
#define ERR_LIST_DELETE "ERROR: Deleting element form list.\n"
#define ERR_LIST_GET "ERROR: Element not found.\n"
#define ERR_LIST_CREATE_NODE "ERROR: Creating auxiliary node for list.\n"
#define ERR_LIST_INSERT "ERROR: Inserting element in list.\n"

typedef struct node_t{
	Person person;
	struct node_t * seg;
	struct node_t * ant;
} Node;

typedef struct {
	Node * pri;
	Node * ult;
	Node * pdi;
} List;

List LIST_create (void); //Done
int LIST_add (List * l, Person p); //Done
Person LIST_getPerson (List l, char* name); //Done
Person LIST_getFirstPerson (List l); //
int LIST_deletePerson (List * l, char* name); //Done
int LIST_deleteFirstPerson (List * l); //Done
int LIST_isEmpty (List l); //Done
int LIST_size (List l); //Done
Person LIST_getOldestPerson (List l);
Person LIST_getYoungestPerson (List l);

//Private Helpers
int LIST_deleteElement(List *l);   //esborra un element de la llista
void LIST_goFirstNode(List *l);	//mou el pdi al inici de la llista
void LIST_next(List *l);	//avanca el pdi en una posicio de la lista
int LIST_destroy(List *l); //destrueix la llista i els seus elements

#endif
