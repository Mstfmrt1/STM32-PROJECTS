#include <stdio.h>
#include <stdlib.h>

/*
Verilen sýralý tam sayý listesinin geniþletilmiþ versiyonunu bulan bir fonksiyon yazýnýz.
? Geniþletme kuralý: Eðer verilen listede “n” deðeri varsa geniþletilmiþ listede “n-2”, “n-1”, “n”,
“n+1”, “n+2” bulunmalýdýr. Ancak listede hiçbir eleman birden fazla bulunmamalýdýr ve liste
sýralý olmalýdýr.
Örnek: input = [ 4, 10, 11, 14] - output=[2, 3, 4, 5, 6, 8, 9, 10, 11, 12, 13, 14, 15, 16 ]
----------------------------------------------

Write a function that finds the expanded version of the given ordered list of integers.
? Expansion rule: If the given list has a value of "n", the expanded list includes "n-2", "n-1", "n",
“n+1”, “n+2” must be found. However, no element in the list should have more than one
should be sequential.
Example: input = [ 4, 10, 11, 14] - output=[2, 3, 4, 5, 6, 8, 9, 10, 11, 12, 13, 14, 15, 16 ]
*/

int main(int argc, char *argv[]) {
	
	int array_length,i=0,j=0,k=0,temp=0,newArray_index=0;
	printf("Please enter array length \n");
	scanf("%d",&array_length);
	printf("Array[%d]\n",array_length);
	int array[array_length];
	int newarray[array_length*5];
	
	for(i=0;i<array_length;i++)
	{
		printf("Enter %d. Array Member: ",i);
		scanf("%d",&array[i]);
	}


   for(i=0;i<array_length;i++)
   {
   	newarray[newArray_index]=array[i]-2;
   	newarray[newArray_index+1]=array[i]-1;
   	newarray[newArray_index+2]=array[i];
   	newarray[newArray_index+3]=array[i]+1;
   	newarray[newArray_index+4]=array[i]+2;
   	newArray_index=newArray_index+5;
   }

   
   for(i=0;i<newArray_index;i++)
   {
   	for(j=i+1;j<newArray_index;j++)
   	{
   		if(newarray[i]> newarray[j])
   		{
            temp = newarray[i];//element to be changed i=0 , temp 0.element
            newarray[i] = newarray[j]; //1.element replaces 0.element
            newarray[j] = temp;//0.element replaces 1.element
		}
	   }
   }
   
      printf("NewArray[]=");
    for(i=0;i<newArray_index;i++)
   {
   	printf("%d ",newarray[i]);
   } 
   
   for(i=0;i<newArray_index;i++)
   {
   	for(j=i+1; j<newArray_index;)
   	{
   		if(newarray[j]==newarray[i])
   		{
   			
   			for(k=j;k<newArray_index;k++)
   			{
   				newarray[k]=newarray[k+1];
			}
			newArray_index--;
	    }
	    else
	    {
	    	j++;
		}
	    
	}
   } 
  
   
 
     printf("\nNewArray[]= ");
    for(i=0;i<newArray_index;i++)
   {
   	printf("%d ", newarray[i]);
   }
	
	return 0;
}



