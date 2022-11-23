#include <stdio.h>
void main() {
    int n,i,t=9;
	int sum =0;
	printf("Input number :");
	scanf("%d",&n);
	for (i=1;i<=n;i++)
	{ 
	  sum +=t;
	  printf("%d  +  ",t);
	  t=t*10+9;//increase 9 digits(9->99)
	} //end for
	printf("\nTotal = %d \n",sum);
} //end main

