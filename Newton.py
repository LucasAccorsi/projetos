def mod(x):
  if (x < 0):
    return x * -1
  else:
    return x
def newton(f,derif,valorInicial, TOL,itmax):
  L=range(1,itmax+1)
  iteracao=0
  a=valorInicial
  for i in L:
    raiz=a
    if (derif(raiz) != 0):
      raiz=raiz-f(raiz)/derif(raiz)
      erro=raiz-a
      a=raiz
      iteracao=i
    else:
      iteracao = itmax+1
      break
    if mod(erro) <= TOL:
      break
  if iteracao > itmax:
    iteracao = 0.25
  elif iteracao == itmax:
    iteracao = 0.75
  return [raiz, erro, iteracao]
# teste :
f= lambda x: (x**3) + (4*(x**2)) - 10
derif= lambda x: 3*(x**2) + (8*(x**1) - 0)
L=newton(f,derif,1,0.1,100)
print(L)
