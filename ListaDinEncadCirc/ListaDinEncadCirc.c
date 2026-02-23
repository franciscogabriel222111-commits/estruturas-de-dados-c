
#include <stdio.h>
#include <stdlib.h>
#include "ListaDinEncadCirc.h" //inclui os Protótipos

//Definição do tipo lista
struct elemento{
    struct numeros dados;
    struct elemento *prox;
};
typedef struct elemento Elem;

Lista* cria_lista(){
    Lista* li = (Lista*) malloc(sizeof(Lista));
    if(li != NULL)
        *li = NULL;
    return li;
}

void libera_lista(Lista* li){
    if(li != NULL && (*li) != NULL){
        Elem *aux, *no = *li;
        while((*li) != no->prox){
            aux = no;
            no = no->prox;
            free(aux);
        }
        free(no);
        free(li);
    }
}

int consulta_lista_pos(Lista* li, int pos, struct numeros *num){
    if(li == NULL || (*li) == NULL || pos <= 0)
        return 0;
    Elem *no = *li;
    int i = 1;
    while(no->prox != (*li) && i < pos){
        no = no->prox;
        i++;
    }
    if(i != pos)
        return 0;
    else{
        *num = no->dados;
        return 1;
    }
}

/*int consulta_lista_num(Lista* li, int n, struct numeros *num){
    if(li == NULL || (*li) == NULL)
        return 0;
    Elem *no = *li;
    while(no->prox != (*li) && no->dados.numero != n)
        no = no->prox;
    if(no->dados.numero != n)
        return 0;
    else{
        *num = no->dados;
        return 1;
    }
}
*/
int insere_lista_final(Lista* li, struct numeros num){
    if(li == NULL)
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = num;
    if((*li) == NULL){//lista vazia: insere início
        *li = no;
        no->prox = no;
    }else{
        Elem *aux = *li;
        while(aux->prox != (*li)){
            aux = aux->prox;
        }
        aux->prox = no;
        no->prox = *li;
    }
    return 1;
}

int insere_lista_inicio(Lista* li, struct numeros num){
    if(li == NULL)
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = num;
    if((*li) == NULL){//lista vazia: insere início
        *li = no;
        no->prox = no;
    }else{
        Elem *aux = *li;
        while(aux->prox != (*li)){
            aux = aux->prox;
        }
        aux->prox = no;
        no->prox = *li;
        *li = no;
    }
    return 1;
}

int insere_lista_ordenada(Lista* li, struct numeros num){//TERMINAR
    if(li == NULL)
        return 0;
    Elem *no = (Elem*) malloc(sizeof(Elem));
    if(no == NULL)
        return 0;
    no->dados = num;
    if((*li) == NULL){//insere início
        *li = no;
        no->prox = no;
        return 1;
    }
    else{
        if((*li)->dados.numero > num.numero){//insere início
            Elem *atual = *li;
            while(atual->prox != (*li))//procura o último
                atual = atual->prox;
            no->prox = *li;
            atual->prox = no;
            *li = no;
            return 1;
        }
        Elem *ant = *li, *atual = (*li)->prox;
        while(atual != (*li) && atual->dados.numero < num.numero){
            ant = atual;
            atual = atual->prox;
        }
        ant->prox = no;
        no->prox = atual;
        return 1;
    }
}

int remove_lista_inicio(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;

    if((*li) == (*li)->prox){//lista fica vaza
        free(*li);
        *li = NULL;
        return 1;
    }
    Elem *atual = *li;
    while(atual->prox != (*li))//procura o último
        atual = atual->prox;

    Elem *no = *li;
    atual->prox = no->prox;
    *li = no->prox;
    free(no);
    return 1;
}

int remove_lista_final(Lista* li){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;

    if((*li) == (*li)->prox){//lista fica vaza
        free(*li);
        *li = NULL;
        return 1;
    }
    Elem *ant, *no = *li;
    while(no->prox != (*li)){//procura o último
        ant = no;
        no = no->prox;
    }
    ant->prox = no->prox;
    free(no);
    return 1;
}

int remove_lista(Lista* li, int n){
    if(li == NULL)
        return 0;
    if((*li) == NULL)//lista vazia
        return 0;
    Elem *no = *li;
    if(no->dados.numero == n){//remover do início
        if(no == no->prox){//lista fica vaza
            free(no);
            *li = NULL;
            return 1;
        }else{
            Elem *ult = *li;
            while(ult->prox != (*li))//procura o último
                ult = ult->prox;
            ult->prox = (*li)->prox;
            *li = (*li)->prox;
            free(no);
            return 1;
        }
    }
    Elem *ant = no;
    no = no->prox;
    while(no != (*li) && no->dados.numero != n){
        ant = no;
        no = no->prox;
    }
    if(no == *li)//não encontrado
        return 0;

    ant->prox = no->prox;
    free(no);
    return 1;
}

int tamanho_lista(Lista* li){
    if(li == NULL || (*li) == NULL)
        return 0;
    int cont = 0;
    Elem* no = *li;
    do{
        cont++;
        no = no->prox;
    }while(no != (*li));
    return cont;
}

int lista_cheia(Lista* li){
    return 0;
}

int lista_vazia(Lista* li){
    if(li == NULL)
        return 1;
    if(*li == NULL)
        return 1;
    return 0;
}

void imprime_lista(Lista* li){
    if(li == NULL || (*li) == NULL)
        return;
    Elem* no = *li;
    do{
        printf("Número: %d\n",no->dados.numero);
        
        printf("-------------------------------\n");
        no = no->prox;
    }while(no != (*li));
}

