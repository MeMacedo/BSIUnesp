/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#define MAX 100


int main()
{
	int n;
	int x_i,y_i,x_f,y_f;
	int mar[MAX][MAX];
	int area = 0;
	
	scanf("%d", &n);
	
	for(int i=0; i<MAX; i++){
		for(int j=0; j<MAX; j++){
			mar[i][j] = 0;
    	}
	}
	
	while(n){
	    scanf("%d %d %d %d",&x_i,&x_f,&y_i,&y_f);
		for(int i=x_i; i<x_f; i++){
			for(int j=y_i; j<y_f; j++){
				mar[i][j] = 1;
		    }
	    }
	    n--;
	}

	for(int i=0; i<MAX; i++)
		for(int j=0; j<MAX; j++)
			if(mar[i][j]) area++;

	printf("%d\n",area);
	
	return 0;
}