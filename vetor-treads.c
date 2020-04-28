#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define tam 1000

void swap(int *n1, int *n2){  
  int temp = *n1; 
  *n1 = *n2; 
  *n2 = temp; 
}

void bubbleSort(int *vetor, int n){ 
  if (n < 1)
    return; 
  for (int i=0; i < n; i++) 
    if (vetor[i] > vetor[i+1]) 
      swap(&vetor[i], &vetor[i+1]);  
  bubbleSort(vetor, n-1); 
} 

void aleatorio(int *vetor, int n){
  int i;
  for (i = 0; i < n; i++)
    vetor[i] = rand()  % 10000;
}

void imprimir(int vetor[], int n){
  int i;
  for(i = 0; i < n; i++)
    printf("%d ", vetor[i]);
}

int main(void) {

  clock_t tempoFinal, tempoInicial;
  tempoInicial = clock();
  
  

  #pragma omp parallel sections
  {
    #pragma omp sections
    {
      int *v1 = calloc(tam, sizeof(int));
      aleatorio(v1, tam);
      bubbleSort(v1, tam);
    }
    #pragma omp sections
    {
      int *v2 = calloc(tam, sizeof(int));
      aleatorio(v2, tam);
      bubbleSort(v2, tam);
    }
    #pragma omp sections
    {
      int *v3 = calloc(tam, sizeof(int));
      aleatorio(v3, tam);
      bubbleSort(v3, tam);
    }
    #pragma omp sections
    {
      int *v4 = calloc(tam, sizeof(int));
      aleatorio(v4, tam);
      bubbleSort(v4, tam);
    }
  }
  
  tempoFinal = clock();
  printf("\n----------------------------------------\nTempo de execução: %.3f segundos", (double)(tempoFinal - tempoInicial) / (double)(CLOCKS_PER_SEC));

  return 0;
}
