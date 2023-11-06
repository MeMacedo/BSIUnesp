/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
int main()
{
    int prim, seg, ter, quar, bran, nul;
    prim = seg = ter = quar = bran =nul=0;
    int voto;
    
    do{
        
        printf("Digite seu voto: ");
        scanf("%d", &voto);
        
        switch(voto){
            case 1: prim++;break;
            case 2: seg++;break;
            case 3: ter++;break;
            case 4: quar++;break;
            case 5: nul++;break;
            case 6: bran++;break;
            default: break;
        }
    }while(voto>0 &&voto<7);
    
    int invalidos = nul+bran;
    int total= nul+bran+prim+seg+ter+quar;
    
    printf("Votos 1: %d\nVotos 2: %d\nVotos 3: %d\nVotos 4: %d\n", prim, seg, ter,quar);
    printf("Votos nulos: %d\n", nul);
    printf("Percentual de brancos e nulos: %.2f", (float)(invalidos/total));
    
}


