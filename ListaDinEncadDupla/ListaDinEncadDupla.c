#include<stdio.h>
#include<stdlib.h>
#include "C:\Users\franc\OneDrive\Desktop\estdadossegundavaliac\ListaDinEncadDupla\ListaDinEncadDupla.h"

struct elemento {
    struct elemento *ant;
    struct numeros dados;
    struct elemento *prox;
};

typedef struct elemento Elem;


//funçao que cria a lista

Lista * cria_lista() {
    Lista * li = (Lista*) malloc(sizeof (Lista));
    if (li != NULL)
        *li = NULL;
    return li;
}

//funçao eu libera lista da memória

void libera_lista(Lista *li) {
    if (li != NULL) {
        Elem *no;
        while ((*li) != NULL) {
            no = *li;
            *li = (*li)->prox;
            free(no);
        }
        free(li);
    }
}
//função que retorna o tamanho da lista

int tamanho_lista(Lista *li) {
    if (li == NULL)
        return 0;
    int cont = 0;
    Elem* no = *li;
    while (no != NULL) {
        cont++;
        no = no->prox;
    }
    return cont;
}

//funçao que verifica se a lista está vazia

int lista_vazia(Lista *li) {
    if (li == NULL)
        return 1;
    if (*li == NULL)
        return 1;
    return 0;
}
//funcao que insere no inicio da lista

int insere_lista_inicio(Lista *li, struct numeros num) {
    if (li == NULL)
        return 0;
    Elem * no = (Elem*) malloc(sizeof (Elem));
    if (no == NULL)
        return 0;
    no->dados = num;
    no->prox = (*li);
    no->ant = NULL;
    //lista não vazia: apontar para o anterior!
    if (*li != NULL)
        (*li)->ant = no;
    *li = no;
    return 1;
}
//funcao que imprime a lista

void imprime_lista(Lista *li) {
    if (li == NULL || (*li) == NULL)
        printf("\nLista vazia!");

    else {
        Elem *ant, *atual = *li;

        while (atual != NULL) {
            printf("\n%d\n", atual->dados.numero);
            ant = atual;
            atual = atual->prox;
        }
    }

}

//função que insere no final da lista

int insere_lista_final(Lista* li, struct numeros num) {
    if (li == NULL)
        return 0;
    Elem * no = (Elem*) malloc(sizeof (Elem));
    if (no == NULL)
        return 0;
    no->dados = num;
    no->prox = NULL;
    if (*li == NULL) {//lista vazia: insere inicio!
        no->ant = NULL;
        *li = no;
    } else {
        Elem *aux = *li;
        while (aux->prox != NULL)
            aux = aux->prox;
        aux -> prox = no;
        no->ant = aux;
    }
    return 1;
}
//função que insere numa lista ordenada

int insere_lista_ordenada(Lista* li, struct numeros num){
    if(li == NULL)
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = num;
    if((*li) == NULL){//lista vazia: insere início
        no->prox = NULL;
        no->ant = NULL;
        *li = no;
        return 1;
    }
    else{
        Elem *ante, *atual = *li;
        while(atual != NULL && atual->dados.numero < num.numero){
            ante = atual;
            atual = atual->prox;
        }
        if(atual == *li){//insere início
            no->ant = NULL;
            (*li)->ant = no;
            no->prox = (*li);
            *li = no;
        }else{
            no->prox = ante->prox;
            no->ant = ante;
            ante->prox = no;
            if(atual != NULL)
                atual->ant = no;
        }
        return 1;
    }
}
//funçao que remove no inicio da lista
int remove_lista_inicio(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;

    Elem *no = *li;
    *li = no->prox;
    if(no->prox != NULL)
        no->prox->ant = NULL;

    free(no);
    return 1;
}


//função que remove no final da lista

int remove_lista_final(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;

    Elem *no = *li;
    while(no->prox != NULL)
        no = no->prox;

    if(no->ant == NULL)//remover o primeiro e único
        *li = no->prox;
    else
        no->ant->prox = NULL;

    free(no);
    return 1;
}

//remove em qualquer posição da lista

int remove_lista(Lista* li, int numero){//TERMINAR
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;
    Elem *no = *li;
    while(no != NULL && no->dados.numero != numero){
        no = no->prox;
    }
    if(no == NULL)//não encontrado
        return 0;

    if(no->ant == NULL)//remover o primeiro?
        *li = no->prox;
    else
        no->ant->prox = no->prox;

    if(no->prox != NULL)//não é o último?
        no->prox->ant = no->ant;

    free(no);
    return 1;
}

//função que busca elemento por posição.

int consulta_lista_pos(Lista *li, int pos, struct numeros *num){
	if(li==NULL || pos <=0) 
		return 0;
	Elem *no = *li;
	int i = 1;
	while(no !=NULL && i<pos){
		no=no->prox;
		i++;
	}
	if(no==NULL)
		return 0;
	else{
		*num=no->dados;
                printf("O numero %d foi localizado na posição %d",no->dados.numero,i);
		return 1;
	}
}

int consulta_lista_num(Lista* li, int n, struct numeros *num) {
    if (li == NULL)
        return 0;
    Elem *no = *li;
    int cont = 1;
    while (no != NULL && no->dados.numero != n) {
        no = no->prox;
        cont++;
    }
    if (no == NULL)
        return 0;
    else {
        *num = no->dados;
        printf("O numero %d foi encontrado na posicao %d", no->dados.numero, cont);
        return 1;
    }
}





