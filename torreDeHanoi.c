// Lucas Micael Accorsi Freitas da Silva

#include <stdio.h>

void torreDeHanoi(int n, char A, char B, char C){
  // Caso Base
  if (n == 1){
    printf("\n Mova o disco 1 da haste %c para a haste %c", A, B);
    return;
  }else{
    // De C para B
    torreDeHanoi(n-1, A, C, B);
    printf("\n Mova o disco %d da haste %c para a haste %c", n, A, B);
    // De A para B e de C para A
    torreDeHanoi(n-1, C, B, A);
  }
}

int main(){
  // Quantidade de discos
  int n = 3;
  // Hastes A, B, C
  torreDeHanoi(n, 'A', 'B', 'C');
  return 0;
}
