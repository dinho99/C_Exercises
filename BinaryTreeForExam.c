#include <stdio.h>
#include <stdlib.h>

/* struttura per l’albero binario */
typedef struct nodo_albero_struct {
    struct nodo_albero_struct* sx;
    struct nodo_albero_struct* dx;
    int info;
} nodo_albero;

/*Test per verificare la parte degli alberi dell'utimo esame (25/01/2023)*/

/*funzione che scorre le dimensioni delle comp connesse, crea per ognuna un nodo e lo inserisce 
 nell'albero con valore info pari a dimensioni[i] */
nodo_albero* crea_abr(int* dim, int length) {
    nodo_albero* n = NULL;
    int i;
    for(i = 0; i<length; i++) {
        if(n == NULL) { //albero senza nodi
            n = (nodo_albero*) malloc(sizeof(nodo_albero));
            n->sx = NULL;
            n->dx = NULL;
            n->info = dim[i];
            printf("Aggiunta la radice dell'albero\n");
        }
        else if(n->dx == NULL && n->sx == NULL) { //albero con solo radice
            nodo_albero* right = (nodo_albero*) malloc(sizeof(nodo_albero));
            n->dx = right;
            right->dx = NULL;
            right->sx = NULL;
            right->info = dim[i];
            printf("Aggiunto nodo dx dell'albero\n");
        }
        else { //albero con almeno due nodi radice e figlio destro
            while(n->sx != NULL) {
                n = n->sx;
            }
            nodo_albero* left = (nodo_albero*) malloc(sizeof(nodo_albero));
            n->sx = left;
            left->sx = NULL;
            left->dx = NULL;
            left->info = dim[i];
        }
    }
    return n;
}

int main() {
    
    printf("Stampa per testare abr:\n");
    
    int dimensioni_componenti[] = {4, 2, 6, 10};
    nodo_albero* output = (nodo_albero*) malloc(sizeof(nodo_albero));

    output = crea_abr(dimensioni_componenti, 4);  
    
    if(output == NULL) {
        printf("Hai sbagliato qualcosa :/\n");
    }
    else if(output->dx == NULL && output->sx == NULL) {
        printf("Solo un nodo:\n");
        printf("campo info 1: %d\n", output->info);
    }
    else if(output->dx != NULL && output->sx == NULL) {
        printf("Solo due nodi:\n");
        printf("campo info 1: %d\n", output->info);
        printf("campo info 2: %d\n", output->dx->info);
    }
    else {
        printf("Almeno tre nodi!\n");
        while(output != NULL) {
            printf("campo info: %d\n", output->info);
            output = output->sx;
        }
    }
    
}
