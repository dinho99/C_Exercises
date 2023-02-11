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

int dim_comp_max(grafo* g) {
    elem_nodi* ln = g->nodi;
    while(ln != NULL) {
        ln->info->color = 0;
        ln = ln->info;
    }
    
    int comp_max = 0;
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
    elem_archi* la = n->archi;
    int count = 1;
    while(la != NULL) {
        nodo* nuovo_nodo = la->info->from;
        if(nuovo_nodo = n)
            nuovo_nodo = la->info->to;
        if(nuovo_nodo->color == 0) {
            count += DFS_size(nuovo_nodo);
        }
        la = la->next;
    }
    return count;
}

int altezza_albero(nodo_albero* n) {
    if(n == NULL) return -1;
    int l = 1 + altezza_albero(n->left_child);
    int r = altezza_albero(n->right_sibling);
    if(l > r) return l;
    return r;
}

int nodi_prof_albero(nodo_albero* a, int h) {
    if(a == NULL) return 0;
    int count = 0;
    nodo* x = a;
    while(x != NULL) {
        if(h == 0) {
            count ++;
        }
        count += nodi_prof_albero(x->left_child, h-1);
        x = x->right_sibling;
    }
    return count;
}

/*La funzione restituisce 1 (cioè true) se esiste una profondità dell’albero alla
 quale ci sono tanti nodi quanti sono i nodi della componente connessa più grande
 del grafo g, altrimenti la funzione restituisce 0 (cioè false). Se uno (o entrambi)
 tra grafo e albero è vuoto (cioè uguale a NULL) la funzione ritorna 0 (false).*/
int verifica(nodo_albero* a, grafo* g) {
    if(a == NULL || g == NULL) return 0;
    int altezza = altezza_albero(a);
    int comp_max = dim_comp_max(g);
    while(altezza != 0) {
        if(comp_max == nodi_prof_albero(a, altezza)) return 1;
        altezza --;
    }
    return 0;
}  

int main() {
}

