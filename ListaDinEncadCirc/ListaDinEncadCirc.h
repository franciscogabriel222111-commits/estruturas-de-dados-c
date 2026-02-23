
//Arquivo ListaDinEncadCirc.h

struct numeros{
    int numero;
  
};

typedef struct elemento* Lista;

Lista* cria_lista();
void libera_lista(Lista* li);
int consulta_lista_pos(Lista* li, int pos, struct numeros *num);
int consulta_lista_num(Lista* li, int mat, struct numeros *num);
int insere_lista_final(Lista* li, struct numeros num);
int insere_lista_inicio(Lista* li, struct numeros num);
int insere_lista_ordenada(Lista* li, struct numeros num);
int remove_lista(Lista* li, int n);
int remove_lista_inicio(Lista* li);
int remove_lista_final(Lista* li);
int tamanho_lista(Lista* li);
int lista_vazia(Lista* li);
void imprime_lista(Lista* li);
