#ifndef _LIST_H_
#define _LIST_H_

#include "person.h"
#include <stdio.h>
#include <stdlib.h>

#define ERR_LIST_CREATE "ERROR: Creating list.\n"
#define ERR_LIST_DELETE "ERROR: Deleting element form list.\n"
#define ERR_LIST_CREATE_NODE "ERROR: Creating auxiliary node for list.\n"
#define ERR_LIST_INSERT "ERROR: Inserting element in list.\n"

typedef struct _Node {
	Person person;
	struct node_t * seg;
	struct node_t * ant;
} Node;

typedef struct {
	Node * pri;
	Node * ult;
	Node * pdi;
    int size;
} List;

List LIST_create (void); //Done
int LIST_add (List * l, Person p); //
Person LIST_getPerson (List l, char* name);
Person LIST_getFirstPerson (List l);
int LIST_deletePerson (List * l, char* name); //Done
int LIST_deleteFirstPerson (List * l); //
int LIST_isEmpty (List l);
int LIST_isFull (List l);
int LIST_size (List l);
Person LIST_getOldestPerson (List l);
Person LIST_getYoungestPerson (List l);

////////////////////////////////////////////////////////////////////////////////////////////////////

void LIST_inserirPrincipi(List * l, Client client);	//introdueix un element al principi de la llista
void LIST_inserirFinal(List * l, Client client);	//introdueix un element al final de la llista
void LIST_consulta(List l, Client **client);			//retorna per referencia un element de la llista
void LIST_esborrar(List * l);					//esborra un element de la llista
void LIST_vesInici(List * l);					//mou el pdi al inici de la llista
void LIST_avanca(List * l);					//avanca el pdi en una posicio de la lista
int LIST_fi (List l);							//ens mostra si ens trobem al final de la llista
int LIST_esBuida (List l);					//ens mostra si tenim una llista sense elements
void LIST_vesFinal (List * l);				//mou el pdi al final de la llista
void LIST_retrocedeix (List * l);				//retrocedeix el pdi en una posicio de la llista
int LIST_inici (List l);						//ens mostra si ens trobem al inici de la llista
int LIST_quants(List l);						//ens retorna el nombre d'elements que conte la llista
void LIST_destrueix (List * l);				//destrueix la llista i els seus elements

#endif
