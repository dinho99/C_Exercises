/*PROVA PRELIMINARE ESERCIZI LISTE*/

/*STRUTTURA LISTE*/
#include <stdio.h>
#include <stdlib.h>

typedef struct elist {
	int info;
	struct elist* next;
} elist;

typedef elist* plist;

/*Costruzione liste da testare (6 liste)*/
elist* costruzione_lista_vuota() {
    elist* p = NULL;
    return p;
}

elist* costruzione_lista_head() {
    elist* head = (elist*) malloc(sizeof(elist));
    head->info = 1;
    head->next = NULL;
    return head;
}

elist* costruzione_lista_tre_elementi_ordinati() {
    elist* head = (elist*) malloc(sizeof(elist));
    elist* e2 = (elist*) malloc(sizeof(elist));
    elist* e3 = (elist*) malloc(sizeof(elist));
    head->info = 1;
    head->next = e2;
    e2->info = 2;
    e2->next = e3;
    e3->info = 3;
    e3->next = NULL;
    return head;
}

elist* costruzione_lista_tre_elementi_disordinati() {
    elist* head = (elist*) malloc(sizeof(elist));
    elist* e2 = (elist*) malloc(sizeof(elist));
    elist* e3 = (elist*) malloc(sizeof(elist));
    head->info = 4;
    head->next = e2;
    e2->info = 2;
    e2->next = e3;
    e3->info = 3;
    e3->next = NULL;
    return head;
}

elist* costruzione_lista_cinque_elementi() {
    elist* head = (elist*) malloc(sizeof(elist));
    elist* e2 = (elist*) malloc(sizeof(elist));
    elist* e3 = (elist*) malloc(sizeof(elist));
    elist* e4 = (elist*) malloc(sizeof(elist));
    elist* e5 = (elist*) malloc(sizeof(elist));
    head->info = 1;
    head->next = e2;
    e2->info = 2;
    e2->next = e3;
    e3->info = 3;
    e3->next = e4;
    e4->info = 10;
    e4->next = e5;
    e5->info = 1;
    e5->next = NULL;
    return head;
}

elist* costruzione_lista_complessa() { //lista con 7 elementi
    elist* head = (elist*) malloc(sizeof(elist));
    elist* e2 = (elist*) malloc(sizeof(elist));
    elist* e3 = (elist*) malloc(sizeof(elist));
    elist* e4 = (elist*) malloc(sizeof(elist));
    elist* e5 = (elist*) malloc(sizeof(elist));
    elist* e6 = (elist*) malloc(sizeof(elist));
    elist* e7 = (elist*) malloc(sizeof(elist));
    head->info = 1;
    head->next = e2;
    e2->info = 2;
    e2->next = e3;
    e3->info = 3;
    e3->next = e4;
    e4->info = 10;
    e4->next = e5;
    e5->info = 1;
    e5->next = e6;
    e6->info = 7;
    e6->next = e7;
    e7->info = 1;
    e7->next = NULL;
    return head;
}

/*==================================================*/
/*Esercizi su liste*/
/*==================================================*/

/*Funzione che calcola valore massimo di una lista*/
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

