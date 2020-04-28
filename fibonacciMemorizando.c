#include <stdio.h>

int cont=0;

int fib(int vet[], int num){
  cont++;
  if(vet[num] != -1){
    return vet[num];
  }else{ 
    vet[num] = fib(vet, num-1) + fib(vet, num-2);
    return vet[num];
  }
}

int main(void){
  int n;
  printf("Numero a ser calculado: ");
  scanf("%d", &n);
  int v[n];
  v[0] = 1;
  v[1] = 1;
  for(int i=2; i < n+1; i++){
    v[i] = -1;
  }
  printf("\nO resultado é: %d", fib(v, n));
  printf("\nNumero de chamadas feitas: %d", cont);
  return 0;
}
