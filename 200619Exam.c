#include <stdio.h>
#include <stdlib.h>

/*Structures: */

/* struttura per il grafo */
typedef struct nodo_struct {
    elem_nodi* pos; // posizione nodo nella lista del grafo
    elem_archi* archi; // lista archi incidenti
    int color;
}nodo;

typedef struct arco_struct {
    elem_archi* pos; // pos. arco lista grafo
    nodo* from;
    nodo* to;
    elem_archi* frompos; // pos. arco nodo
    elem_archi* topos; // pos. arco nodo to
}arco;

typedef struct elem_lista_nodi {
    struct elem_lista_nodi* prev;
    struct elem_lista_nodi* next;
    nodo* info;
}elem_nodi; // elemento di una lista di nodi

typedef struct elem_lista_archi {
    struct elem_lista_archi* prev;
    struct elem_lista_archi* next;
    arco* info;
}elem_archi; // elemento di una lista di archiù

typedef struct {
    int numero_nodi;
    int numero_archi;
    elem_archi* archi; // lista degli archi
    elem_nodi* nodi; // lista dei nodi
} grafo;

/* struttura per l’albero binario */
typedef struct nodo_albero_struct {
    struct nodo_albero_struct* sx;
    struct nodo_albero_struct* dx;
    int info;
} nodo_albero;

/*Ritorna numero di nodi a una certa profondità*/
int nodi_prof(nodo_albero* n, int h) {
    if(n == NULL) return 0;
    if(h == 0) return 1;
    return nodi_prof(n->dx, h-1) + nodi_prof(n->sx, h-1);
}

int componente_max(grafo* g) {
    elem_nodi* ln = g->nodi;
    while(ln != NULL) {
        ln->info->color = 0;
        ln = ln->next;
    }
    
    ln = g->nodi;
    int comp_max = 0;
    while(ln != NULL) {
        if(ln->info->color == 0){
            int new = DFS_size(ln->info);
            if(new > comp_max)
            comp_max = new;
        }
        ln = ln->next;
    }
    return comp_max;
}

int DFS_size(nodo* n) {
    int count = 1;
    n->color = 1;
    elem_archi* la = n->archi;
    while(la != NULL) {
        nodo* altro_nodo = la->info->from;
        if(altro_nodo == n)
            altro_nodo = la->info->to;
        if(altro_nodo->color == 0)
            count += DFS_size(altro_nodo);
        la = la->next;
    }
    return count;
}

/*La funzione restituisce 1 se il numero di nodi dell’albero a che sono a
profondità h sono tanti quanti sono i nodi della componente più grande del
grafo g, altrimenti la funzione restituisce 0. Se uno (o entrambi) tra grafo
e albero è vuoto (cioè uguali a NULL) la funzione ritorna 0.*/
int verifica(int h, nodo_albero* a, grafo* g) {
    if(a == NULL || g == NULL) return 0;
    return nodi_prof(a, h) == componente_max(g);
}

int main()
{
    
}