/*Funzione che controlla se lista ordinata crescente*/
int lista_verificata(plist l1, plist l2){
	if(l2 == NULL) return 1;
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

/*Funzione che conta quante volte gli elementi della prima lista che sono contenuti nella seconda lista (se prima
  ha un numero che si ripete più volte verranno contati es: l1 = {1, 2, 1}; l2 = {1} la funzione darà 2)*/
int comuni(plist p1, plist p2) {
	if(p1 == NULL || p2 == NULL) return 0;
	int count = 0;
	while(p1 != NULL) {
	int verificato = 0;
	plist temp = p2; //creo lista clone a p2 senno al termine del ciclo avrei p2 sull'ultimo elemento
		while(temp != NULL && verificato == 0){
			if(p1->info == temp->info){
				count += 1;
				verificato = 1;
			}
			else{
				temp = temp->next;
			}
		}
		p1 = p1->next;
	}
	return count;
}

/*Funzione che verifica se primo e ultimo elemento della lista sono uguali*/
int confronta_primo_ultimo(plist l){
    if(l == NULL) return 0;
    if(l->next == NULL) return 1; //lista con solo un elemento
    
    int first = l->info;
    while(l->next!=NULL) {
        l = l->next;
    }
    
    int last = l->info;
    
    if(first == last) return 1;
    return 0;
}

/*Funzione che verifica se esiste campo info pari alla lunghezza della lista*/
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

/*funzione che controlla se tutti gli elementi della lista hanno campo info pari alla lunghezza della lista*/
int tutte_info_pari_lunghezza(plist p) {
    if(p == NULL) return 0;
    int l = lunghezza_lista(p);
    int verificato = 1;
    while(p != NULL && verificato) {
        if(p->info == l) {
            p = p->next;
        }
        else {
            verificato = 0;
        }
    }
    return verificato;
}

/*===================================================*/
/*FUNZIONI PER TESTARE CORRETTA CREAZIONE DELLE LISTE*/
/*===================================================*/

/*Funzione che calcola lunghezza della lista*/
int lunghezza_lista(elist* e) {
    if(e == NULL) return 0;
    int count = 0;
    while(e!=NULL) {
        count += 1;
        e = e->next;
    }
    return count;
}

/*Funzione che stampa la lista*/
void stampa_lista(elist* e, int length) {
    if(e == NULL)
        printf("Lista vuota!\n");
    for(int i = 0; i<length; i++) {
        printf("%d elemento della lista: %d\n", i+1, e->info);
        e = e->next;
    }
}

/*===================================================*/
/*test*/
/*===================================================*/

int main()
{
    elist* l1 = costruzione_lista_vuota();
    elist* l2 = costruzione_lista_head();
    elist* l3 = costruzione_lista_tre_elementi_ordinati();
    elist* l4 = costruzione_lista_tre_elementi_disordinati();
    elist* l5 = costruzione_lista_cinque_elementi();
    elist* l6 = costruzione_lista_complessa();

    /*TEST STAMPA LISTE*/
    printf("STAMPA DI TUTTE LE LISTE -->\n");
    stampa_lista(l1, lunghezza_lista(l1));
    printf("\n");
    stampa_lista(l2, lunghezza_lista(l2));
    printf("\n");
    stampa_lista(l3, lunghezza_lista(l3));
    printf("\n");
    stampa_lista(l4, lunghezza_lista(l4));
    printf("\n");
    stampa_lista(l5, lunghezza_lista(l5));
    printf("\n");
    stampa_lista(l6, lunghezza_lista(l6));
    printf("\n");
    
    /*TEST CALCOLA MASSIMO VALORE*/
    printf("TEST MAX_LIST\n");
    printf("Risultato atteso: 0, Risultato funzione: %d\n", max_lista(l1));
    printf("Risultato atteso: 1, Risultato funzione: %d\n", max_lista(l2));
    printf("Risultato atteso: 3, Risultato funzione: %d\n", max_lista(l3));
    printf("Risultato atteso: 4, Risultato funzione: %d\n", max_lista(l4));
    printf("Risultato atteso: 10, Risultato funzione: %d\n", max_lista(l5));
    printf("Risultato atteso: 10, Risultato funzione: %d\n", max_lista(l6));
    printf("\n");
    
    /*TEST LISTA ORDINATA*/
    printf("TEST LISTA_CRESCENTE\n");
    printf("Risultato atteso: 0, Risultato funzione: %d\n", is_crescente(l1));
    printf("Risultato atteso: 1, Risultato funzione: %d\n", is_crescente(l2));
    printf("Risultato atteso: 1, Risultato funzione: %d\n", is_crescente(l3));
    printf("Risultato atteso: 0, Risultato funzione: %d\n", is_crescente(l4));
    printf("Risultato atteso: 0, Risultato funzione: %d\n", is_crescente(l5));
    printf("Risultato atteso: 0, Risultato funzione: %d\n", is_crescente(l6));
    printf("\n");
    
    /*TEST CALCOLA MASSIMO VALORE*/
    printf("TEST ELEMENTI_COMUNI\n");
    printf("Risultato atteso: 0, Risultato funzione: %d\n", comuni(l1, l2));
    printf("Risultato atteso: 1, Risultato funzione: %d\n", comuni(l2, l3));
    printf("Risultato atteso: 2, Risultato funzione: %d\n", comuni(l3, l4));
    printf("Risultato atteso: 2, Risultato funzione: %d\n", comuni(l4, l5));
    printf("Risultato atteso: 5, Risultato funzione: %d\n", comuni(l5, l6));
    printf("Risultato atteso: 3, Risultato funzione: %d\n", comuni(l6, l2));
    printf("\n");
    
    /*TEST CONFRONTA PRIMO E ULTIMO*/
    printf("TEST PRIMO_ULTIMO\n");
    printf("Risultato atteso: 0, Risultato funzione: %d\n", confronta_primo_ultimo(l1));
    printf("Risultato atteso: 1, Risultato funzione: %d\n", confronta_primo_ultimo(l2));
    printf("Risultato atteso: 0, Risultato funzione: %d\n", confronta_primo_ultimo(l3));
    printf("Risultato atteso: 0, Risultato funzione: %d\n", confronta_primo_ultimo(l4));
    printf("Risultato atteso: 1, Risultato funzione: %d\n", confronta_primo_ultimo(l5));
    printf("Risultato atteso: 1, Risultato funzione: %d\n", confronta_primo_ultimo(l6));
    printf("\n");
    
    /*TEST ESISTE CAMPO INFO PARI A LUNGHEZZA*/
    printf("TEST INFO_PARI_LUNGHEZZA\n");
    printf("Risultato atteso: 0, Risultato funzione: %d\n", almeno_info_pari_lunghezza(l1));
    printf("Risultato atteso: 1, Risultato funzione: %d\n", almeno_info_pari_lunghezza(l2));
    printf("Risultato atteso: 1, Risultato funzione: %d\n", almeno_info_pari_lunghezza(l3));
    printf("Risultato atteso: 1, Risultato funzione: %d\n", almeno_info_pari_lunghezza(l4));
    printf("Risultato atteso: 0, Risultato funzione: %d\n", almeno_info_pari_lunghezza(l5));
    printf("Risultato atteso: 1, Risultato funzione: %d\n", almeno_info_pari_lunghezza(l6));
    printf("\n");
	
    /*TEST Tutte info pari lunghezza*/
    printf("TEST TUTTE_INFO_PARI_LUNGHEZZA\n");
    printf("Risultato atteso: 0, Risultato funzione: %d\n", tutte_info_pari_lunghezza(l1));
    printf("Risultato atteso: 1, Risultato funzione: %d\n", tutte_info_pari_lunghezza(l2));
    printf("Risultato atteso: 0, Risultato funzione: %d\n", tutte_info_pari_lunghezza(l3));
    printf("Risultato atteso: 0, Risultato funzione: %d\n", tutte_info_pari_lunghezza(l4));
    printf("Risultato atteso: 0, Risultato funzione: %d\n", tutte_info_pari_lunghezza(l5));
    printf("Risultato atteso: 0, Risultato funzione: %d\n", tutte_info_pari_lunghezza(l6));
    printf("\n");
}
