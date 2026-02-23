struct numeros{
	int numero;

};

typedef struct elemento* Lista;


//funçao que cria a lista
Lista * cria_lista();
//funçao eu libera lista da memória
void libera_lista(Lista *li);
//funçao que verifica o tamanho da lista
int tamanho_lista(Lista *li);
//funçao que verifica se a lista está vazia
int lista_vazia(Lista *li);
//funçao que insere no inicio da lista
int insere_lista_inicio(Lista *li, struct numeros num);
//função que insere no final da lista
int insere_lista_final(Lista* li, struct numeros num);
//insere numa lista ordenada
int insere_lista_ordenada(Lista* li, struct numeros num);
//funçao que imprime a lista
void imprime_lista(Lista *li);
//funçao que remove no inicio da lista 
int remove_lista_inicio(Lista* li);
//funçao que remove no final da lista
int remove_lista_final(Lista* li);
//remove em qualquer posição da lista
int remove_lista(Lista* li, int numero);
//busca elemento por posição.
int consulta_lista_pos(Lista* li, int pos, struct numeros *num);

int consulta_lista_num(Lista* li, int n, struct numeros *num);





