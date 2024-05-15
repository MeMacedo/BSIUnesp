import pandas as pd


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
    if n==1:
        return A[n][n]
    if n==2:
        return A[0][0]*A[1][1]-A[0][1]*A[1][0]

    det = 0
    subMatriz = [[]for i in range(n-1)]
    for j in range(n):
        if(A[0][j]) != 0:
            signal = (-1)**(2+i)
            linha_aux = 0;
                col_aux = 0;
            for linha in range(1, n):
                for col in range(n):
                    if(col!=j):
                        subMatriz[linha_aux][col_aux] = A[linha][col]
                        col_aux+=1
                linha_aux+=1
                col_aux=0
            det += signal*A[0][j]*CalculoDeterminante(n-1, subMatriz)
            


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
  sol =[0 for i in range(n)]
  

  return sol

def Cholesky(n, A, b):
  sol =[0 for i in range(n)]
  

  return sol


def GaussCompacto(n, A, b):
  sol =[0 for i in range(n)]
  

  return sol

def GaussJordan(n, A, b):
  sol =[0 for i in range(n)]
  

  return sol

def Jacobi(n, A, b, x_0, e, max_int):
  sol =[0 for i in range(n)]
  

  return sol, ints

def GaussSeidel(n, A, b, x_0, e, max_int):
  sol =[0 for i in range(n)]
  

  return sol, ints


def MatrizInversa(n, A):
  ##LU ou GaussCompacto

  return inv








if __name__ == ‘__main__’:
    main()

