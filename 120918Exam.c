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

/* struttura per l’albero figlio-sinistro fratello-destro */
typedef struct nodo_albero_struct {
    struct nodo_albero_struct* left_child;
    struct nodo_albero_struct* right_sibling;
    int info;
} nodo_albero;

/*torna numero di componenti connesse di un grafo*/
int numero_comp_connesse(grafo* g) {
    elem_nodi* ln = g->nodi;
    while(ln != NULL) {
        ln->info->color = 0;
        ln = ln->next;
    }
    
    int color = 0;
    ln = g->nodi;
    while(ln != NULL) {
        if(ln->info->color == 0) {
            color ++;
            DFS_colora(ln->info, color);
        }
        ln = ln->next;
    }
    return color;
}

void DFS_colora(nodo* n, int color) {
    n->color = color;
    elem_archi* la = n->archi;
    while(la != NULL) {
        nodo* nuovo_nodo = la->info->from;
        if(nuovo_nodo == n)
            nuovo_nodo = la->info->to;
        if(nuovo_nodo->color == 0)
            DFS_colora(nuovo_nodo, color);
        la = la->next;
    }
}

/*ritorna dimensione di una componente connessa
 contando tutti i nodi della lista nodi che hanno
 un determinato colore*/
int dimensione_comp(grafo* g, int color) {
    int count = 0;
    elem_nodi* ln = g->nodi;
    while(ln != NULL) {
        if(ln->info->color == color) {
            count ++;
        }
        ln = ln->next;
    }
    return count;
}

/*ritorna numero di foglie di un albero arbitrario*/
int numero_foglie_albero(nodo_albero* n) {
    if(n == NULL) return 0;
    
    if(n->left_child == NULL){ //se n è foglia
        return 1 + numero_foglie_albero(n->right_sibling); //vai al fratello di n se null tanto torna 0
    }
    return numero_foglie_albero(n->left_child) + numero_foglie_albero(n->right_sibling);
}

/*La funzione restituisce 1 se almeno una componente connessa del grafo g ha tanti
 nodi quante le foglie dell’albero a, altrimenti la funzione restituisce 0.
 Se grafo e albero sono entrambi vuoti (cioè uguali a NULL) la funzione ritorna true.
 Se uno è vuoto e uno no, allora ritorna false.
*/
int foglie_comp(grafo* g, nodo_albero* a) {
    if(g == NULL && a == NULL) return 1;
    if(g == NULL || a == NULL) return 0;
    
    int c = numero_comp_connesse(g);
    int numero_foglie = numero_foglie_albero(a);
    for(int i = 1; i <= c; i ++) {
        if(dimensione_comp(g, i) == numero_foglie)
            return 1;
    }
    
    return 0;
}

int main() {
}

