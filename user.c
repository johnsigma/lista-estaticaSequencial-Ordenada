#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include "lista.h"

int main(){

setlocale(LC_ALL, "Portuguese_Brazil");

    Lista lista1,lst1,lst2,lst3,lst4;
    lista1=cria_lista();
    lst1=cria_lista();
    lst2=cria_lista();
    lst3=cria_lista();
    lst4=cria_lista();

    if(lista1==NULL){
        printf("Não foi possível criar a lista!");
        return -1;
    }

    tamanho(lista1);
    imprime_lista(lista1);

    insere_ord(lista1,4);
    insere_ord(lista1,8);
    insere_ord(lista1,0);
    insere_ord(lista1,19);
    insere_ord(lista1,2);
    insere_ord(lista1,7);
    insere_ord(lista1,9);
    insere_ord(lista1,22);
    insere_ord(lista1,8);

    tamanho(lista1);
    imprime_lista(lista1);

    remover_pares(lista1);
    tamanho(lista1);
    imprime_lista(lista1);

    menor(lista1);
    tamanho(lista1);
    imprime_lista(lista1);

    remove_ord(lista1,8);

    menor(lista1);
    tamanho(lista1);
    imprime_lista(lista1);

    lista1=cria_lista();

    tamanho(lista1);
    imprime_lista(lista1);

    free(lista1);

    printf("\n\n\n");


    insere_ord(lst1,6);
    insere_ord(lst2,60);
    insere_ord(lst1,12);
    insere_ord(lst2,-9);



    Lista lst5=intercala(lst1,lst2);

    imprime_lista(lst5);

    insere_ord(lst3,4);
    insere_ord(lst3,5);
    insere_ord(lst3,6);
    insere_ord(lst3,0);
    insere_ord(lst3,1);

    insere_ord(lst4,0);
    insere_ord(lst4,5);
    insere_ord(lst4,6);
    insere_ord(lst4,4);
    insere_ord(lst4,1);

    iguais(lst3,lst4);

    free(lista1);
    free(lst1);
    free(lst2);
    free(lst3);
    free(lst4);

    return 0;
}
