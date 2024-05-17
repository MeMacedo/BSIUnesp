import numpy as np
import math

def main():

  print("----------MENU-----------")
  print("1 - Calcular determinante")
  print("2 - Calcular sistema triangular inferior")
  print("3 - Calcular sistema triangular superior")
  print("4 - Calcular decomposição LU")
  print("5 - Calcular cholesky")
  print("6 - Calcular gauss compacto")
  print("7 - Calcular gauss jordan")
  print("8 - Calcular jacobi")
  print("9 - Calcular gauss seidel")
  print("10 - Calcular inversa")

  value = int(input("Digite a opção que queira calcular: "))
  
  match value:
    case 1:
      n = int(input("Digite a ordem da matriz: "))
      A = criaMatriz(n)
      print(f'O determinante é {CalculoDeterminante(n, A)}') 
    case 2:
      n = int(input("Digite a ordem da matriz: "))
      A = criaMatriz(n)
      b = criaVetor(n, "de termos independentes")
      print(f'A solução é : {SistemaTriangularInferior(n, A, b)}')
    case 3:
      n = int(input("Digite a ordem da matriz: "))
      A = criaMatriz(n)
      b = criaVetor(n, "de termos independentes")
      print(f'A solução é : {SistemaTriangularSuperior(n, A, b)}')
    case 4:
      n = int(input("Digite a ordem da matriz: "))
      A = criaMatriz(n)
      b = criaVetor(n, "de termos independentes")
      print(f'A solução é {DecomposicaoLU(n, A, b)}')
    case 5:
      n = int(input("Digite a ordem da matriz: "))
      A = criaMatriz(n)
      b = criaVetor(n, "de termos independentes")
      print(f'A solução é {Cholesky(n, A, b)}')
    case 6:
      n = int(input("Digite a ordem da matriz: "))
      A = criaMatriz(n)
      b = criaVetor(n, "de termos independentes")
      print(f'A solução é {GaussCompacto(n, A, b)}')
    case 7:
      n = int(input("Digite a ordem da matriz: "))
      A = criaMatriz(n)
      b = criaVetor(n, "de termos independentes")
      print(f'A solução é {GaussJordan(n, A, b)}')
    case 8:
      n = int(input("Digite a ordem da matriz: "))
      A = criaMatriz(n)
      b = criaVetor(n, "de termos independentes")
      x_0 = criaVetor(n, "de solução inicial")
      e = float(input("Digite a precisão esperada: "))
      max_int = int(input("Digite o máximo de iterações: "))
      print(f'A solução encontrada é {Jacobi(n, A, b, x_0, e, max_int)}')
    case 9:
      n = int(input("Digite a ordem da matriz: "))
      A = criaMatriz(n)
      b = criaVetor(n, "de termos independentes")
      x_0 = criaVetor(n, "de solução inicial")
      e = float(input("Digite a precisão esperada: "))
      max_int = int(input("Digite o máximo de iterações: "))
      print(f'A solução encontrada é {GaussSeidel(n, A, b, x_0, e, max_int)}')
    case 10:
      n = int(input("Digite a ordem da matriz: "))
      A = criaMatriz(n)
      typeSol = int(input("Digite 1 para resolver por Decomposição LU e 2 para Gauss Compacto: "))
      print('A inversa é:')
      print(MatrizInversa(n,A,typeSol))
    case _:
      print("Opção inválida.")

def criaMatriz(n):
  print("Criando matriz.")
  A = [[] for i in range(n)]

  for i in range(n):
    for j in range(n):
      A[i].append(float(input("Digite o próximo termo da matriz: ")))

  print(np.array(A))

  return A


def criaVetor(n, tipo):
  print(f'Criando vetor {tipo}.')
  vetor = []

  for i in range(n):
    vetor.append(float(input("Digite o próximo termo do vetor: ")))
  print(vetor)
  return vetor

