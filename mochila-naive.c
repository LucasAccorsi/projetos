#include<stdio.h> 
  
// Máximo entre dois números
int max(int a, int b){
  return (a > b)? a : b;
} 
  
// Returns the maximum value that can be put in a knapsack of capacity W 
int knapSack(int W, int wt[], int val[], int n){ 
  // Caso Base 
  if (n == 0 || W == 0){ 
    return 0; 
  }
   // Se o peso do item for maior que a capacidade da mochila
   if (wt[n-1] > W) 
       return knapSack(W, wt, val, n-1); 
  
   // Máximo entre dois números
   else
   return max(val[n-1] + knapSack(W-wt[n-1], wt, val, n-1), knapSack(W, wt, val, n-1)); 
} 
  
//******************* MAIN *********************
int main() 
{ 
    int val[] = {1, 3, 3, 4, 7, 6, 9, 12, 16, 20}; 
    int wt[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; 
    int  W = 50; 
    int n = sizeof(val)/sizeof(val[0]); 
    printf("%d", knapSack(W, wt, val, n)); 
    return 0; 
} 
