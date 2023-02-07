#include <stdio.h>
#include <stdlib.h>

/* struttura nodo per l’albero binario */
typedef struct nodo_struct {
    struct nodo_struct* sx;
    struct nodo_struct* dx;
    int info;
} nodo;

/*COSTRUZIONI ALBERI: 1 ESEMPIO ESAME, 1 DISPARI, 1 NON VERIFICA*/

/*Costruzione albero dispari: 9 nodi*/
nodo* costruzione_albero_dispari() {
    nodo* radice = (nodo*) malloc(sizeof(nodo));
    nodo* sinistro = (nodo*) malloc(sizeof(nodo));
    nodo* destro = (nodo*) malloc(sizeof(nodo));
    nodo* sinistrosinistro = (nodo*) malloc(sizeof(nodo));
    nodo* sinistrodestro = (nodo*) malloc(sizeof(nodo));
    nodo* sinistrodestrodestro = (nodo*) malloc(sizeof(nodo));
    nodo* destrodestro = (nodo*) malloc(sizeof(nodo));
    nodo* destrodestrodestro = (nodo*) malloc(sizeof(nodo));
    nodo* destrodestrosinistro = (nodo*) malloc(sizeof(nodo));
    
    radice->sx = sinistro;
    radice->dx = destro;
    radice->info = 1;
    
    sinistro->sx = sinistrosinistro;
    sinistro->dx = sinistrodestro;
    sinistro->info = 1;
    
    destro->sx = NULL;
    destro->dx = destrodestro;
    destro->info = 1;
    
    destrodestro->sx = destrodestrosinistro;
    destrodestro->dx = destrodestrodestro;
    destrodestro->info = 1;
    
    destrodestrosinistro->sx = NULL;
    destrodestrosinistro->dx = NULL;
    destrodestrosinistro->info = 1;
    
    destrodestrodestro->sx = NULL;
    destrodestrodestro->dx = NULL;
    destrodestrodestro->info = 1;
    
    sinistrosinistro->sx = NULL;
    sinistrosinistro->dx = NULL;
    sinistrosinistro->info = 1;
    
    sinistrodestro->sx = NULL;
    sinistrodestro->dx = sinistrodestrodestro;
    sinistrodestro->info = 1;
    
    sinistrodestrodestro->sx = NULL;
    sinistrodestrodestro->dx = NULL;
    sinistrodestrodestro->info = 0;
    
    return radice;
}

/*Costruzione albero che non verifica: 8 nodi*/
nodo* costruzione_albero_non_verifica() {
    nodo* radice = (nodo*) malloc(sizeof(nodo));
    nodo* sinistro = (nodo*) malloc(sizeof(nodo));
    nodo* destro = (nodo*) malloc(sizeof(nodo));
    nodo* sinistrosinistro = (nodo*) malloc(sizeof(nodo));
    nodo* sinistrodestro = (nodo*) malloc(sizeof(nodo));
    nodo* sinistrodestrodestro = (nodo*) malloc(sizeof(nodo));
    nodo* destrodestro = (nodo*) malloc(sizeof(nodo));
    nodo* sinistrodestrodestrosinistro = (nodo*) malloc(sizeof(nodo));

    radice->sx = sinistro;
    radice->dx = destro;
    radice->info = 1;
    
    sinistro->sx = sinistrosinistro;
    sinistro->dx = sinistrodestro;
    sinistro->info = 1;
    
    destro->sx = NULL;
    destro->dx = destrodestro;
    destro->info = 1;
    
    destrodestro->sx = NULL;
    destrodestro->dx = NULL;
    destrodestro->info = 1;
    
    sinistrosinistro->sx = NULL;
    sinistrosinistro->dx = NULL;
    sinistrosinistro->info = 1;
    
    sinistrodestro->sx = NULL;
    sinistrodestro->dx = sinistrodestrodestro;
    sinistrodestro->info = 1;
    
    sinistrodestrodestro->sx = sinistrodestrodestrosinistro;
    sinistrodestrodestro->dx = NULL;
    sinistrodestrodestro->info = 0;
    
    sinistrodestrodestrosinistro->sx = NULL;
    sinistrodestrodestrosinistro->dx = NULL;
    sinistrodestrodestrosinistro->info = 0;
    
    return radice;
}
    
