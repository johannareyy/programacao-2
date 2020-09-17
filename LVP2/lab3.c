#include "lab3.h"
#include <stdio.h> //printf
#include <stdlib.h> //malloc, realoc
#include <math.h> //sqrt, pow

FILE *abre_arquivo(const char *arquivo){
    if (!arquivo) return NULL;
    FILE *arq;
    arq=fopen(arquivo,"r");
    return arq;
}
    
int fecha_arquivo(FILE *arq){
    if (!arq) return 1;
    fclose(arq);
    return 0;
}

double *le_valores(const char *arquivo, unsigned int *qtd_numeros){
    if (!arquivo){
        qtd_numeros=0;
        return NULL;
    }
    if (!qtd_numeros) return NULL;
    FILE *arq;
    arq = fopen(arquivo,"r");
    double *vetor=(double*)malloc(sizeof(double));
    int i=0,j=2;
    while (fscanf(arq,"%lf",vetor+i)!=EOF){
        /*if(i=100*j){
            vetor=(double*)realloc(vetor,sizeof(double)*100*(j+1));
            j++;
        }*/
        vetor=(double*)realloc(vetor,sizeof(double)*j);
        j++;
        i++;
    }
    *qtd_numeros=i;
    fclose(arq);
    
    return vetor;
}
  
double maior(double* valores, unsigned int qtd_numeros){
    if(!valores) return HUGE_VAL;
    if(!qtd_numeros) return HUGE_VAL;
    double maior_num=valores[0];
    for (int i=0;i<qtd_numeros;i++)
        if (valores[i]>maior_num)
            maior_num=valores[i];

    return maior_num;
}  
   
double menor(double* valores, unsigned int qtd_numeros){
    if(!valores) return HUGE_VAL;
    if(!qtd_numeros) return HUGE_VAL;
    double menor_num=valores[0];
    for (int i=0;i<qtd_numeros;i++)
        if (valores[i]<menor_num)
            menor_num=valores[i];
    return menor_num;
}

double media(double* valores, unsigned int qtd_numeros){
    if(!valores) return HUGE_VAL;
    if(!qtd_numeros) return HUGE_VAL;
    double soma=0;
    for (int i=0;i<qtd_numeros;i++)
        soma+=valores[i];
    return (soma/qtd_numeros);
}

double desvio(double* valores, unsigned int qtd_numeros){
    if(!valores) return HUGE_VAL;
    if(!qtd_numeros) return HUGE_VAL;
    double Media=media(valores,qtd_numeros);
    double soma_dos_quad=0;
    for(int i=0;i<qtd_numeros;i++)
        soma_dos_quad+=pow((valores[i]-Media),2);
    return sqrt(soma_dos_quad/(qtd_numeros-1));
}

double amplitude(double* valores, unsigned int qtd_numeros){
    if(!valores) return HUGE_VAL;
    if(!qtd_numeros) return HUGE_VAL;
    double Maior=maior(valores,qtd_numeros);
    double Menor=menor(valores,qtd_numeros);
    return (Maior-Menor);
}

double valor(double* valores, unsigned int qtd_numeros, unsigned int posicao){
    if(!valores) return HUGE_VAL;
    if(!qtd_numeros) return HUGE_VAL;
    if(qtd_numeros<=posicao) return HUGE_VAL;
    return *(valores+posicao);
}

double repetido(double* valores, unsigned int qtd_numeros, unsigned int *qtd_repeticao){
    if(!valores){
        qtd_repeticao=0;
        return HUGE_VAL;
    }
    /*if(qtd_numeros=1){
        *qtd_repeticao=0;
        return valores[0];
    }*/
    if(!qtd_numeros) return HUGE_VAL;
    if(!qtd_repeticao) return HUGE_VAL;
    
    int cont=1, i=0, aux=0, mais_rep=0, k=0, j=0;
    for(i=0;i<qtd_numeros;i++){
        for(j=i+1;j<qtd_numeros;j++){
            if(valores[i]==valores[j]){
                cont++;
            }
        }
        for(k=i-1;k>=0;k--){
            if(valores[i]==valores[k]){
                cont++;
            }
        }
    
        if(cont>mais_rep){
            aux=i;
            mais_rep=cont;
        }
        cont=1;
    }
    *qtd_repeticao=mais_rep;
    return (valores[aux]);
}
/*resposta de implementacao aqui*/
