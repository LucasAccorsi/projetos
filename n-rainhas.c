/*#include<stdio.h>
#include<stdbool.h>
bool dama(int t[8][8], int coldama, int contdama){
  if (contdama < 8){
      for (int i=0; i < 8; i++){
        if(t[i][coldama] == 0){
          t[i][coldama] = 1;
          for (int j = 0; j < 8; j++){
            if(t[j][coldama] == 0){
              t[j][coldama] = 2;
            }
          }
          for (int j = 0; j < 8; j++){
            if(t[i][j] == 0){
              t[i][j] = 2;
            }
          }
          int c = i+1;
          for(int j = coldama+1; j < 8 || c < 8; j++){
              t[c][j] = 2;
              c = c + 1;
          }
          int c = i+1;
          for(int j = coldama+1; j < 8 || c < 8; j++){
              t[c][j] = 2;
              c = c + 1;
          }
        }
      }
      for (int i=0; i < 8; i++){
        for(int j=0;j < 8; j++){
          printf("%d",t[i][j]);
        }
        printf("\n");
      }
      printf("***********************\n");
      dama(t, coldama+1, contdama+1);
  }else{
    return true;
  }
  return false;
}
int main(void) {
  int t[8][8] = {0};
  
  for (int i=0; i < 8; i++){
    for(int j=0;j < 8; j++){
      printf("%d",t[i][j]);
    }
    printf("\n");
  }
  printf("***********************\n");
  printf("%d", dama(t, 0, 0));
  return 0;
}*/
#include <stdbool.h>
#include <stdio.h>
#define n 8
void printarSolucao(int t[n][n]){
  for (int i = 0; i < n; i++){
    for (int j = 0; j < n; j++){
      printf(" %d ", t[i][j]);
    }
    printf("\n");
  }
  printf("****************************\n");
}
bool podeColocar(int t[n][n], int lin, int col){
  int i, j;
  for (i = 0; i < col; i++){
    if (t[lin][i]){
      return false;
    }
  }
  for (i = lin, j = col; i >= 0 && j >= 0; i--, j--){
    if (t[i][j]){
      return false;
    }
  }
  for (i = lin, j = col; j >= 0 && i < n; i++, j--){
    if (t[i][j]){
      return false;
    }
  }
  return true;
}
bool colocar(int t[n][n], int col){
  printarSolucao(t);
  if (col >= n){
    return true;
  }
  for (int i = 0; i < n; i++){
    if (podeColocar(t, i, col)){
      t[i][col] = 1;
      if (colocar(t, col + 1)){
        return true;
      }
      t[i][col] = 0; // BACKTRACK
    }
  }
  return false;
}
bool damas(int t[n][n]){
  if (colocar(t, 0) == false){
    printf("Solução não existe");
    return false;
  }
  printarSolucao(t);
  return true;
}
int main(){
  int t[n][n] = {0};
  printf("****************************\n");
  damas(t);
  return 0;
}
