typedef struct lista *Lista;
Lista cria_lista();
int lista_vazia(Lista lst);
int lista_cheia(Lista lst);
int insere_ord(Lista lst, int elem);
int remove_ord(Lista lst, int elem);
Lista imprime_lista(Lista lst);
int tamanho(Lista lst);
int menor(Lista lst);
int remover_pares(Lista lst);
Lista intercala(Lista lst1, Lista lst2);
void iguais(Lista lst1, Lista lst2);
