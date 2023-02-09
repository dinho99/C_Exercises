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
    elem_archi* frompos; // pos. arco nodo from
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
}nodo_albero;

/*Algoritmo*/
int dimensione_componente_minima(grafo* g) {
    elem_nodi* ln = g->nodi;
    while(ln != NULL) {
        ln->info->color = 0;
        ln = ln->next;
    }
    
    ln = g->nodi;
    int comp_min = DFS_size(ln->info);
    while(ln != NULL) {
        if(ln->info->color == 0) {
            int new_size = DFS_size(ln->info);
            if(new_size < comp_min)
                comp_min = new_size;
        }
        ln = ln->next;
    }
    return comp_min;
}

int DFS_size(nodo* n) {
    n->color = 1;
    int count = 1;
    elem_archi* la = n->archi;
    while(la != NULL) {
        nodo* nuovo_nodo = la->info->from;
        if(nuovo_nodo == n)
            nuovo_nodo = la->info->to;
        if(nuovo_nodo->color == 0)
            count += DFS_size(nuovo_nodo);
        la = la->next;
    }
    return count;
}

int numero_sottoalberi_prof(nodo_albero* a, int h) {
    if(a == NULL) return 0;
    int out = numero_sottoalberi_prof(a->sx, h) + numero_sottoalberi_prof(a->dx, h);
    if(prof_albero(a) == h)
        out ++;
    return out;
}

int prof_albero(nodo_albero* a) {
    if(a == NULL) return -1;
    int l = prof_albero(a->sx);
    int r = prof_albero(a->dx);
    if(l>r) return l+1;
    return r+1;
}

/*La funzione restituisce 1 se il numero di nodi dell’albero a che sono radici
 di un sottoalbero di profondità h sono tanti quanti sono i nodi della componente
 più piccola del grafo g, altrimenti la funzione restituisce 0.*/
int verifica(int h, nodo_albero* a, grafo* g) {
    if(g == NULL && a == NULL) return 1;
    if(g == NULL && a != NULL) return 0;
    if(g != NULL && a == NULL) return 0;
    return numero_sottoalberi_prof(a, h) == dimensione_componente_minima(g);
}

int main()
{
    
}
