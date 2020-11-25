

#ifndef _lista_h_
#define _lista_h_

#include <stdlib.h>
#include <stdio.h>

typedef struct no no_t;
typedef struct lista lista_t;

lista_t* lista_cria();

int 	lista_insere_cabeca(lista_t *l, int e);

int 	lista_insere_cauda(lista_t *l, int e);

int 	lista_insere_posicao(lista_t *l, int e, int p);

int 	lista_remove_cabeca(lista_t *l, int *e);

int 	lista_remove_cauda(lista_t *l, int *e);

int 	lista_remove_posicao(lista_t *l, int *e, int p);

void  lista_imprime(lista_t *l);

int 	lista_busca(lista_t *l, int e);

void 	lista_destroi(lista_t **l);

#endif


