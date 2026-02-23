#include<stdio.h>
#include<stdlib.h>
#include "FilaEstatica.h"

int main(int argc, char** argv) {

   
    Fila *fi;
    struct numeros num;
    int x,n;


    int continuar = 1;

    do {
        
        printf("\n\tMenu de Opção\n\n");
        printf("1. Cria Fila \n");
        printf("2. Libera Fila\n");
        printf("3. Imprimi o tamanho da fila\n");
        printf("4. Insere na fila\n");
        printf("5. Remove na Fila\n");
        printf("6.Imprimi a Fila\n");
        printf("0.  Sair\n");

        scanf("%d", &continuar);
        system("cls || clear");

        switch (continuar) {
            case 1:
                fi = cria_Fila();
                printf("Fila criada com sucesso!");
                break;

            case 2:
                libera_Fila(fi);
                break;
            case 3:
                x = tamanho_Fila(fi);
                printf("%d", x);
                break;
           case 4:
                printf("Digite um numero a ser inserido na lista:\n");
                scanf("%d",&num.numero);
                if (insere_Fila(fi,num))
                    printf("Numero inserido com sucesso!");
                else
                    printf("Fila Cheia!");
                break;     
           case 5:
              
                if (remove_Fila(fi))
                    printf("Numero removido com sucesso!");
                else
                    printf("Fila Vazia!");
                break;     
           case 6:
               
                imprime_Fila(fi);
                break;
                
            case 0:
                break;
            default:
                printf("Digite uma opção valida\n");
        }
    } while (continuar);


}