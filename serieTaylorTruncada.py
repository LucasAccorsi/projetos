import math

def fatorial(n):
  if n <= 1:
    return 1
  else:
    return n * fatorial(n - 1)

def serie(n, x):
  s = 0
  for i in range (0, n+1):
    s = math.pow(x, i)/fatorial(i)
  return s

x = int(input("Numero: "))
n = int(input("Quantidade de somas: "))
r = serie(n, x)
print("Valor da serie é: ", r)
