#include<stdio.h>
#include<stdlib.h>
#include "PilhaDin.h"

int main(int argc, char** argv) {

   
    Pilha *pi;
    struct numeros num;
    int x,n;


    int continuar = 1;

    do {
        
        printf("\n\tMenu de Opção\n\n");
        printf("1. Cria Pilha \n");
        printf("2. Libera Pilha\n");
        printf("3. Imprimi o tamanho da Pilha\n");
        printf("4. Insere na Pilha\n");
        printf("5. Remove na Pilha\n");
        printf("6.Imprimi a Pilha\n");
        printf("0.  Sair\n");

        scanf("%d", &continuar);
        system("cls || clear");

        switch (continuar) {
            case 1:
                pi = cria_Pilha();
                printf("Pilha criada com sucesso!");
                break;

            case 2:
                libera_Pilha(pi);
                break;
            case 3:
                x = tamanho_Pilha(pi);
                printf("%d", x);
                break;
           case 4:
                printf("Digite um numero a ser inserido na Pilha:\n");
                scanf("%d",&num.numero);
                if (insere_Pilha(pi,num))
                    printf("Numero inserido com sucesso!");
                else
                    printf("Pilha Cheia!");
                break;     
           case 5:
              
                if (remove_Pilha(pi))
                    printf("Numero removido com sucesso!");
                else
                    printf("Pilha Vazia!");
                break;     
           case 6:
               
                imprime_Pilha(pi);
                break;
                
            case 0:
                break;
            default:
                printf("Digite uma opção valida\n");
        }
    } while (continuar);


}