#include <stdlib.h>
#include <stdio.h>

/*Structures: */
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
    from elem_archi* topos; // pos. arco nodo to
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

/*==============================================*/

void DFS_colora(nodo* n, int color) {
    n->color = color;
    elem_archi* la = n->archi;
    while(la != NULL) {
        nodo* altro_nodo = la->info->to;
        if(altro_nodo == n) {
            altro_nodo = la->info->from;
        }
        if(altro_nodo->color == 0) {
            DFS_colora(altro_nodo, color);
        }
        la = la->next;
    }
}

/*Funzione che riceve un puntatore ad un grafo e restituisce la dimensione della componente connessa*/
int dimensione_componente(grafo* g, int comp) {
    int cont = 0;
    elem_nodi* ln = g->nodi;
    while(ln!=NULL) {
        if(ln->info->color == comp) {
            cont ++;
        }
        ln = ln->next;
    }
    return cont;
}

/*Funzione verifica(grafo* g) che accetti in input un puntatore g ad un grafo non orientato
rappresentato tramite oggetti e riferimenti. La funzione restituisce 1 (cioè true) se il grafo
contiene almeno una componente connessa il cui numero di nodi è pari al numero di componenti
connesse del grafo stesso, altrimenti la funzione restituisce 0 (cioè false).
Se il grafo è vuoto (cioè uguale a NULL) la funzione ritorna 1 (true).*/
int verifica(grafo* g) {
    if(g == NULL) return 1;
    
    elem_nodi* ln = g->nodi;
    while(ln != NULL) { // inizializzo colore a 0
        ln->color = 0;
        ln = ln->next;
    }
    int color = 0;
    ln = g->nodi;
    while(ln != NULL) {
        if(ln->info->color == 0) { // trovato nodo non visitato
            color ++;
            DFS_colora(ln->info, color);
        }
        ln = ln->next;
    }
    int comp;
    for(comp = 0; comp<= color; comp ++) {
        if(dimensione_componente(g, comp) == color)
            return 1;
    }
    return 0;
}



int main() {}
