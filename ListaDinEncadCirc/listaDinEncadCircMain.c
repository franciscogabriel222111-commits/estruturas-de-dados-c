#include<stdio.h>
#include<stdlib.h>
#include "ListaDinEncadCirc.h"

int main(int argc, char** argv) {

   
    Lista *li;
    struct numeros num;
    int x,n;


    int continuar = 1;

    do {
        
        printf("\n\tMenu de Opção\n\n");
        printf("1. Cria Lista \n");
        printf("2. Libera lista\n");
        printf("3. Imprimi o tamanho da lista\n");
        printf("4. Insere no inicio da lista\n");
        printf("5. Insere no final da lista\n");
        printf("6. Insere no meio da lista\n");
        printf("7. Remove do inicio da Lista\n");
        printf("8. Remove no final da lista\n");
        printf("9. Remove e qualquer posição da lista\n");
        printf("10.Imprimi a lista\n");
        printf("0.  Sair\n");

        scanf("%d", &continuar);
        system("cls || clear");

        switch (continuar) {
            case 1:
                li = cria_lista();
                printf("Lista criada com sucesso!");
                break;

            case 2:
                libera_lista(li);
                break;
            case 3:
                x = tamanho_lista(li);
                printf("%d", x);
                break;
           case 4:
                printf("Digite um numero a ser inserido na lista:\n");
                scanf("%d",&num.numero);
                if (insere_lista_inicio(li,num))
                    printf("Numero inserido com sucesso!");
                else
                    printf("Não foi possivel inserir o numero!");
                break;     
           case 5:
                printf("Digite um numero a ser inserido na lista:\n");
                scanf("%d",&num.numero);
                if (insere_lista_final(li,num))
                    printf("Numero inserido com sucesso!");
                else
                    printf("Não foi possivel inserir o numero!");
                break;     
           case 6:
                printf("Digite um numero a ser inserido na lista:\n");
                scanf("%d",&num.numero);
                if (insere_lista_ordenada(li,num))
                    printf("Numero inserido com sucesso!");
                else
                    printf("Não foi possivel inserir o numero!");
                break;
            case 7:
                if(remove_lista_inicio(li))
                    printf("Numero deletado da lista!");
                else
                    printf("Lista vazia!");
                break;
                
            case 8:
                if(remove_lista_final(li))
                    printf("Numero deletado da lista!");
                else
                    printf("Lista vazia!");
                break; 
            case 9:
                printf("Digite o numero a ser deletado da lista:\n");
                scanf("%d",&n);
                if(remove_lista(li,n))
                    printf("Numero deletado da lista!");
                else
                    printf("Número não localizado na lista!");
                break;      
                
            case 10:
                imprime_lista(li);
                break;
                
            case 0:
                break;
            default:
                printf("Digite uma opção valida\n");
        }
    } while (continuar);


}