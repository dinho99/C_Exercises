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

int numero_comp_connesse(grafo* g, int color) {
    elem_nodi* ln = g->nodi;
    int count = 0;
    while(ln != NULL) {
        ln->info->color = 0;
        ln = ln->next;
    }
    
    ln = g->nodi;
    int color = 0;
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
        if(nuovo_nodo->color == 0) {
            DFS_colora(nuovo_nodo, color);
        }
        la = la->next;
    }
}

int numero_sottoalberi_omogenei(nodo_albero* n) {
    if(n == NULL) return 0;
    if(n->info != 1) return 0;
    int out = 1;
    nodo_albero* x = n->left_child;
    while(x != NULL) {
        out = out && numero_sottoalberi_omogenei(x);
        x = x->right_sibling;
    }
    return out;
}

/*La funzione restituisce 1 se il numero delle componenti connesse del grafo
 è uguale al numero di sottoalberi “omogenei” dell’albero a, altrimenti la funzione
 restituisce 0. Un sottoalbero è “omogeneo” se ha il valore 1 nel campo info di
 tutti i suoi nodi (compresa la radice del sottoalbero). Se grafo e albero sono
 entrambi vuoti (cioè uguali a NULL) la funzione ritorna true.
 Se uno è vuoto e uno no, allora ritorna false.
 */
int verifica(grafo* g, nodo_albero* a) {
    if(g == NULL && a == NULL) return 1;
    if(g == NULL || a == NULL) return 0;
    return numero_comp_connesse(g) = numero_sottoalberi_omogenei(a);
}

int main() {
}

