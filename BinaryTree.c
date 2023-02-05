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
    radice->dx = NULL;
    radice->sx = NULL;
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
    destro->info = 0;
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
    sinistrodestrodestro->info = 0;
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


/*Funzione che restituisce 1 se esiste un nodo con due figli foglie*/
int due_figli_foglie(albero T){
    if(T==NULL || T->dx == NULL || T->sx == NULL) return 0;
    if(T->dx->dx == NULL && T->dx->sx == NULL && T->sx->dx == NULL && T->sx->sx == NULL)
        return 1;
    return due_figli_foglie(T->dx) || due_figli_foglie(T->sx);
}

/*Funzione che conta quanti nodi hanno campo info pari a 0*/
int conta_info_zero(albero T){
    if(T==NULL) return 0;
    int count = 0;
    if(T->info == 0)
        count ++;
    return count + conta_info_zero(T->dx) + conta_info_zero(T->sx);
}

/*Funzione che conta quante foglie hanno campo info pari a 0*/
int conta_foglie_info_zero(albero T){
    if(T==NULL) return 0;
    int count = 0;
    if(T->dx == NULL && T->sx == NULL && T->info == 0)
        count ++;
    return count + conta_foglie_info_zero(T->dx) + conta_foglie_info_zero(T->sx);
}

/*Funzione che verifica altezza dell'albero sia pari al numero di foglie*/
int altezza(nodo* n){
    if(n == NULL) return -1;
    
    int r = altezza(n->dx);
    int l = altezza(n->sx);
    
    if(r>l) return r+1;
    return l+1;
}

int numero_foglie(nodo* n){
    if(n == NULL) return 0;
    int count = 0;
    if(n->dx == NULL && n->sx == NULL)
        count ++;
    return count + numero_foglie(n->dx) + numero_foglie(n->sx);
}

int altezza_come_foglie(albero T){
    if(T == NULL) return 0;
    if(altezza(T) == numero_foglie(T))
        return 1;
    else return 0;
}

/*Funzione che verifica se esiste un valore all'interno dell'albero*/
int cerca_valore(albero T, int v){
    if(T == NULL) return 0;
    int verificato = 0;
    if(T->info == v)
        verificato = 1;
    return verificato || cerca_valore(T->dx, v) || cerca_valore(T->sx, v);
}

/*Funzione che conta quanti nodi hanno info pari a un valore passato per parametro*/
int conta_valore(albero T, int v){
    if(T == NULL) return 0;
    int count = 0;
    if(T->info == v)
        count ++;
    return count + conta_valore(T->dx, v) + conta_valore(T->sx, v);
}

/*Funzione che conta quanti nodi hanno campo info pari alla distanza dalla radice*/
int distanza_dalla_radice(nodo* n, int d){
    if(n == NULL) return 0;
    int count = 0;
    if(n->info == d)
        count ++;
    count += distanza_dalla_radice(n->dx, d+1) + distanza_dalla_radice(n->sx, d+1);
    return count;
}

int info_pari_distanza(albero T){
    if(T == NULL) return 0;
    return distanza_dalla_radice(T, 0);
}

/*Funzione che conta quanti nodi hanno campo info pari all'altezza dell'albero*/
int altezza_albero(nodo* n){
    if(n == NULL) return -1;
    
    int l = altezza_albero(n->sx);
    int r = altezza_albero(n->dx);
    
    if(l>r) return l+1;
    return r+1;
}

int counter(nodo* n, int h){
    if(n == NULL) return 0;
    int count = 0;
    if(n->info == h)
        count ++;
    return count + counter(n->sx, h) + counter(n->dx, h);
}

int info_pari_altezza(albero T){
    if(T == NULL) return 0;
    int high = altezza_albero(T);
    return counter(T, high);
}

