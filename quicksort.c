#include <stdio.h>

void quicksort(int a[], int e, int d){
	int i, j, pivo, aux;
	i = e;
	j = d-1;
	pivo = a[(e + d) / 2];
	while(i <= j){
		while((a[i] < pivo) && (i < d)){
			i++;
		}
		while((a[j] > pivo) && (j > e)){
			j--;
		}
		if(i <= j){
			aux = a[i];
			a[i] = a[j];
			a[j] = aux;
			i++;
			j--;
		}
	}
	if(j > e){
		quicksort(a, e, j+1);
  }
	if(i < d){
		quicksort(a, i, d);
  }
}

int main(void){
  int a[10] = {9, 4, 5, 3, 1, 2, 8, 7, 6, 0};
  quicksort(a, 0, 10);

  for(int i = 0; i < 10; i++){
    printf("%d",a[i]);
  }

  return 0;
}