def CalculoDeterminante(n, A):
    matriz = np.array(A)
    if n==1:
        return matriz[0,0]
    if n==2:
        return matriz[0,0]*matriz[1,1]-matriz[0,1]*matriz[1,0]

    det = 0
    
    for j in range(n):
        if(A[0][j]) != 0:
            fator = (-1)**(2+j)
            cols = np.array([i!=j for i in range(n)])
            subMatriz = matriz[np.ix_([1,n-1], cols)]
            det += fator*A[0][j]*CalculoDeterminante(n-1, subMatriz)

    return det

def SistemaTriangularInferior(n, A, b):
  sol =[]
 
  j = 0
  for i in range(n):
    sum = b[i]
    while(j<i):
      sum-=sol[j]*A[i][j]
      j+=1
    sum = sum/A[i][j]
    sol.append(sum)
    j=0
  
  return sol

def SistemaTriangularSuperior(n, A, b):
  sol =[0 for i in range(n)]
  
  j = n-1
  for i in range(n-1, -1, -1):
    sum = b[i]
    while(j>i):
      sum-=sol[j]*A[i][j]
      j-=1
    sum = sum/A[i][j]
    sol[i]=sum
    j=n-1
  
  return sol

def DecomposicaoLU(n, A, b):
  sol =[]

  if calcMenores(n, A):
    U = np.array(A)
    L = np.eye(n)  
    for j in np.arange(n-1):  
        for i in np.arange(j+1,n):  
            L[i,j] = U[i,j]/U[j,j]  
            for k in np.arange(j+1,n):  
                U[i,k] = U[i,k] - L[i,j]*U[j,k]  
            U[i,j] = 0
    y = SistemaTriangularInferior(n, L.tolist(), b)
    sol = SistemaTriangularSuperior(n, U.tolist(), y)
  else:
    print("Menores principais não são diferentes de 0. Método não aplicável.")
    
  return sol

def GaussJordan(n, A, b):
  matriz = np.array(A)
  
  if calcMenores(n,A):
    for i in range(n):
      if (matriz[i,i] == 0):
        swap = 1
        while ((i + swap) < n and matriz[i+swap,i] == 0):
          swap += 1    
        temp = np.copy(matriz[i])
        matriz[i] = np.copy(matriz[i+swap])
        matriz[i+swap]= temp
        
      fator = matriz[i,i]  
      for j in range(i+1,n):
        b[j] = b[j]-(matriz[j,i]/fator)*b[i]
        matriz[j] = matriz[j] - ((matriz[j,i]/fator)*matriz[i])
  else:
    print("Menores principais não são diferentes de 0. Método não aplicável.")
    return []
  
  return SistemaTriangularSuperior(n, matriz.tolist(), b)

def Cholesky(n, A, b):
  matriz = np.array(A)
  L = np.zeros((n,n))
  transMatriz = matriz.transpose()
  if not np.array_equal(matriz, transMatriz):
    print('Matriz não é simétrica. Método inválido')
  if not calcDefinidaPositiva(n,A):
    print("Matriz não é definida positiva. Método inválido.")
  else: 
    for i in range(n):
      for j in range(i+1):
        sum=0
        if j == i: 
          for k in range(j):
            sum += pow(L[j,k], 2);
          L[i,i] = math.sqrt(matriz[j,j] - sum)
        else:
          for k in range(j):
            sum += L[i,k]*L[j,k]
          L[i,j] = (matriz[i,j]-sum)/L[j,j]
    
  LTrans = L.transpose()
  y = SistemaTriangularInferior(n, L.tolist(), b)
  
  
  return SistemaTriangularSuperior(n, LTrans.tolist(), y)

def GaussCompacto(n, A, b):
  matriz = np.array(A)
  coefs = np.array(b).reshape((n,1))
  matrizAument = np.concatenate((matriz, coefs), axis=1)
  matriz = np.copy(matrizAument)
  for i in range (n):
    for j in range (n+1):
      sum = 0
      if (i>j):
        for k in range(j):
          sum += matrizAument[i,k]*matrizAument[k,j]
        matrizAument[i,j] = (matriz[i,j]-sum)/matrizAument[j,j]
      else:
        for k in range(i):
          sum += matrizAument[i,k]*matrizAument[k,j]
        matrizAument[i,j] = matriz[i,j]-sum
  

  U = np.triu(matrizAument[:n,:n]).tolist()
  newCoefs = matrizAument[:, n].tolist()

  return SistemaTriangularSuperior(n, U, newCoefs)

