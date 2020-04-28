#include <stdio.h>
#include <string.h>

void scanner(char p[], int *i, char *r[]){

	q0:
		if(p[*i] > 47 && p[*i] < 58){
    	(*i)++;
			goto q1;
		}else if(p[*i] == '+' || p[*i] == '-'){
      (*i)++;
      goto q2;
		}else{
			goto q5;
		}

	q1:
    if(p[*i] > 47 && p[*i] < 58){
      (*i)++;
      goto q1;
		}else if(p[*i] == '.'){
      (*i)++;
      goto q3;
		}else if(p[*i] == ' '|| p[*i] == '\0'){
			*r = "<INTEIRO>";
			return;
		}else{
      goto q5;
		}

	q2:
    if(p[*i] > 47 && p[*i] < 58){
      (*i)++;
      *r = "<INTEIRO>";
      goto q1;
		}else{
      goto q5;
		}

  	q3:
      *r = "<P. FLUTUANTE>";
    	if(p[*i] > 47 && p[*i] < 58){
      	(*i)++;
      	goto q4;
		  }else{
			  (*i)--;
      	goto q5;
		  }

  	q4:
    	if(p[*i] > 47 && p[*i] < 58){
      	(*i)++;
      	goto q4;
		  }else if(p[*i] == ' '|| p[*i] == '\0'){
        return;
      }else{
			  goto q5;
      }

  	q5:
    	(*i)++;
    	for(;(p[*i] != 32) && p[*i] != '\0'; (*i)++);
		  *r = "<ERRO>";
		  return;
}

int main(int argc, char *argv[]){

	char *resposta[] = {""}, palavra[] = {"-21  +45.67  0.123   .456   42  23.AA  xx 6. 5"};
  int indice = 0;	
	
  while(palavra[indice] == ' '){
    indice++;
  }
  while(palavra[indice] != '\0'){

    scanner(palavra, &indice, resposta);
    printf("\n%s\n", *resposta);

    while(palavra[indice] == ' '){
      indice++;
    }
  }
  return 0;
}
