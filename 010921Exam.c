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

/* struttura per l’albero binario */
typedef struct nodo_albero_struct {
    struct nodo_albero_struct* sx;
    struct nodo_albero_struct* dx;
    int info;
}nodo_albero;

/*=================================================*/

/*Funziona che torna l'altezza della foglia meno profonda*/
int foglia_meno_profonda(nodo_albero* t) {

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

int dimensione_componente_minima(grafo* g) {
    elem_nodi* ln = g->nodi;
    while(ln != NULL) {
        ln->info->color = 0;
        ln = ln->next;
    }
    ln = g->nodi;
    int min_nodi = DFS_size(ln->info);
    while(ln != NULL) {
        if(ln->info->color == 0) {
            int new_size = DFS_size(ln->info);
            if(new_size < min_nodi) min_nodi = new_size;
        }
        ln = ln->next;
    }
    return min_nodi;
}

int DFS_size(nodo* n) {
    n->color = 1;
    int count = 1;
    elem_archi* la = n->archi;
    while(la!=NULL) {
        nodo* altro_nodo = la->info->to;
        if(altro_nodo == n) altro_nodo = la->info->from;
        if(altro_nodo->color == 0)
            count += DFS_size(altro_nodo);
        le = le->next;
    }
    return count;
}

int verifica(grafo* g, nodo_albero* a) {
    if(g==NULL || a==NULL) return 0;
    if(foglia_meno_profonda(a) == dimensione_componente_minima(g))
        return 1;
    return 0;
}

int main() {}
