#include <stdio.h>
#include <stdlib.h>
#include "lista.h"
#define max 10

struct lista{
    int no[max];
    int fim;
};

Lista cria_lista(){
    Lista lst;
    lst = (Lista) malloc(sizeof(struct lista));

    if(lst != NULL){
        lst->fim = 0;
    }
    return lst;
}

int lista_vazia(Lista lst){
    if(lst->fim==0)
        return 1; //lista vazia
    else
        return 0; //lista NÃO vazia
}

int lista_cheia(Lista lst){
    if(lst->fim==max)
        return 1; //lista cheia
    else
        return 0; //lista NÃO cheia
}

int insere_ord(Lista lst, int elem){
    if(lst==NULL || lista_cheia(lst)==1)
        return 0; //falha
    //trata lista vazia ou elemento >= último da lista
    if(lista_vazia(lst)==1 || elem>=lst->no[lst->fim-1]){
        lst->no[lst->fim]=elem; //insere no final
    }
    else{
        int i, aux=0;
        while(elem>=lst->no[aux]) //percorrimento
            aux++;
        for(i=lst->fim;i>aux;i--) //deslocamento
            lst->no[i]=lst->no[i-1];
        lst->no[aux]=elem; //inclui o elemento na lista
    }
    lst->fim++; //avança o fim
    return 1; //sucesso na inserção
}

int remove_ord(Lista lst, int elem){
    if(lst==NULL || lista_vazia(lst)==1 || elem<lst->no[0] || elem>lst->no[lst->fim-1])
        return 0; //falha
    int i, aux=0;
    //percorre até achar o elem ou nó maior, ou final de lista
    while(aux<lst->fim && lst->no[aux]<elem)
        aux++;
    if(aux==lst->fim || lst->no[aux]>elem)
        return 0; //falha
    //deslocamento a esquerda do sucessor até o final da lista
    for(i=aux+1;i<lst->fim;i++)
        lst->no[i-1]=lst->no[i];
    lst->fim--; //decremento do fim
    return 1; //sucesso na remoção
}

Lista imprime_lista(Lista lst){
    int i;
    if(lst->fim<=0)
        printf("Lista vazia!\n\n");
    else{
        printf("Lista: ");
        for(i=0;i<lst->fim;i++){
            printf("%d ", lst->no[i]);
        }
        printf("\n\n");
    }
}

int tamanho(Lista lst){
    printf("Tamanho da lista: %d\n",lst->fim);
}

int menor(Lista lst){
    int i, aux=0, menor;
    menor=lst->no[0];
    while(menor<lst->no[aux]) //percorrimento
        aux++;
    for(i=aux+1;i<lst->fim;i++)
        lst->no[i-1]=lst->no[i];
    lst->fim--; //decremento do fim
    return 1;
}

int remover_pares(Lista lst){
    if(lst==NULL || lista_vazia(lst)==1)
        return 0;

    int i, Aux=0;

    while(Aux<lst->fim){
        if((lst->no[Aux]%2)==0){
            for(i=Aux+1;i<lst->fim;i++)
                lst->no[i-1]=lst->no[i];
            lst->fim--;
        }
        if(lst->no[Aux]%2!=0)
            Aux++;
    }

    return 1;
}

Lista intercala(Lista lst1, Lista lst2){

    if((lst1->fim+lst2->fim)>max){
        printf("Tamanho maior que max!\n");
        return 0;
    }

    Lista lst3= cria_lista();
    if(lst3==NULL)
        return 0;
    int i;
    int aux1=0;
    int aux2=0;

    while(aux1<lst1->fim && aux2<lst2->fim){
        if(lst1->no[aux1]<=lst2->no[aux2]){
            lst3->no[lst3->fim]=lst1->no[aux1];
            lst3->fim++;
            aux1++;
        }else{
            lst3->no[lst3->fim]=lst2->no[aux2];
            lst3->fim++;
            aux2++;
        }
    }

    while(aux1<lst1->fim){
        lst3->no[lst3->fim]=lst1->no[aux1];
        lst3->fim++;
        aux1++;
    }

    while(aux2<lst2->fim){
        lst3->no[lst3->fim]=lst2->no[aux2];
        lst3->fim++;
        aux2++;
    }

    return lst3;
}

void iguais(Lista lst1, Lista lst2){
    int i, j;

    for(i=0;i<lst1->fim;i++){
        if(lst1->no[i]!=lst2->no[i])
           return printf("\nAs listas não são iguais!\n");
    }

    return printf("\nAs listas são iguais!\n");
}
