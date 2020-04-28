import math

def mod(x):
  if (x < 0):
    return x * -1
  else:
    return x

def f(x):
  return (math.pow(x, 3)+(4*math.pow(x, 2))-10)

def bissecao(a, b, TOL, N):
  
  i = 1
  fa = f(a)
  
  while (i <= N):
    
    #iteracao da bissecao
    p = a + (b-a)/2
    fp = f(p)
    print (mod(f(p)))

    #condicao de parada
    if ((fp == 0) or (mod(f(p)) < TOL)):
      return "interações: ", i, "An: ", a, "Bn: ", b, "Pn: ", p, "F(Pn): ", f(p) 

    i = i+1
    if (fa * fp > 0):
      a = p
      fa = fp
    else:
      b = p

  return "Numero maximo de iterações excedido!";

a = 1;
b = 2;
TOL = 0.1;
NumeroDeInteracoes = 1000;
print (bissecao(a, b, TOL, NumeroDeInteracoes))
