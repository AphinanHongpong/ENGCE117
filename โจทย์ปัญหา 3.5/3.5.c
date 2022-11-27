#include <stdio.h>
void main() {
    int arr[1000],arrb[10000],i,length,k,c=0;
    
	printf("\nInput number of element to be store in array : ");
	scanf("%d",&length);
	
	printf("\n-----");
	
	for (i=1;i<=length;i++){
	  printf("\nElement [%d] : ",i);
	  scanf("%d",&arr[i]);
	} //end for
	
	printf("\n-----");
	
	  for(i=1; i<=length; i++){
        c=1;
        if(arr[i]!=-1)
		{
		    for(k=i+1; k<length; k++)
     
            {
        	   if(arr[i]==arr[k])
        	    {
			       c++;
			       arr[k]=-1;
		       }//end if
	       }//end for
	       arrb[i]=c;
		}//end if
    }//end for
	
	for(i=1;i<=length;i++){
		if(arr[i]!=-1){
			printf("\n %d -> %d ", arr[i],arrb[i]);
		}//end if
	}//end for
	
	return 0;
	
} //end main
