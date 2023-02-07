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

/*La funzione restituisce 1 se il numero di nodi dell’albero a che hanno un solo
figlio sono tanti quanti sono i nodi della componente più piccola del grafo g,
altrimenti la funzione restituisce 0. Se uno (o entrambi) tra grafo e albero è
vuoto (cioè uguali a NULL) la funzione ritorna 0.*/
int nodi_con_solo_un_figlio(nodo_albero* a) {
    if(a == NULL) return 0;
    int count = 0;
    if((a->dx != NULL && a->sx == NULL) || (a->dx == NULL && a->sx != NULL)) //se a ha solo un figlio
        count ++;
    return count + nodi_con_solo_un_figlio(a->sx) + nodi_con_solo_un_figlio(a->dx);
}

int componente_minima(grafo* g) {
    elem_nodi* ln = g->nodi;
    while(ln != NULL) {
        ln->info->color = 0;
        ln = ln->next;
    }
    ln = g->nodi;
    int comp_min = DFS_size(ln->info);
    while(ln != NULL) {
        if(ln->info->color == 0) {
            int min = DFS_size(ln->info);
            if(min < comp_min)
                comp_min = min;
        }
        ln = ln->next;
    }
    return comp_min;
}

int DFS_size(nodo* n) {
    int count = 1;
    n->color = 1;
    elem_archi* la = n->archi;
    while(la != NULL) {
        nodo* nuovo_nodo = nodo_opposto(n, la->info);
        if(nuovo_nodo->color == 0)
            count += DFS_size(nuovo_nodo);
        la = la->next;
    }
    return count;
}

nodo* nodo_opposto(nodo* n, arco* a) {
    if(a->to == n) return a->from;
    return a->to;
}

int verifica(nodo_albero* a, grafo* g) {
    if(a == NULL || g == NULL) return 0;
    return nodi_con_solo_un_figlio(a) == componente_minima(g);
}


int main()
{
    printf("Hello World");

}
