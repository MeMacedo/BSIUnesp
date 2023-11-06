/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include<stdio.h>
#include<conio.h>

int main(){
	
	int cha;
	
	do{
	    printf("Pressione uma tecla");
	    cha = getch();
	    
	    if(cha>=65||cha<=90)printf("%c\n", cha);
	    if(cha>=97||cha<112)printf("%c\n", cha-22);
	    }
	while(cha!=27);
		
	return 0;
}
