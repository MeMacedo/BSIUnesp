/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>

int main()
{
    int n1, n2, quant_primo = 0;
    do{
        
        printf("Digite N1 e N2, N1<N2: ");
        scanf("%d %d", &n1, &n2);
        
        for(int i = n1+1; i<n2; i++){
            int primo = 1;
            for(int j = 2; j<i;j++){
                if(i%j==0) {printf("%d", i);primo = 0;}
            }
            quant_primo+=primo;
        }
        
        if (n1+n2>0) printf("A quantidade de primos entre N1 e N2 é %d\n", quant_primo);
        quant_primo = 0;
    }while(n1+n2>0);


    return 0;
}