/*Funziona che torna l'altezza della foglia meno profonda*/
int foglia_meno_profonda(albero t) {

  if (t == NULL) {
    return 0;
  }

  if ((t->sx == NULL) && (t->dx == NULL)) {
    return 0;
  }

  int left = foglia_meno_profonda(t->sx);
  int right = foglia_meno_profonda(t->dx);

  if (left > right) {
    return right + 1;
  } else
    return left + 1;
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
    
    //TEST ESISTE DUE FIGLI FOGLIA
    printf("DUE_FIGLI_FOGLIE\n");
    printf("Risultato atteso: 0, Risultato funzione: %d\n", due_figli_foglie(n1));
    printf("Risultato atteso: 0, Risultato funzione: %d\n", due_figli_foglie(n2));
    printf("Risultato atteso: 0, Risultato funzione: %d\n", due_figli_foglie(n3));
    printf("Risultato atteso: 1, Risultato funzione: %d\n", due_figli_foglie(n4));
    printf("Risultato atteso: 0, Risultato funzione: %d\n", due_figli_foglie(n5));
    printf("\n");
    
    //TEST CONTA INFO PARI A ZERO
    printf("CONTA_INFO_ZERO\n");
    printf("Risultato atteso: 0, Risultato funzione: %d\n", conta_info_zero(n1));
    printf("Risultato atteso: 1, Risultato funzione: %d\n", conta_info_zero(n2));
    printf("Risultato atteso: 1, Risultato funzione: %d\n", conta_info_zero(n3));
    printf("Risultato atteso: 2, Risultato funzione: %d\n", conta_info_zero(n4));
    printf("Risultato atteso: 3, Risultato funzione: %d\n", conta_info_zero(n5));
    printf("\n");
    
    //TEST CONTA FOGLIE INFO PARI A ZERO
    printf("CONTA_FOGLIE_INFO_ZERO\n");
    printf("Risultato atteso: 0, Risultato funzione: %d\n", conta_foglie_info_zero(n1));
    printf("Risultato atteso: 1, Risultato funzione: %d\n", conta_foglie_info_zero(n2));
    printf("Risultato atteso: 0, Risultato funzione: %d\n", conta_foglie_info_zero(n3));
    printf("Risultato atteso: 1, Risultato funzione: %d\n", conta_foglie_info_zero(n4));
    printf("Risultato atteso: 2, Risultato funzione: %d\n", conta_foglie_info_zero(n5));
    printf("\n");
    
    //TEST NUMERO FOGLIE PARI ALL'ALTEZZA
    printf("ALTEZZA_COME_FOGLIE\n");
    printf("Risultato atteso: 0, Risultato funzione: %d\n", altezza_come_foglie(n1));
    printf("Risultato atteso: 0, Risultato funzione: %d\n", altezza_come_foglie(n2));
    printf("Risultato atteso: 1, Risultato funzione: %d\n", altezza_come_foglie(n3));
    printf("Risultato atteso: 0, Risultato funzione: %d\n", altezza_come_foglie(n4));
    printf("Risultato atteso: 1, Risultato funzione: %d\n", altezza_come_foglie(n5));
    printf("\n");
    
    //TEST CERCA VALORE
    printf("CERCA_VALORE\n");
    printf("Risultato atteso: 0, Risultato funzione: %d\n", cerca_valore(n1, 1));
    printf("Risultato atteso: 0, Risultato funzione: %d\n", cerca_valore(n2, 1));
    printf("Risultato atteso: 1, Risultato funzione: %d\n", cerca_valore(n3, 1));
    printf("Risultato atteso: 1, Risultato funzione: %d\n", cerca_valore(n4, 1));
    printf("Risultato atteso: 1, Risultato funzione: %d\n", cerca_valore(n5, 1));
    printf("\n");
    
    //TEST CONTA VALORE
    printf("CONTA_VALORE\n");
    printf("Risultato atteso: 0, Risultato funzione: %d\n", conta_valore(n1, 1));
    printf("Risultato atteso: 0, Risultato funzione: %d\n", conta_valore(n2, 1));
    printf("Risultato atteso: 1, Risultato funzione: %d\n", conta_valore(n3, 1));
    printf("Risultato atteso: 1, Risultato funzione: %d\n", conta_valore(n4, 1));
    printf("Risultato atteso: 3, Risultato funzione: %d\n", conta_valore(n5, 1));
    printf("\n");
    
    //TEST CONTA QUANTI INFO PARI A DISTANZA DALLA RADICE
    printf("INFO_PARI_DISTANZA\n");
    printf("Risultato atteso: 0, Risultato funzione: %d\n", info_pari_distanza(n1));
    printf("Risultato atteso: 1, Risultato funzione: %d\n", info_pari_distanza(n2));
    printf("Risultato atteso: 2, Risultato funzione: %d\n", info_pari_distanza(n3));
    printf("Risultato atteso: 2, Risultato funzione: %d\n", info_pari_distanza(n4));
    printf("Risultato atteso: 3, Risultato funzione: %d\n", info_pari_distanza(n5));
    printf("\n");
    
    //TEST CONTA QUANTI INFO PARI A ALTEZZA ALBERO
    printf("INFO_PARI_ALTEZZA\n");
    printf("Risultato atteso: 0, Risultato funzione: %d\n", info_pari_altezza(n1));
    printf("Risultato atteso: 1, Risultato funzione: %d\n", info_pari_altezza(n2));
    printf("Risultato atteso: 1, Risultato funzione: %d\n", info_pari_altezza(n3));
    printf("Risultato atteso: 1, Risultato funzione: %d\n", info_pari_altezza(n4));
    printf("Risultato atteso: 0, Risultato funzione: %d\n", info_pari_altezza(n5));
    printf("\n");
    
    //TEST FOGLIA MENO PROFONDA
    printf("FOGLIA_MENO_PROFONDA\n");
    printf("Risultato atteso: 0, Risultato funzione: %d\n", foglia_meno_profonda(n1));
    printf("Risultato atteso: 0, Risultato funzione: %d\n", foglia_meno_profonda(n2));
    printf("Risultato atteso: 1, Risultato funzione: %d\n", foglia_meno_profonda(n3));
    printf("Risultato atteso: 1, Risultato funzione: %d\n", foglia_meno_profonda(n4));
    printf("Risultato atteso: 1, Risultato funzione: %d\n", foglia_meno_profonda(n5));
    printf("\n");
}
