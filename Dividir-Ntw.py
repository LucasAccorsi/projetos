n = int(input("Quantidade de valores: "))

# Criando as listas
x = []
y = []
f = []

# Crinado a matriz
for i in range(0,n):
  f.append([0] * n)

# Recebendo X e Y
for i in range (0,n):
  a = float(input("X: "))
  x.append(a)
  b = float(input("Y: "))
  y.append(b)

# Colocando Y na coluna 0 da matriz
for i in range(0,n):
  f[i][0] = y[i]

# Fazendo as diferenças divididas
for i in range(1,n):
  for j in range(1,i):
    f[i][j] = (f[i][j-1] - f[i-1][j-1]) / (x[i] - x[i-j])

# Imprimindo os As da formula
for i in range(0,n):
  print(f[i][i])
