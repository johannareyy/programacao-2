#ifndef _fila_
#define _fila_

#include <stdio.h>
#include <stdlib.h>

typedef struct fila fila_t;

fila_t* 	fila_cria(int capacidade);
void		fila_destroi(fila_t **f);
int 		fila_enfileira(fila_t *f, char dado);
int 		fila_desenfileira(fila_t *f, char *dado);
int 		fila_frente(fila_t *f, char *dado);
void 		fila_imprime(fila_t *f);
int 		fila_tamanho(fila_t *f);
int 		fila_cheia(fila_t *f);

#endif
