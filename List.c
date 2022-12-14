/*PROVA PRELIMINARE ESERCIZI LISTE*/

/*STRUTTURA LISTE*/
#include <stdio.h>
#include <stdlib.h>
typedef struct elist {
	int info;
	struct elist* next;
} elist;

typedef elist* plist;

/*==================================================*/
/*All'inizio di ogni esercizio vi è una funzione che crea una lista per testare le funzioni*/

/*Funzione che calcola valore massimo di una lista*/
plist costruisci_lista_massimo() {
	plist p = NULL;
	int L[] = {2, 3, 10, 5, 8};
	for(int i=0; i<5; i++) {
		plist temp = (plist) malloc(sizeof(elist));
		temp->info = L[i];
		temp->next = p;
		p = temp;
	}
	return p;
}

int max_lista(plist p){
    if(p==NULL) return 0;
    int max = p->info;
    while(p!=NULL){
        if(p->info> max){
            max = p->info;
        }
        p = p->next;
    }
    return max;
}

/*==================================================*/

/*funzione che controlla se lista ordinata crescente*/
plist costruisci_lista_ordinata() {
	plist p = NULL;
	int L[] = {2, 3, 4, 5, 6};
	for(int i=0; i<5; i++) {
		plist temp = (plist) malloc(sizeof(elist));
		temp->info = L[i];
		temp->next = p;
		p = temp;
	}
	return p;
}

plist costruisci_lista_non_ordinata() {
	plist p = NULL;
	int L[] = {2, 3, 4, 7, 5};
	for(int i=0; i<5; i++) {
		plist temp = (plist) malloc(sizeof(elist));
		temp->info = L[i];
		temp->next = p;
		p = temp;
	}
	return p;
}

int lista_verificata(plist l1, plist l2){
	if(l2 == NULL) return 0;
	int verificato = 1;
	while(l2!=NULL && verificato == 1){
		if(l1->info >= l2->info){
			verificato = 0;
		}
		l1 = l1->next;
		l2 = l2->next;
	}
	return verificato;
}

int is_crescente(plist p) {
	if(p == NULL)
		return 0;
	if(lista_verificata(p, p->next))
		return 1;
	else
		return 0;
}

/*==================================================*/

/*Funzione che conta gli elementi in comune tra due liste*/
plist costruisci_lista_uno_comuni() {
	plist p = NULL;
	int L[] = {2, 3, 4, 5, 2};
	for(int i=0; i<5; i++) {
		plist temp = (plist) malloc(sizeof(elist));
		temp->info = L[i];
		temp->next = p;
		p = temp;
	}
	return p;
}

plist costruisci_lista_due_comuni() {
	plist p = NULL;
	int L[] = {0, 3, 7, 7, 2};
	for(int i=0; i<5; i++) {
		plist temp = (plist) malloc(sizeof(elist));
		temp->info = L[i];
		temp->next = p;
		p = temp;
	}
	return p;
}

int comuni(plist p1, plist p2) {
	if(p1 == NULL || p2 == NULL) return 0;
	int count = 0;
	while(p2!=NULL){
	int verificato = 0;
		while(p1!=NULL && verificato == 0){
			if(p1->info == p2->info){
				count ++;
				verificato = 1;
			}
			else{
				p1 = p1->next;
			}
		}
		p2 = p2->next;
	}
	return count;
}

/*==================================================*/

/*Funzione che verifica se primo e ultimo elemento della lista sono uguali*/

plist costruisci_lista_primo_ultimo_uguali() {
	plist p = NULL;
	int L[] = {2, 3, 4, 5, 2};
	for(int i=0; i<5; i++) {
		plist temp = (plist) malloc(sizeof(elist));
		temp->info = L[i];
		temp->next = p;
		p = temp;
	}
	return p;
}

plist costruisci_lista_primo_ultimo_diversi() {
	plist p = NULL;
	int L[] = {2, 3, 4, 5, 6};
	for(int i=0; i<5; i++) {
		plist temp = (plist) malloc(sizeof(elist));
		temp->info = L[i];
		temp->next = p;
		p = temp;
	}
	return p;
}

int confronta_primo_ultimo(plist l){
    if(l == NULL) return 0;
    int first = l->info;
    while(l->next!=NULL) {
        l = l->next;
    }
    int last = l->info;
    if(first == last) return 1;
    return 0;
    
}

/*==================================================*/

/*Funzione che verifica se esiste campo info pari alla lunghezza della lista*/

plist costruisci_lista_con_almeno_un_info_uguale_lunghezza() {
	plist p = NULL;
	int L[] = {2, 3, 4, 5, 2};
	for(int i=0; i<5; i++) {
		plist temp = (plist) malloc(sizeof(elist));
		temp->info = L[i];
		temp->next = p;
		p = temp;
	}
	return p;
}

plist costruisci_lista_senza_un_info_uguale_lunghezza() {
	plist p = NULL;
	int L[] = {2, 3, 4, 7, 6};
	for(int i=0; i<5; i++) {
		plist temp = (plist) malloc(sizeof(elist));
		temp->info = L[i];
		temp->next = p;
		p = temp;
	}
	return p;
}

int length(plist p){
    int l = 0;
    if(p == NULL) return l;
    while(p!=NULL){
        l ++;
        p = p->next;
    }
    return l;
}

int almeno_info_pari_lunghezza(plist l){
    if(l==NULL) return 0;
    int lun = length(l);
    while(l!=NULL) {
        if(l->info == lun) return 1;
        l = l->next;
    }
    return 0;
}

/*test*/
int main()
{
    plist l5 = costruisci_lista_massimo();
    printf("Nodo massimo -->  ");
	printf("Risultato atteso: 10; Risultato funzione: %d", max_lista(l5));
	printf("\n\n");
	plist l1 = costruisci_lista_ordinata();
	printf("Lista crescente -->  ");
	printf("Risultato atteso: 1; Risultato funzione: %d", is_crescente(l1));
	printf("\n\n");
	plist l2 = costruisci_lista_non_ordinata();
	printf("Lista non crescente -->  ");
	printf("Risultato atteso: 0; Risultato funzione: %d", is_crescente(l2));
	printf("\n\n");
	plist l6 = costruisci_lista_uno_comuni();
	plist l7 = costruisci_lista_due_comuni();
	printf("Comuni -->  ");
	printf("Risultato atteso: 2; Risultato funzione: %d", comuni(l6, l7));
	printf("\n\n");
	plist l3 = costruisci_lista_primo_ultimo_uguali();
	printf("Primo e ultimo uguali -->  ");
	printf("Risultato atteso: 1; Risultato funzione: %d", confronta_primo_ultimo(l3));
	printf("\n\n");
	plist l4 = costruisci_lista_primo_ultimo_diversi();
	printf("Primo e ultimo diversi -->  ");
	printf("Risultato atteso: 0; Risultato funzione: %d", confronta_primo_ultimo(l4));
	printf("\n\n");
	plist l8 = costruisci_lista_con_almeno_un_info_uguale_lunghezza();
	printf("Lista con almeno un info pari alla lunghezza -->  ");
	printf("Risultato atteso: 1; Risultato funzione: %d", almeno_info_pari_lunghezza(l8));
	printf("\n\n");
	plist l9 = costruisci_lista_senza_un_info_uguale_lunghezza();
	printf("Lista con almeno un info pari alla lunghezza -->  ");
	printf("Risultato atteso: 0; Risultato funzione: %d", almeno_info_pari_lunghezza(l9));
	printf("\n\n");
}
