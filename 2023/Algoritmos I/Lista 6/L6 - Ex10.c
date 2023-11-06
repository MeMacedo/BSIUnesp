/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/
#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    
    int termos, x;
    
    do{
        printf("Digite o valor de x e o número de termos: ");
        scanf("%d %d", &x, &termos);
        
        double fat = 1;
        int expo = 0;
        
    float soma=0;
        
        for(int i=1; i<=termos; i++){
            if(i%2) {
                soma+= pow(x, expo)/fat;
            } else {
                
                soma-= pow(x, expo)/fat;
            }
            if(fat==1) fat = fat*(fat+1);
            else fat = fat*(abs(expo)+1)*(abs(expo)+2);
            
            expo += 2;
        }
        
        if(termos) printf("cos(x) = %.2f, soma = %.2f\n", cos(x), soma);
    } while(termos>0);
    
}