def Jacobi(n, A, b, x_0, e, max_int):
  sol =[0 for i in range(n)]
  ints = 0
  matriz = np.array(A)
  x_k_1 = x_0

  if not (convLin(n,A) or convCol(n,A)):
    print("Método não converge.")
  else:

    while(True):
      ints+=1
      x_k = x_k_1
      x_k_1 = []
      for i in range(n):
        sum =0
        for j in range(n):
          sum+=x_k[j]*matriz[i,j]
        calc = (b[i]-sum)/matriz[i,i]
        x_k_1.append(calc)
      erro = infNorm([x_k_1[i]-x_k[i] for i in range(n)])/infNorm(x_k_1)
      if(erro<=e):
        break
      if(ints==max_int):
        break

  return x_k_1, ints

def GaussSeidel(n, A, b, x_0, e, max_int):
  ints = 0
  matriz = np.array(A)
  x_k_1 = x_0

  if not (convLin(n,A) or sassenfeld(n,A)):
    print("Método não converge.")
  else:
    while(True):
      ints+=1
      x_k = x_k_1
      x_k_1 = []
      for i in range(n):
        sum=0
        for j in range(n):
          if(i>j):
            sum+=x_k[j]*matriz[i,j]
          if(i<j):
            sum+=x_k_1[j]*matriz[i,j]
        calc = (b[i]-sum)/matriz[i,i]
        x_k_1.append(calc)
      erro = infNorm([x_k_1[i]-x_k[i] for i in range(n)])/infNorm(x_k_1)
      if(erro<=e):
        break
      if(ints==max_int):
        break

  return x_k_1, ints

def MatrizInversa(n, A, typeSol):
  inv = np.zeros((n,n))
  if not CalculoDeterminante(n,A):
    print("Matriz não é singular. Não é possível achar inversa.")

  else:
    match typeSol:
      case 1:
        for i in range(n):
          inv[:, i] = np.array(DecomposicaoLU(n, A, [int(i==j) for j in range(n)]))
      case 2:
        for i in range(n):
          inv[:, i] = np.array(GaussCompacto(n, A, [int(i==j) for j in range(n)]))
      case _:
        print("Opção de solução inválida.")
  return inv.tolist()

def calcMenores(n, A):
  matriz = np.array(A)
  for i in range(1, n):
    det = CalculoDeterminante(i, matriz[0:i , 0:i].tolist())
    if det == 0:
      return False
  return True

def calcDefinidaPositiva(n, A):
  matriz = np.array(A)
  for i in range(1,n):
    det = CalculoDeterminante(i, matriz[0:i , 0:i].tolist())
    if det <= 0:
      return False
  return True

def convLin(n, A):
  coefs = []
  for i in range (n):
    sum = 0
    for j in range(n):
      if(i!=j):
        sum+=abs(A[i][j]/A[i][i])
    coefs.append(sum)

  return max(coefs)<1

def convCol(n, A):
  coefs = []
  for i in range (n):
    sum = 0
    for j in range(n):
      if(i!=j):
        sum+=abs(A[i][j]/A[j][j])
    coefs.append(sum)

  return max(coefs)<1

def sassenfeld(n, A):
  betas = []

  for i in range(n):
    for j in range(i-1):
      sum+=  betas[j]*abs(A[i][j]/A[i][i])
    for k in range(i+1, n):
      sum+= abs(A[i][j]/A[i][i])
    betas.append(sum)

  return max(betas)<1


def infNorm(vetor):
    return max(abs(i) for i in vetor)

if __name__ == "__main__":
    main()

