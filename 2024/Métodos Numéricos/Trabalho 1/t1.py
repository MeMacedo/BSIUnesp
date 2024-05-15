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
      CalculoDeterminante(n, A)
    case 2:
      n = int(input("Digite a ordem da matriz: "))
      A = criaMatriz(n)
      b = criaVetor(n, "de termos independentes")
      SistemaTriangularInferior(n, A, b)
    case 3:
      n = int(input("Digite a ordem da matriz: "))
      A = criaMatriz(n)
      b = criaVetor(n, "de termos independentes")
      SistemaTriangularInferior(n, A, b)
    case 4:
      n = int(input("Digite a ordem da matriz: "))
      A = criaMatriz(n)
      b = criaVetor(n, "de termos independentes")
      DecomposicaoLU(n, A, b)
    case 5:
      n = int(input("Digite a ordem da matriz: "))
      A = criaMatriz(n)
      b = criaVetor(n, "de termos independentes")
      Cholesky(n, A, b)
    case 6:
      n = int(input("Digite a ordem da matriz: "))
      A = criaMatriz(n)
      b = criaVetor(n, "de termos independentes")
      GaussCompacto(n, A, b)
    case 7:
      n = int(input("Digite a ordem da matriz: "))
      A = criaMatriz(n)
      b = criaVetor(n, "de termos independentes")
      GaussJordan(n, A, b)
    case 8:
      n = int(input("Digite a ordem da matriz: "))
      A = criaMatriz(n)
      b = criaVetor(n, "de termos independentes")
      x_0 = criaVetor(n, "de solução inicial")
      e = float(input("Digite a precisão esperada: "))
      
      max_int = int(input("Digite o máximo de iterações: "))
      Jacobi(n, A, b, x_0, e, max_int)
    case 9:
      n = int(input("Digite a ordem da matriz: "))
      A = criaMatriz(n)
      b = criaVetor(n, "de termos independentes")
      x_0 = criaVetor(n, "de solução inicial")
      e = float(input("Digite a precisão esperada: "))
      max_int = int(input("Digite o máximo de iterações: "))
      GaussSeidel(n, A, b, x_0, e, max_int)
    case 10:
      n = int(input("Digite a ordem da matriz: "))
      A = criaMatriz(n)
      MatrizInversa(A)
    case _:
      print("Opção inválida.")

def criaMatriz(n):
  print("Criando matriz.")
  A = [[] for i in range(n)]

  for i in range(n):
    for j in range(n):
      A[i].append(float(input("Digite o próximo termo da matriz: ")))

  return A

def criaVetor(n, tipo):
  print(f'Criando vetor {tipo}.')
  vetor = []

  for i in range(n):
    vetor.append(float(input("Digite o próximo termo do vetor: ")))
  return vetor

def CalculoDeterminante(n, A):
    matriz = np.array(A)
    if n==1:
        return matriz[n,n]
    if n==2:
        return A[0,0]*A[1,1]-A[0,1]*A[1,0]

    det = 0
    
    for j in range(n):
        if(A[0][j]) != 0:
            fator = (-1)**(2+j)
            cols = np.array([i!=j for i in range(n)])
            print(matriz)
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
    y = SistemaTriangularInferior(n, L.toList(), b)
    sol = SistemaTriangularSuperior(n, U.toList(), y)
  else:
    print("Menores principais não são diferentes de 0. Método não aplicável.")
    
  return sol

def GaussJordan(n, A, b):
  sol =[]
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
          matriz[j] = matriz[j] - ((matriz[j,i]/fator)*matriz[i])
          b[j] = b[j]-(matriz[j,0]/fator)*b[i]
  else:
    print("Menores principais não são diferentes de 0. Método não aplicável.")
    return []
  
  return SistemaTriangularSuperior(n, matriz.tolist(), b)

def Cholesky(n, A, b):
  sol =[]
  matriz = np.array(A)
  L = np.zeros(n)
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
  sol =[]
  if calcMenores(n, A):
    print()
  else:
    print("Menores principais não são diferentes de 0. Método não aplicável.")

  return sol



def Jacobi(n, A, b, x_0, e, max_int):
  sol =[0 for i in range(n)]
  ints = 0
  

  return sol, ints

def GaussSeidel(n, A, b, x_0, e, max_int):
  sol =[0 for i in range(n)]
  ints = 0
  

  return sol, ints


def MatrizInversa(n, A):
  inv = []
  match int(input("Digite 1 para resolver por Decomposição LU e 2 para Gauss Compacto: ")):
    case 1:
      print()
    case 2:
      print()
    case _:
      print("Opção inválida.")
  
  
  

  return inv





def calcMenores(n, A):
  matriz = np.array(A)
  for i in range(n):
    det = CalculoDeterminante(i, matriz[0:i , 0:i].tolist())
    if det == 0:
      return False
  return True

def calcDefinidaPositiva(n, A):
  matriz = np.array(A)
  for i in range(n):
    det = CalculoDeterminante(i, matriz[0:i , 0:i].tolist())
    if det <= 0:
      return False
  return True


if __name__ == "__main__":
    main()

