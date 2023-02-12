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

int dim_comp_max(grafo* g) {
    elem_nodi* ln = g->nodi;
    while(ln != NULL) {
        ln->info->color = 0;
        ln = ln->next;
    }
    
    int comp_max = DFS_size(ln->info);
    ln = g->nodi;
    while(ln != NULL) {
        if(ln->info->color == 0) {
            int new_size = DFS_size(ln->info);
            if(new_size > comp_max)
                comp_max = new_size;
        }
        ln = ln->next;
    }
    return comp_max;
}

int DFS_size(nodo* n) {
    n->color = 1;
    int count = 1;
    elem_archi* la = n->archi;
    while(la != NULL) {
        nodo* nodo_opposto = la->info->from;
        if(nodo_opposto == n)
            nodo_opposto = la->info->to;
        if(nodo_opposto->color == 0)
            count += DFS_size(nodo_opposto);
        la = la->next;
    }
    return count;
}

int prof_foglia_ric(nodo_albero* n, int h, int max) {
    if(n == NULL) return 0;
    if(n->dx == NULL && n->sx == NULL && h == comp_max)
        return 1;
    return prof_foglia_ric(n->dx, h+1) ||  prof_foglia_ric(n->dx, h+1);
}

int prof_foglia_come_compmax(nodo_albero* n, int max) {
    if(n == NULL) return 0;
    return prof_foglia_ric(n, 0, max);
}

/*La funzione restituisce 1 (cioè true) se esiste una foglia dell’albero la cui
 profondità è uguale al numero di nodi della componente connessa del grafo g che
 ha più nodi, altrimenti la funzione restituisce 0 (cioè false). Se uno (o entrambi)
 tra grafo e albero è vuoto (cioè uguale a NULL) la funzione ritorna 0 (false).*/
int verifica(nodo_albero* a, grafo* g) {
    if(a == NULL || g == NULL) return 0;
    int comp_max = dim_comp_max(g);
    return prof_foglia_come_compmax(a, comp_max);
}

int main()
{

}
