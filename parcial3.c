#include <stdio.h>
#include <stdlib.h>

struct nodo{

    struct nodo* hijo_izq;
    struct nodo* hijo_der;
    struct nodo* num;
    int dato;
};

struct nodo* raiz = NULL;

struct nodo* nuevoNodo(int dato){
    size_t tam_nodo = sizeof(struct nodo);
    struct nodo* nuevo_nodo = (struct nodo*) malloc(tam_nodo);
    nuevo_nodo -> dato = dato;
    nuevo_nodo -> hijo_izq = NULL;
    nuevo_nodo -> hijo_der = NULL;
    return nuevo_nodo;
}

void insertarNodo(struct nodo* nd, int dato){
    if(dato > nd->dato){
        if(nd -> hijo_der == NULL){
            nd -> hijo_der = nuevoNodo(dato);
        }else{
            insertarNodo(nd -> hijo_der, dato);
        }
    }else{
        if(nd -> hijo_izq == NULL){
            nd -> hijo_izq = nuevoNodo(dato);
        }else{
            insertarNodo(nd -> hijo_izq, dato);
        }
    }
}

void imprimirPre(struct nodo* nd){

    if (nd != NULL){
        printf("%i-", nd->dato);
        imprimirPre(nd -> hijo_izq);
        imprimirPre(nd -> hijo_der);
    }

}

void imprimirEntre(struct nodo* nd){
    if (nd != NULL){
        imprimirEntre(nd -> hijo_izq);
        printf("%i-", nd->dato);
        imprimirEntre(nd -> hijo_der);
    }

}

void imprimirPost(struct nodo* nd){
    if (nd != NULL){
        imprimirPost(nd -> hijo_izq);
        imprimirPost(nd -> hijo_der);
        printf("%i-", nd->dato);
    }

}


void imprimirEntreNivel(struct nodo* nd, int nivel){
    if (nd != NULL){
        imprimirEntreNivel(nd -> hijo_izq, nivel + 1);
        printf("%i(%i) - ", nd->dato, nivel);
        imprimirEntreNivel(nd -> hijo_der, nivel + 1);
    }
}

void valorMayor(){
    if(raiz != NULL){
        struct nodo* nd = raiz;
        while(nd->hijo_der != NULL){
            nd = nd->hijo_der;
        }
        printf("El mayor valor del arbol es: %i\n\n", nd -> dato);
    }
}

void valorMenor(){
    if(raiz != NULL){
        struct nodo* nd = raiz;
        while(nd->hijo_izq != NULL){
            nd = nd->hijo_izq;
        }
        printf("El menor valor del arbol es: %i\n\n", nd -> dato);
    }
}

void alturaArbol(struct nodo* nd, int nivel, int *altura){
    if(nd != NULL){
        alturaArbol(nd -> hijo_izq, nivel + 1, altura);
        if(nivel>*altura){
            *altura = nivel;
        }
        alturaArbol(nd -> hijo_der, nivel + 1, altura);
    }
}


void busqueda(struct nodo* nd){

    int num = 0;

    if(nd!= NULL){

        printf("Ingrese el nodo que desea buscar: ");
        scanf("%d", &num);
        printf("\n\n");

        if(nd -> dato == num){
            printf("Su dato existe");
        }else{
            printf("Su dato no existe");
        }

        printf("\n\n");
    }
}

int main(){

    int cant = 0;
    int altura = 0;

    raiz = nuevoNodo(6);

    insertarNodo(raiz, 5);
    insertarNodo(raiz, 11);
    insertarNodo(raiz, 4);
    insertarNodo(raiz, 8);
    insertarNodo(raiz, 12);
    insertarNodo(raiz, 3);
    insertarNodo(raiz, 4);
    insertarNodo(raiz, 21);

    printf("\n\n");
    printf("Arbol en Pre-orden \n\n");
    imprimirPre(raiz);
    printf("\n\n");
    printf("Arbol en In-orden \n\n");
    imprimirEntre(raiz);
    printf("\n\n");
    printf("Arbol en Post-orden \n\n");
    imprimirPost(raiz);
    printf("\n\n");
    printf("Arbol en In-orden con niveles\n\n");
    imprimirEntreNivel(raiz, 1);
    printf("\n\n");
    alturaArbol(raiz, 1, &altura);
    printf("La altura del arbol es de: %i\n", altura);
    printf("\n");
    valorMayor();
    valorMenor();
    busqueda(raiz);

    return 0;
}