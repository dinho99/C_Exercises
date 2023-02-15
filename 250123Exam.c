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

/*ritorna numero tot di comp connesse e colora ogni componente connessa di un colore
 diverso partendo da 1 e arrivando al numero tot di comp*/
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

void DFS_colora(nodo* n, int comp) {
    n->color = comp;
    elem_archi* la = n->archi;
    while(la != NULL) {
        nodo* altro_nodo = la->info->from;
        if(altro_nodo == n)
            altro_nodo = la->info->to;
        if(altro_nodo->color == 0)
            DFS_colora(altro_nodo, comp);
        la = la->next;
    }
}

int numero_singola_componente(grafo* g, int color) {
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

void aggiungi_nodo(nodo_albero* n, nodo_albero* nuovo) {
    if(n == NULL) { //aggiungi radice
        n = nuovo;
        return;
    }
    if(nuovo->info < n->info) { //aggiungi a sx di n
        if(n->sx != NULL)
            aggiungi_nodo(n->sx, nuovo);
        else
            n->sx = nuovo;
            return;
    }
    if(nuovo->info >= n->info) { //aggiungi a dx di n
        if(n->dx != NULL)
            aggiungi_nodo(n->dx, nuovo);
        else
            n->dx = nuovo;
            return;
    }
    return;
}

/*La funzione restituisce un puntatore a un bst che memorizza le dimensioni delle componenti*/
nodo_albero* abr_da_grafo(grafo* g) {
    if(g == NULL || g->numero_nodi == 0) return 0;
    
    nodo_albero* abr = (nodo_albero*) malloc(sizeof(nodo_albero));
    abr = NULL;
    
    int componenti = numero_comp_connesse(g);
    
    for (int i = 1; i <= componenti; i++) {
        int info = numero_singola_componente(g, i);
        
        nodo_albero* nuovo = (nodo_albero*) malloc(sizeof(nodo_albero));
        nuovo->info = info;
        nuovo->dx = NULL;
        nuovo->sx = NULL;
        
        aggiungi_nodo(abr, nuovo);
    }
    
    return abr;
}

int main() {
    
}
