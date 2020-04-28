#include <stdio.h>
//****************Dinâmico***********************
int max(int max, int temp){
  if(temp>max){
    max=temp;
  }
  return max;
}

int memorizaraux(int n, int p[], int r[]){
  int temp;
  if(r[n] >= 0){
    return r[n];
  }
  if(r[n] == 0){
    temp = 0;
  }else{
    temp = -1;
    for(int i=1; i <= n; i++){
      temp = max(temp,p[i] + memorizaraux(n-1, p, r));
    }
  }
  r[n] = temp;
  return memorizaraux(n, p, r);
}

int memorizar(int n, int p[]){
  int r[n];
  for(int i=0; i<=n; i++){
    r[i] = -1;
  }
  return memorizaraux(n, p, r);
}

//****************ingênuo************************
int haste(int n, int p[]){
  if(n==0){
    return 0;
  }
  int max=-1;
  for(int i=0; i<=n; i++){
    int temp=p[i]+haste(n-1, p);
    if(temp>max){
      max=temp;
    }
  }
  return max;
}

//*****************MAIN*****************************
int main(void){
  int t,n;
  printf("Quantidades de cortes possíveis: ");
  scanf("%d", &t);
  int p[t];
  for (int i=0; i<t; i++){
    printf("Valor do corte %dº: ", i+1);
    scanf("%d", &p[i]);
  }
  printf("Tamanho da haste: ");
  scanf("%d", &n);
  printf("ingênuo\nMaior lucro: %d", haste(n, p));
  printf("Dinâmico\nMaior lucro: %d", memorizar(n, p));
  return 0;
}
