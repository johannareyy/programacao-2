#include "lista.h"

/**
 * arquivo lista.c
 * 
 * Implemente neste arquivo as funções especificadas em lista.h.
 * Não faça modificações nas estruturas de nó e lista fornecidas
 * Você pode implementar funções auxiliares além das fornecidas,
 * para isso, coloque o cabeçário da função no arquivo .h e sua
 * implementação aqui, no arquivo .c. Não altere assinaturas de
 * funções, caso contrário seu código receberá nota 0,0 (zero).
 */

// Estrutura de nó duplamente encadeado
struct no {
	tipo 		 info;		//Informação (dado) armazenada no nó
	struct no	*ant;		//Ponteiro para o nó anterior
	struct no	*prx;		//Ponteiro para o próximo nó
};

//Estrutura de lista duplamente encadeada com nós
struct lista {
	no_t 		*cabeca;	//Ponteiro para a cabeça da lista (primeiro)
	no_t 		*cauda;		//Ponteiro para a cauda da lista (último)
	int 		tamanho;	//Tamanho atual da lista
};

// Coloque a partir daqui a implementação das funções

lista_t* lista_cria (){
    lista_t* a = (lista_t*)malloc(sizeof(lista_t));
    if(!a) return NULL;
  	a->cabeca = NULL;
  	a->cauda = NULL;
  	a->tamanho = 0;
    return a;
}



void lista_destroi (lista_t **l){
	if(!(l)) return;
  	
	//Percorrer a lista
	no_t* ptr = (*l)->cabeca,*ptr2;
	
  	while (ptr)
    {
  		ptr2 = ptr->prx;
      	free (ptr);
      	ptr = ptr2;
    }
  
	free(*l);
  
  *l = NULL;
	return;
}


int lista_inicializada (lista_t *l){
  	if (l)
      return 1;
  	return 0;
}


int lista_tamanho (lista_t *l){
  if(!l) return -1;
	
  int size = 0;
  
  no_t** pptr = &(l->cabeca);
  while (*pptr)
  {
    size++;
    pptr = &(*pptr)->prx;
  }
  
  return size;
}


int lista_info_cabeca (lista_t *l, int *dado){
  if (!dado || !l)
    return -1;
  if (!(l->cabeca))
    return 0;
  
  *dado = l->cabeca->info;
  return 1;
}


int lista_info_cauda (lista_t *l, int *dado){
  if (!dado || !l)
    return -1;
  if (!(l->cauda))
    return 0;
  
  *dado = l->cauda->info;
  return 1;
}


int lista_info_posicao (lista_t *l, int *dado, int pos){
  if (!dado || !l) return -1;
  if (l->tamanho==0) return 0;
  if (0 > pos || pos >= l->tamanho)  return 0;
  
  no_t** pptr = &(l->cabeca);
  while (pos)
  {
    pos--;
    pptr = &(*pptr)->prx;
  }
  
  *dado = (*pptr)->info;
  
  return 1;
}


int	lista_insere_cabeca	(lista_t *l, tipo dado){
 if (!l)
    return -1;
  no_t* novo = (no_t*) malloc (sizeof(no_t));
  if (!novo)
    return -1;
  
  
  novo->info = dado;
  novo->ant = NULL;
  novo->prx = l->cabeca;
  
  if (l->cabeca) //caso já tenha pelo menos um elemento lá
  	l->cabeca->ant = novo;
  else //caso não haja nenhum elemento, coloque ele como cauda também
    l->cauda = novo;
  
  l->cabeca = novo;
  l->tamanho++;
  
  return 1;
  
}


int	lista_insere_cauda (lista_t *l, tipo dado){
   if (!l)
    return -1;
  no_t* novo = (no_t*) malloc (sizeof(no_t));
  if (!novo)
    return -1;

  
  novo->info = dado;
  novo->prx = NULL;
  novo->ant = l->cauda;
  
  if (l->cauda) //caso já tenha pelo menos um elemento lá
  	l->cauda->prx = novo;
  else //caso não haja nenhum elemento, coloque ele como cauda também
    l->cabeca = novo;
  
  l->cauda = novo;
  l->tamanho++;
  
  return 1;

}


int	lista_insere_posicao (lista_t *l, tipo dado, int pos){
  if (!l) return -1;
  if (0 > pos || pos > l->tamanho)  return 0;
    

  
  if(pos == 0) return lista_insere_cabeca(l,dado);
  if(pos == l->tamanho) return lista_insere_cauda(l,dado);
  
    no_t* novo = (no_t*) malloc (sizeof(no_t));
  if (!novo) return -1;
  no_t* aux;
  aux =l->cabeca;
  int i=0;
  while(i < pos){
    aux = aux->prx;
    i++;
  } 
  
  novo->info = dado;
   novo->ant=aux->ant;
   aux->ant->prx=novo;
    novo->prx=aux;
    aux->ant=novo;
    l->tamanho++;
    return 1;

}


int	lista_remove_cabeca	(lista_t *l, tipo *dado){
  if (!l) return -1;
  if (!dado) return -1;
  if (l->tamanho == 0) return 0;
    
  
  *dado = l->cabeca->info;
  
  no_t* ptr = l->cabeca;
  l->cabeca = l->cabeca->prx;
    if (l->tamanho == 1){
    l->cauda = NULL;
    l->cabeca = NULL;
}  
  if(l->cabeca)
  	l->cabeca->ant = NULL;
  	

  free (ptr);
  l->tamanho--;
  return 1;
}


