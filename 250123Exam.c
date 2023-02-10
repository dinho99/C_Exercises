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

/*Restituisce un puntatore alla radice di un albero binario di ricerca che 
memorizza il numero dei nodi delle componenti connesse di g*/

/*Restituisce numero di nodi colorati di un colore passato per parametro
 ovvero restituisce numero di nodi appartenenti a una componente connessa del grafo
 poiché i nodi connessi hanno lo stesso colore*/
int dimensione_componente_connessa(grafo* g, int comp) {
    int numero_nodi = 0;
    elem_nodi* ln = g->nodi;
    while(ln != NULL) {
        if(ln->info->color == comp) {
            numero_nodi += 1;
        }
        ln = ln->next;
    }
    return numero_nodi;
}

/*Colora tutti i nodi connessi a quello passato per parametro del colore passato per parametro*/
void DFS_colora(nodo* n, int color) {
    n->color = color;
    elem_archi* la = n->archi;
    while(la != NULL) {
        nodo* altro_nodo = nodo_opposto(n, la->info);
        if(altro_nodo == 0) {
            DFS_colora(altro_nodo, color);
        }
        la = la->next;
    }
}

nodo* nodo_opposto(nodo* n, arco* a) {
    if(a->to == n) return a->from;
    return a->to;
}

void aggiungi_nodo(nodo_albero* abr, nodo_albero* nodo_nuovo) {
    if(abr == NULL) { //albero output vuoto -> aggiungi radice
        abr = nodo_nuovo;
        return;
    }
    if(nodo_nuovo->info < abr->info) {
        if(abr -> sx != NULL) // se abr ha figlio sinistro
            aggiungi_nodo(abr->sx, nodo_nuovo);
        else // nessun figlio a sx
            abr->sx = nodo_nuovo;
            return;
    }
    if(nodo_nuovo->info >= abr->info) {
        if(abr -> dx != NULL) // se abr ha figlio sinistro
            aggiungi_nodo(abr->dx, nodo_nuovo);
        else // nessun figlio a sx
            abr->dx = nodo_nuovo;
            return;
    }
    return;
}

nodo_albero* abr_da_grafo(grafo* g) {
    if(g == NULL || g->numero_nodi == 0) return 0;
    
    elem_nodi* ln = g->nodi;
    while(ln != NULL) {
        ln->info->color = 0;
        ln = ln->next;
    }
    
    ln = g->nodi;
    int comp = 0; //numero delle componenti connesse
    while(ln != NULL) {
        if(ln->info->color == 0) {
            comp ++; //se color = 0 incontro nodo appartenente a comp connessa non visitata quindi incremento n. comp
            DFS_colora(ln->info, comp); //colora il nodo passato e tutti i nodi connessi con quello passato
        }
        ln = ln->next;
    }
    
    int c; //colore componente connessa
    nodo_albero* output = (nodo_albero*) malloc(sizeof(nodo_albero));
    for(c = 1; c <= comp; c ++) {
        int info = dimensione_componente_connessa(g, c);
        nodo_albero* nuovo = (nodo_albero*) calloc(1, sizeof(nodo_albero));
        nuovo->info = info;
        aggiungi_nodo(output, nuovo);
    }
    
    return output;
}

int main() {
}
