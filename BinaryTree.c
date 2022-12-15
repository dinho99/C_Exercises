#include <stdio.h>
#include <stdlib.h>

typedef struct nodo{
    struct nodo* sx;
    struct nodo* dx;
    int info;
}nodo;

typedef nodo* albero;

/*Costruzione alberi da testare:
    5 alberi
    - NULL
    - Albero radice
    - Albero un figlio foglia
    - Albero due figli foglie
    - Albero 6 nodi complesso (3 foglie)*/
    
void costruzione_albero_null() {}

nodo* costruzione_albero_radice(){
    nodo* radice = (nodo*) malloc(sizeof(nodo));
    radice->dx == NULL;
    radice->sx == NULL;
    radice->info = 0;
    return radice;
}

nodo* costruzione_albero_figlio_foglia(){
    nodo* radice = (nodo*) malloc(sizeof(nodo));
    nodo* sinistro = (nodo*) malloc(sizeof(nodo));
    radice->sx = sinistro;
    radice->dx = NULL;
    radice->info = 0;
    sinistro->sx = NULL;
    sinistro->dx = NULL;
    sinistro->info = 1;
    return radice;
}

nodo* costruzione_albero_figli_foglie(){
    nodo* radice = (nodo*) malloc(sizeof(nodo));
    nodo* sinistro = (nodo*) malloc(sizeof(nodo));
    nodo* destro = (nodo*) malloc(sizeof(nodo));
    radice->sx = sinistro;
    radice->dx = destro;
    radice->info = 0;
    sinistro->sx = NULL;
    sinistro->dx = NULL;
    sinistro->info = 1;
    destro->sx = NULL;
    destro->dx = NULL;
    destro->info = 1;
    return radice;
}

nodo* costruzione_albero_complesso(){
    nodo* radice = (nodo*) malloc(sizeof(nodo));
    nodo* sinistro = (nodo*) malloc(sizeof(nodo));
    nodo* destro = (nodo*) malloc(sizeof(nodo));
    nodo* sinistrosinistro = (nodo*) malloc(sizeof(nodo));
    nodo* sinistrodestro = (nodo*) malloc(sizeof(nodo));
    nodo* sinistrodestrodestro = (nodo*) malloc(sizeof(nodo));
    radice->sx = sinistro;
    radice->dx = destro;
    radice->info = 0;
    sinistro->sx = sinistrosinistro;
    sinistro->dx = sinistrodestro;
    sinistro->info = 1;
    destro->sx = NULL;
    destro->dx = NULL;
    destro->info = 1;
    sinistrosinistro->sx = NULL;
    sinistrosinistro->dx = NULL;
    sinistrosinistro->info = 0;
    sinistrodestro->sx = NULL;
    sinistrodestro->dx = sinistrodestrodestro;
    sinistrodestro->info = 1;
    sinistrodestrodestro->sx = NULL;
    sinistrodestrodestro->dx = NULL;
    sinistrodestrodestro->info = 1;
    return radice;
}

/*=======================================*/
/*FUNZIONI*/
/*=======================================*/

/*funzione che restituisce 1 se il numero di nodi sono esattamente il doppio delle foglie*/
int conta_foglie(nodo* n){
    if(n == NULL) return 0;
    int count = 0;
    if(n->dx == NULL && n->sx == NULL)
        count ++;
    return count + conta_foglie(n->dx) + conta_foglie(n->sx);
}

int conta_nodi(nodo* n){
    if(n == NULL) return 0;
    int count = 0;
    if(n != NULL) count ++;
    return count + conta_nodi(n->dx) + conta_nodi(n->sx);
}

int nodi_foglie_per_due(albero T){
    if(T == NULL) return 1;
    if((2*conta_foglie(T)) == conta_nodi(T))
        return 1;
    else return 0;
}

/*Funzione che restituisce 1 se esiste una foglia destra nell'albero*/
int foglia_destra(albero T){
    if(T==NULL || T->dx==NULL) return 0;
    if(T->dx->dx == NULL && T->dx->sx == NULL)
        return 1;
    return foglia_destra(T->sx) || foglia_destra(T->dx);
}

/*=======================================*/
/*MAIN*/

int main()
{
    //Costruzione alberi per i test
    nodo* n1 = NULL;
    nodo* n2 = costruzione_albero_radice();
    nodo* n3 = costruzione_albero_figlio_foglia();
    nodo* n4 = costruzione_albero_figli_foglie();
    nodo* n5 = costruzione_albero_complesso();
    
    //TEST NODI = FOGLIE x2
    printf("NODI_FOGLIE_PER_DUE\n");
    printf("Risultato atteso: 1, Risultato funzione: %d\n", nodi_foglie_per_due(n1));
    printf("Risultato atteso: 0, Risultato funzione: %d\n", nodi_foglie_per_due(n2));
    printf("Risultato atteso: 1, Risultato funzione: %d\n", nodi_foglie_per_due(n3));
    printf("Risultato atteso: 0, Risultato funzione: %d\n", nodi_foglie_per_due(n4));
    printf("Risultato atteso: 1, Risultato funzione: %d\n", nodi_foglie_per_due(n5));
    printf("\n");

    //TEST ESISTE FOGLIA DESTRA
    printf("FOGLIA_DESTRA\n");
    printf("Risultato atteso: 0, Risultato funzione: %d\n", foglia_destra(n1));
    printf("Risultato atteso: 0, Risultato funzione: %d\n", foglia_destra(n2));
    printf("Risultato atteso: 0, Risultato funzione: %d\n", foglia_destra(n3));
    printf("Risultato atteso: 1, Risultato funzione: %d\n", foglia_destra(n4));
    printf("Risultato atteso: 1, Risultato funzione: %d\n", foglia_destra(n5));
    printf("\n");
}