int	lista_remove_cauda (lista_t *l, tipo *dado){
if (!l) return -1;
  if (!dado) return -1;
  if (l->tamanho == 0) return 0;

  
  *dado = l->cauda->info;
  
  no_t* ptr = l->cauda;
  l->cauda = l->cauda->ant;
  
 if (l->tamanho == 1){
    l->cauda = NULL;
    l->cabeca = NULL;
}  
  
  if(l->cauda)
  	l->cauda->prx = NULL;

  
  free (ptr);
  l->tamanho--;
  return 1;
    
}


int	lista_remove_posicao (lista_t *l, tipo *dado, int pos){
  if(!l || !dado) return -1;
  if(pos < 0 || pos >= l->tamanho || l->tamanho == 0) return 0;
  
  if(pos == 0) return lista_remove_cabeca(l,dado);
  if(pos == l->tamanho -1) return lista_remove_cauda(l,dado);
  no_t* ptr;
  ptr =l->cabeca;
  int i =0;
  
  while( i < pos){
      ptr = ptr->prx;
      i++;
  }
 
  ptr->prx->ant = ptr->ant;
  ptr->ant->prx = ptr->prx;
   *dado = ptr->info;
  free(ptr);
  l->tamanho--;
  return 1;
  
 
}


void remove_elemento(no_t* no, lista_t* l){
  if (no->ant)
    no->ant->prx = no->prx;
  
  if (no->prx)
    no->prx->ant = no->ant;
  
  l->tamanho--;
  
  if (l->tamanho == 0)
  {
    l->cabeca = NULL;
    l->cauda = NULL;
  }
  if (l->tamanho == 1)
  {
    if (l->cabeca == no)
      l->cabeca = l->cauda;
    else
      l->cauda = l->cabeca;
  }
  
  free(no);
}

int lista_remove_primeira (lista_t *l, tipo dado){
    if(!l) return -1;
    int posicao = lista_busca_info(l,dado);
    int data;
    if(posicao != -1){
        lista_remove_posicao(l,&data,posicao);
        return posicao;
    }else return -2;
  return 1;

}


int lista_remove_todas (lista_t *l, tipo dado){
    if(!l) return -1;
    int removidos = 0;
    while(lista_remove_primeira(l,dado) != -2){
        removidos++;
    }
    return removidos;
}


int lista_busca_info (lista_t *l, tipo dado){
  if(!l) return -1;
  no_t* ptr;
  ptr = l->cabeca;
  int test =1,i=0,posicao;
  while(ptr && test == 1){
      if(ptr->info == dado){
        test = 0;
        posicao = i;
      }
      i++;
      ptr = ptr->prx;
  }
  if(test == 0) return posicao;
  else return -1;
    
}


int lista_frequencia_info (lista_t *l, tipo dado){
    if(!l) return -1;
    no_t* ptr;
    ptr = l->cabeca;
    int freq =0;
    while(ptr){
        if(ptr->info == dado) freq++;
        ptr = ptr->prx;
    }
    return freq;
    
}


int	lista_ordenada (lista_t *l){
  if(!l) return -1;
  no_t* ptr;
  ptr = l->cabeca;
  if(l->tamanho <= 1) return 1;
  while(ptr->prx){
      if(ptr->info > ptr->prx->info) return 0;
      ptr = ptr->prx;
  }
    return 1;
}


int lista_insere_ordenado (lista_t *l, tipo dado){
  if(!l) return -1;
  int posicao = 0;
  no_t* ptr;
  ptr = l->cabeca;
  
  while(ptr && ptr->info < dado){
      posicao++;
      ptr = ptr->prx;
  }
  
  return lista_insere_posicao(l,dado,posicao);
    
}


int lista_compara (lista_t *l1, lista_t *l2){
    if(!l1 && !l2 ) return 1;
    if(!l1 || !l2) return 0;
    
    if(l1->tamanho != l2->tamanho) return 0;
    no_t *ptr1,*ptr2;
    ptr1 = l1->cabeca;
    ptr2 = l2->cabeca;
    int x=0;
    while(ptr1 && ptr2){
        if(ptr1->info == ptr2->info) x++;
        
        ptr1 = ptr1->prx;
        ptr2 = ptr2->prx;
    }
    if(x == l1->tamanho) return 1;
    else return 0;
}



int lista_reverte (lista_t *l){
  if (!l) return -1;
  if(l->tamanho <= 1) return 1;

  int i =0,troca;
  no_t* ptr, *ptr2;
  ptr = l->cabeca;
  ptr2 = l->cauda;
  while(i < l->tamanho/2){
      troca = ptr->info;
      ptr->info = ptr2->info;
      ptr2->info = troca;
      ptr = ptr->prx;
      ptr2 = ptr2->ant;
      i++;
  }
  return 1;
    
}



lista_t* lista_cria_copia (lista_t *l){
  if(!l) return NULL;
  no_t* ptr;
  ptr = l->cauda;
  lista_t* l2 = lista_cria();
  if(!l2) return NULL;
  
  while(ptr){
      lista_insere_cabeca(l2,ptr->info);
      ptr = ptr->ant;
  }
  
  
  return l2;
}