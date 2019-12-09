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
<<<<<<< HEAD

=======
	//Ves inici.
	l->pdi = l->pri->seg;
	//Borra el node.
	LIST_esborrar(l);
>>>>>>> b59ec45102ee86b12c85dee239722550b73cb1a7
}

/***********************************************
*
* @Finalitat: Esborrem un element de Llista
* @Parametres: punter a la Llista bidireccional per pasarla per referencia
* @Retorn: -
*
************************************************/
int LIST_deletePerson (List * l, char* name){
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
				free(n->client.name);
				free(n);

				break;
			} else {
				n = n->seg;
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
		if (!strcmp(PERSON_getName(l->pdi->person), name) return 1;
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
		return NULL;
	} else {
		return l.pdi->person;
	}
}
/***********************************************
*
* @Finalitat: Avançar el punter pdi de la Llista
* @Parametres: punter a la Llista bidireccional per pasarla per referencia
* @Retorn: -
*
************************************************/
void LIST_avanca (List * l){
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
void LIST_vesInici (List * l){
	l -> pdi = l -> pri -> seg;
}
/***********************************************
*
* @Finalitat: Retrocedeix el punter pdi en una posicio de la llista
* @Parametres: punter a la Llista bidireccional per pasarla per referencia
* @Retorn: -
*
************************************************/
void LIST_retrocedeix (List * l){
	if(l -> pdi != l -> pri){
		l -> pdi = l -> pdi -> ant;
	}
}
/***********************************************
*
* @Finalitat: Ens porta al Inici de la Llista
* @Parametres: punter a la Llista bidireccional per pasarla per referencia
* @Retorn: Flag que ens diu si ens trobem al inici o no
*
************************************************/
int LIST_inici (List l){
	return l.pdi == l.pri;
}
/***********************************************
*
* @Finalitat: Ens porta al final de la Llista
* @Parametres: punter a la Llista bidireccional per pasarla per referencia
* @Retorn: -
*
************************************************/
void LIST_vesFinal (List * l){
	l -> pdi = l -> ult -> ant;
}
/***********************************************
*
* @Finalitat: Introdueix un client dins de la llista al principi
* @Parametres: punter a la Llista bidireccional per pasarla per referencia, Client c que s'inserira a la Llista
* @Retorn: -
*
************************************************/
void LIST_inserirPrincipi (List * l, Client c){
	Node* n = NULL;
	LIST_vesInici(l);
	if(l -> pdi != l -> pri){

		n = (Node*)malloc(sizeof(Node));

		if(n == NULL){
			write(1, ERR_LIST_CREATE_NODE, strlen(ERR_LIST_CREATE_NODE));
		}
		else{
			n -> client = c;
			n -> seg = l -> pdi;
			n -> ant = l -> pdi -> ant;
			l -> pdi -> ant -> seg = n;
			l -> pdi -> ant = n;
		}
	}
	else{
		write(1, ERR_LIST_INSERT, strlen(ERR_LIST_INSERT));
	}
}
/***********************************************
*
* @Finalitat: Introdueix El client c dins de la llista al final
* @Parametres: punter a la Llista bidireccional per pasarla per referencia, client c que s'inserira a la Llista
* @Retorn: -
*
************************************************/
void LIST_inserirFinal (List * l, Client c){
	Node* n = NULL;

	if (l -> pdi == l -> ult){
		write(1, ERR_LIST_INSERT, strlen(ERR_LIST_INSERT));
	}
	else{
		n = (Node*)malloc(sizeof(Node));
		if (n == NULL){
			write(1, ERR_LIST_CREATE_NODE, strlen(ERR_LIST_CREATE_NODE));
		}
		else{
			n -> client = c;
			n -> seg = l -> pdi -> seg;
			n -> ant = l -> pdi;
			l -> pdi -> seg -> ant = n;
			l -> pdi -> seg = n;
		}
	}
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
* @Retorn: -
*
************************************************/
void LIST_esborrar(List * l){
	Node* n;

	if( l -> pdi == l -> pri || l -> pri == l -> ult){
		write(1, ERR_LIST_DELETE, strlen(ERR_LIST_DELETE));
	}
	else{
		l -> pdi -> ant -> seg = l -> pdi -> seg;
		l -> pdi -> seg -> ant = l -> pdi -> ant;
		n = l -> pdi;
		l -> pdi = l -> pdi -> seg;
		free(n->person.name);
		free(n);
	}
}

void LIST_destrueix (List * l){
	LIST_vesInici(l);
	while(!LIST_esBuida(*l)){
		LIST_esborrar(l);
	}
	free(l -> pri);
	free(l -> ult);
	l -> pri = NULL;
	l -> ult = NULL;
}

/***********************************************
*
* @Finalitat:Mostrarnos quants elements conté la nostra llista
* @Parametres: Llista que conte varies fitxes
* @Retorn: enter que ens diu el nombre d'elements de la llista
*
************************************************/
int LIST_quants(List l){
	int i = 0;

	LIST_vesInici(&l);
	while(!LIST_fi(l)){
		LIST_avanca(&l);
		i++;
	}
	return i;
}
