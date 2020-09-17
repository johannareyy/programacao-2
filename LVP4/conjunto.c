#include "conjunto_privado.h"
#include <stdio.h>
#include <stdlib.h>

// Coloque aqui a implementacao das funcoes

conjunto_t *conjunto_cria(void){
    conjunto_t *a=(conjunto_t*)malloc(sizeof(conjunto_t));
    if(!a) return NULL;
    (*a).vetor=(elem_t*)malloc(sizeof(elem_t)*ELEMENTOS);
    (*a).capacidade=10;
    (*a).numero=0;
    if((*a).vetor==NULL){
		free(a);
		return NULL;
    }
    return a;
}

void conjunto_destroi(conjunto_t **a){
	if(!a) return;
	free((**a).vetor);
	free(*a);
	*a=NULL;
	return;
}


int conjunto_numero_elementos(conjunto_t *a){
    if(!a) return -1;
    return (*a).numero;
}

void conjunto_inicializa_vazio(conjunto_t *a){
    if(!a) return;
    (*a).numero=0;
    return;
}


void conjunto_uniao(conjunto_t *a, conjunto_t *b, conjunto_t *c){
    if(!a) return;
    if(!b) return;
    if(!c) return;
    for(unsigned int i=0;i<(*a).numero;i++){
        conjunto_insere_elemento((*a).vetor[i],c);
    }
    for(unsigned int i=0;i<(*b).numero;i++){
        conjunto_insere_elemento((*b).vetor[i],c);
    }
    return;
}


void conjunto_interseccao(conjunto_t *a, conjunto_t *b, conjunto_t *c){
    if(!a) return;
    if(!b) return;
    if(!c) return;
    conjunto_inicializa_vazio(c);
    for(unsigned int i=0;i<(*a).numero;i++){
        for(unsigned int j=0;j<(*b).numero;j++){
            if((*a).vetor[i]==(*a).vetor[j]){
                conjunto_insere_elemento((*a).vetor[i],c);
            }
        }
    }
    return;
}


void conjunto_diferenca(conjunto_t *a, conjunto_t *b, conjunto_t *c){
    if(!a) return;
    if(!b) return;
    if(!c) return;
    conjunto_inicializa_vazio(c);
    for(unsigned int i=0;i<(*a).numero;i++){
        if(!conjunto_membro((*a).vetor[i],b)) conjunto_insere_elemento((*a).vetor[i],c);
    }
     for(unsigned int i=0;i<(*b).numero;i++){
        if(!conjunto_membro((*b).vetor[i],a)) conjunto_insere_elemento((*b).vetor[i],c);
    }
    return;
}


int conjunto_membro(elem_t x, conjunto_t *a){
    if(!a) return 0;
    for(unsigned int i=0;i<(*a).numero;i++){
        if(x==(*a).vetor[i]) return 1;
    }
    return 0;
}


int conjunto_insere_elemento(elem_t x, conjunto_t *a){
    if(!a) return 0;
    if(conjunto_membro(x,a)) return 1;
    if((*a).numero==(*a).capacidade){
        (*a).vetor=realloc((*a).vetor, sizeof(elem_t)*((*a).capacidade+1));
        (*a).capacidade++;
    }
    (*a).vetor[(*a).numero]=x;
    (*a).numero++;
    return 1;
}


void conjunto_remove_elemento(elem_t x, conjunto_t *a){
    if(!a) return;
    if(!conjunto_membro(x,a)) return;
    int aux;
    for(unsigned int i=0;i<(*a).numero;i++) if(x==(*a).vetor[i]) aux=i;
    for(unsigned int j=aux;j<(*a).numero-1;j++){
        (*a).vetor[j]=(*a).vetor[j+1];
    }
    (*a).capacidade--;
    (*a).vetor=realloc((*a).vetor,sizeof(elem_t)*(*a).capacidade);
    (*a).numero--;
    return;
}


void conjunto_atribui(conjunto_t *a, conjunto_t *b){
    if(!a) return;
    if(!b) return;
    for(unsigned int i=0;i<(*b).numero;i++){
        conjunto_remove_elemento((*b).vetor[i],b);
    }
    for(unsigned int i=0;i<(*a).numero;i++){
        conjunto_insere_elemento((*a).vetor[i],b);
    }
    (*b).numero=(*a).numero;
    return;
}


int conjunto_igual(conjunto_t *a, conjunto_t *b){
    if(!a) return 0;
    if(!b) return 0;
    if((*a).numero!=(*b).numero) return 0;
    //int aux=0;
    for(unsigned int i=0;i<(*a).numero;i++){
        if((*a).vetor[i]!=(*b).vetor[i]) return 0;
            //aux++;
    }
    return 1;
}


elem_t conjunto_minimo(conjunto_t *a){
    if(!a) return ELEM_MAX;
    elem_t menor=(*a).vetor[0];
    for(unsigned int i=0;i<(*a).numero;i++){
        if((*a).vetor[i]<menor) menor=(*a).vetor[i];
    }
    return menor;
}


elem_t conjunto_maximo(conjunto_t *a){
    if(!a) return ELEM_MIN;
    elem_t maior=(*a).vetor[0];
    for(unsigned int i=0;i<(*a).numero;i++){
        if((*a).vetor[i]>maior) maior=(*a).vetor[i];
    }
    return maior;
}

void conjunto_imprime(conjunto_t *a){
    if(!a) return;
    printf("%d",(*a).vetor[0]);
    for(unsigned int i=1;i<(*a).numero;i++) printf(" %d",(*a).vetor[i]);
    printf("\n");
}