/**/

/*Costruzione albero d'esempio: 10 nodi*/
nodo* costruzione_albero_esempio_esame() {
    nodo* radice = (nodo*) malloc(sizeof(nodo));
    nodo* sinistro = (nodo*) malloc(sizeof(nodo));
    nodo* destro = (nodo*) malloc(sizeof(nodo));
    nodo* sinistrosinistro = (nodo*) malloc(sizeof(nodo));
    nodo* sinistrodestro = (nodo*) malloc(sizeof(nodo));
    nodo* sinistrodestrodestro = (nodo*) malloc(sizeof(nodo));
    nodo* sinistrodestrodestrosinistro = (nodo*) malloc(sizeof(nodo));
    nodo* destrodestro = (nodo*) malloc(sizeof(nodo));
    nodo* destrodestrodestro = (nodo*) malloc(sizeof(nodo));
    nodo* destrodestrosinistro = (nodo*) malloc(sizeof(nodo));
    
    radice->sx = sinistro;
    radice->dx = destro;
    radice->info = 1;
    
    sinistro->sx = sinistrosinistro;
    sinistro->dx = sinistrodestro;
    sinistro->info = 1;
    
    destro->sx = NULL;
    destro->dx = destrodestro;
    destro->info = 1;
    
    destrodestro->sx = destrodestrosinistro;
    destrodestro->dx = destrodestrodestro;
    destrodestro->info = 1;
    
    destrodestrosinistro->sx = NULL;
    destrodestrosinistro->dx = NULL;
    destrodestrosinistro->info = 1;
    
    destrodestrodestro->sx = NULL;
    destrodestrodestro->dx = NULL;
    destrodestrodestro->info = 1;
    
    sinistrosinistro->sx = NULL;
    sinistrosinistro->dx = NULL;
    sinistrosinistro->info = 1;
    
    sinistrodestro->sx = NULL;
    sinistrodestro->dx = sinistrodestrodestro;
    sinistrodestro->info = 1;
    
    sinistrodestrodestro->sx = sinistrodestrodestrosinistro;
    sinistrodestrodestro->dx = NULL;
    sinistrodestrodestro->info = 0;
    
    sinistrodestrodestrosinistro->sx = NULL;
    sinistrodestrodestrosinistro->dx = NULL;
    sinistrodestrodestrosinistro->info = 0;
    
    return radice;
}

/*
Funzione che accetti in input un puntatore alla radice di un albero binario
di interi e ritorni 1 se esiste un nodo dell’albero che è radice di un sottoalbero
che ha esattamente la metà dei nodi dell’intero albero, altrimenti ritorna 0.
Se i nodi dell’albero sono dispari la funzione verifica() ritorna ovviamente 0.
*/
int numero_nodi(nodo* n) {
    if(n == NULL) return 0;
    int count = 0;
    if(n != NULL)
        count ++;
    return count + numero_nodi(n->sx) + numero_nodi(n->dx);
}

int esiste_sottoalbero(nodo* n, int nodi) {
    if(n == NULL) return 0;
    if(numero_nodi(n) == nodi) return 1;
    return esiste_sottoalbero(n->dx, nodi) || esiste_sottoalbero(n->sx, nodi);
}

int verifica(nodo* a) {
    int nodi = numero_nodi(a);
    if(nodi % 2 != 0) return 0; //se numero di nodi dispari
    return esiste_sottoalbero(a, nodi/2);
}

int main()
{
    nodo* test_corretto = costruzione_albero_esempio_esame();
    nodo* test_dispari = costruzione_albero_dispari();
    nodo* test_non_corretto = costruzione_albero_non_verifica();
    
    /*Stampa test*/
    printf("TEST ESISTE SOTTOALBERO -->\n");
    printf("Risultato atteso = 1, Risultato funzione = %d\n", verifica(test_corretto));
    printf("Risultato atteso = 0, Risultato funzione = %d\n", verifica(test_dispari));
    printf("Risultato atteso = 0, Risultato funzione = %d\n", verifica(test_non_corretto));

}
