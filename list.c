#include "list.h"

/***********************************************
*
* @Finalitat: Creem la Llista amb els nodes fantasme
* @Parametres: -
* @Retorn: El tipus List que utilitzem com a estructura de dades lineals.
*
************************************************/

List LIST_create(){
	List l;

	l.pri = (Node*)malloc(sizeof(Node));
	if (l.pri == NULL) write(1, ERR_LIST_CREATE, strlen(ERR_LIST_CREATE));

	else {
		l.ult = (Node*)malloc(sizeof(Node));
		if(l.ult == NULL){
			free(l.pri);
			write(1, ERR_LIST_CREATE, strlen(ERR_LIST_CREATE));
		}
		else{
			l.pdi = l.pri;
			l.pri -> seg = l.ult;
			l.pri -> ant = NULL;
			l.ult -> seg = NULL;
			l.ult -> ant = l.pri;
		}
	}
	return l;
}


int LIST_deleteFirstPerson(List *l)
{
	//Ves inici.
	l->pdi = l->pri->seg;
	//Borra el node.
	return LIST_deleteElement(l);
}

	/***********************************************
*
* @Finalitat: Esborrem un element de Llista
* @Parametres: punter a la Llista bidireccional per pasarla per referencia
* @Retorn: -
*
************************************************/
int LIST_deletePerson(List *l, char *name)
{
	Node* n;
	int trobat = 0;

	l->pdi = l->pri->seg;

	if (l->pri == l->ult) write(1, ERR_LIST_DELETE, strlen(ERR_LIST_DELETE));
	else {
		while (l->pdi != l->ult) {
			if (!strcmp(name, PERSON_getName(l->pdi->person))){
				trobat = 1;

				l -> pdi -> ant -> seg = l -> pdi -> seg;
				l -> pdi -> seg -> ant = l -> pdi -> ant;
				n = l -> pdi;
				l -> pdi = l -> pdi -> seg;
				free(n->person.name);
				free(n);

				break;
			} else {
				l->pdi = l->pdi->seg;
			}
		}
	}

	if (!trobat) {
		write(1, ERR_LIST_DELETE, strlen(ERR_LIST_DELETE));
		return -1;
	} else return 1;
}

// Coloca el pdi a la primera persona que coincideix amb el nom donat
// Si no troba la persona retorna -1, sino retorna 1
int LIST_setPdi(List *l, char* name) {
	l->pdi = l->pri->seg;

	while (l->pdi != l->ult) {
		if (!strcmp(PERSON_getName(l->pdi->person), name)) return 1;
		l->pdi = l->pdi->seg;
	}

	return -1;
}

/***********************************************
*
* @Finalitat: Es fa servir per consular quin client es guarda en una posicio de la Llista
* @Parametres: Llista Bidireccional y un client que contindrá l'element consultat
* @Retorn: -
*
************************************************/
Person LIST_getPerson (List l, char* name){
	if (LIST_setPdi(&l, name) == -1) {
		write(1, ERR_LIST_GET, strlen(ERR_LIST_GET));
		return PERSON_undefined();
	} else {
		return l.pdi->person;
	}
}

Person LIST_getFirstPerson (List l){
	return l.pri->seg->person;
}

/***********************************************
*
* @Finalitat: Avançar el punter pdi de la Llista
* @Parametres: punter a la Llista bidireccional per pasarla per referencia
* @Retorn: -
*
************************************************/
void LIST_next (List * l){
	if (l -> pdi != l -> ult){
		l -> pdi = l -> pdi -> seg;
	}
}
/***********************************************
*
* @Finalitat: Ens avisa si ens trobem al final de la llista
* @Parametres: punter a la Llista bidireccional per pasarla per referencia
* @Retorn: flag que ens diu si ens trobem al final o no
*
************************************************/
int LIST_fi (List l){
	return l.pdi == l.ult;
}
/***********************************************
*
* @Finalitat: Ens porta al Inici de la Llista
* @Parametres: punter a la Llista bidireccional per pasarla per referencia
* @Retorn: -
*
************************************************/
void LIST_goFirstNode (List * l){
	l -> pdi = l -> pri -> seg;
}

/***********************************************
*
* @Finalitat: Ens diu si la nostra llista esta buida
* @Parametres: Llista bidireccional en la que guardem varies fixes
* @Retorn: enter que ens diu si hi ha alguna fitxa dins de la llista
*
************************************************/
int LIST_isEmpty (List l){
	return l.pri -> seg == l.ult;
}


/***********************************************
*
* @Finalitat: Destruir tota la llista y els seus elements
* @Parametres: punter a la Llista bidireccional per pasarla per referencia y posar els seus punters a NULL
* @Retorn: 0 si hi ha error.
*		   1 si tot esta bé
*
************************************************/
int LIST_deleteElement(List * l) {
	Node* n;

	if( l -> pdi == l -> pri || l -> pri == l -> ult){
		write(1, ERR_LIST_DELETE, strlen(ERR_LIST_DELETE));
		return 0;
	}
	else{
		l -> pdi -> ant -> seg = l -> pdi -> seg;
		l -> pdi -> seg -> ant = l -> pdi -> ant;
		n = l -> pdi;
		l -> pdi = l -> pdi -> seg;
		free(n->person.name);
		free(n);
		return 1;
	}
}

int LIST_destroy (List * l) {
	LIST_goFirstNode(l);
	int status = 1;
	while(!LIST_isEmpty(*l)){
		status &= LIST_deleteElement(l);
	}
	free(l -> pri);
	free(l -> ult);
	l -> pri = NULL;
	l -> ult = NULL;
	return status;
}

/***********************************************
*
* @Finalitat:Mostrarnos quants elements conté la nostra llista
* @Parametres: Llista que conte varies fitxes
* @Retorn: enter que ens diu el nombre d'elements de la llista
*
************************************************/
int LIST_size(List l) {
	int i = 0;

	LIST_goFirstNode(&l);
	while (l.pdi != l.ult)
		{
			LIST_next(&l);
			i++;
	}
	return i;
}

Person LIST_getOldestPerson(List l) {
	Person p;
	LIST_goFirstNode(&l);

	if (LIST_isEmpty(l)) return PERSON_undefined();

	l.pdi = l.pri -> seg;
	p = l.pdi->person;

	do {
		p = (PERSON_getAge(p) < PERSON_getAge(l.pdi->person)) ? l.pdi->person : p;
		LIST_next(&l);
	} while (!LIST_fi(l));

	return p;
}

Person LIST_getYoungestPerson(List l) {
	Person p;
	LIST_goFirstNode(&l);

	if (LIST_isEmpty(l)) return PERSON_undefined();

	l.pdi = l.pri -> seg;
	p = l.pdi->person;

	do {
		p = (PERSON_getAge(p) > PERSON_getAge(l.pdi->person)) ? l.pdi->person : p;
		LIST_next(&l);
	} while (!LIST_fi(l));

	return p;
}

int LIST_add (List* l, Person p){
	Node* n = NULL;

	l -> pdi = l -> pri -> seg;
	if(l -> pdi != l -> pri){

		n = (Node*)malloc(sizeof(Node));

		if(n == NULL){
			write(1, ERR_LIST_CREATE_NODE, strlen(ERR_LIST_CREATE_NODE));
		}
		else{
			n -> person = p;
			n -> seg = l -> pdi;
			n -> ant = l -> pdi -> ant;
			l -> pdi -> ant -> seg = n;
			l -> pdi -> ant = n;
		}
	}
	else{
		write(1, ERR_LIST_INSERT, strlen(ERR_LIST_INSERT));
	}
	return 1;
}
