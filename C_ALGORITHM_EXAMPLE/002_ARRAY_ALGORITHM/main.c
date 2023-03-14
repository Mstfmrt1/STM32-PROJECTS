/*MUSTAFA MERT DURAN*/

#include <stdio.h>
/*
Kendi içerisinde eleman tekrarý olmayan ( A={2,3,5,8,9…} ) üç farklý sayý dizisi (Ýng. Array) A, B ve
C’nin elemanlarýný aþaðýda verilen kurallara göre tek bir sayý dizisi “D” içerisinde birleþtiriniz.
- Sayýlar “D” dizisinde küçükten büyüðe sýralanmalýdýr.
- Verilen dizilerdeki bir sayý birden fazla kez bulunuyor ise ve bulunma sayýsý çift ise o sayý
“D”de yer almamalýdýr.

Bu fonksiyonun içindeki dizi sayýsý bilinmeyen bir dizi listesi alarak çalýþan ve ayný görevi
yerine getiren geniþletilmiþ halini yazýnýz.


---------------------------------------

Three different number arrays (Eng. Array) A, B and
Combine the elements of C into a single string of numbers "D" according to the rules given below.
- Numbers should be arranged in the "D" sequence from smallest to largest.
- If a number in the given sequences is found more than once and the number of occurrences is even, that number
It should not be in "D".

It works by taking a sequence list with an unknown number of sequences inside this function and performs the same task.
Write the expanded version that fulfills it.
*/
*/

void dispArray(int arr1[],int arr2[],int arr3[],int l1,int l2,int l3);
void fillArray(int arr1[],int arr2[],int arr3[],int l1,int l2,int l3);
nonDuplicate(int arr[],int size);
void selectionSort(int arr[], int n);

int main()

{
    int length1,length2,length3,temp;
    
    printf("Enter first array length: ");
    scanf("%d",&length1);
    printf("Enter second array length: ");
    scanf("%d",&length2);
    printf("Enter third array length: ");
    scanf("%d",&length3);
    
    int firstArray[length1],secondArray[length2],thirdArray[length3];
    
    fillArray(firstArray,secondArray,thirdArray,length1,length2,length3);
    dispArray(firstArray,secondArray,thirdArray,length1,length2,length3);
    
    int mergeArrLength = length1+length2+length3;
    
    int mergeArray[mergeArrLength];
    
    arrayMergeFunc(firstArray,secondArray,thirdArray,mergeArray,length1,length2,length3);
    
    nonDuplicate(mergeArray,mergeArrLength);
    
    selectionSort(mergeArray,mergeArrLength);
    int i=0;
    for( i = 0; i < mergeArrLength; i++){
        printf("Array is: %d\n",mergeArray[i]);
    }

}


void fillArray(int arr1[],int arr2[],int arr3[],int l1,int l2,int l3)//get array member from user
{
    
   int flag=0,i=0;
   while(flag!=l1)
   {
       int temp;
       printf("Enter Array1[%d]",flag);
       scanf("%d",&temp);
       for(i=0;i<l1;i++)
       {
           if(arr1[i]==temp)
           {
               while(temp==arr1[i])
               {
                 printf("Please enter member again Array1[%d] ",flag);
                 scanf("%d",&temp);
               }
               
               
           }
       }
       arr1[flag++]=temp;
       
   }
   flag=0,i=0;
   
   while(flag!=l2)
   {
       int temp;
       printf("Enter Array2[%d]",flag);
       scanf("%d",&temp);
       for(i=0;i<l2;i++)
       {
           if(arr2[i]==temp)
           {
               while(temp==arr2[i])
               {
                 printf("Please enter member again Array2[%d] ",flag);
                 scanf("%d",&temp);
               }
               
               
           }
       }
       arr2[flag++]=temp;
       
   }
   flag=0,i=0;
   while(flag!=l3)
   {
       int temp;
       printf("Enter Array3[%d]",flag);
       scanf("%d",&temp);
       for(i=0;i<l3;i++)
       {
           if(arr3[i]==temp)
           {
               while(temp==arr3[i])
               {
                 printf("Please enter member again Array3[%d] ",flag);
                 scanf("%d",&temp);
               }
               
               
           }
       }
       arr3[flag++]=temp;
       
   }
   
}

void dispArray(int arr1[],int arr2[],int arr3[],int l1,int l2,int l3)//PRINT
{
	int i=0;
    for( i=0;i<l1;i++){
        printf("firstArray[%d] : %d\n",i,arr1[i]);
    }
    for( i=0;i<l2;i++){
        printf("secondArray[%d] : %d\n",i,arr2[i]);
    }
    for( i=0;i<l3;i++){
        printf("thirdArray[%d] : %d\n",i,arr3[i]);
    }
}


void arrayMergeFunc(int arr1[],int arr2[],int arr3[],int arrToMerged[],int l1,int l2,int l3)//MERGE ARRAYS
{
    int i=0,j=0,k=0;
    int index = 0;
    
    for(i = 0;i<l1;i++){
        arrToMerged[index++] = arr1[i];
    }

    for(i = 0;i<l2;i++){
        arrToMerged[index++] = arr2[i];
    }

    for(i = 0;i<l3;i++){
        arrToMerged[index++] = arr3[i];
    }
}


nonDuplicate(int arr[],int size)//remove repeating elements
{
    
    int i=0,j=0,k=0;
    
    for(i=0;i<size;i++)
   {
   	for(j=i+1; j<size;)
   	{
   		if(arr[j]==arr[i])
   		{
   			
   			for(k=j;k<size;k++)
   			{
   				arr[k]=arr[k+1];
			}
			size--;
	    }
	    else
	    {
	    	j++;
		}
	    
	}
   } 
    
}


void selectionSort(int arr[], int n)//ORDERING THE ELEMENTS
{
   int i=0,j=0,temp;
   for(i=0;i<n;i++)
   {
   	for(j=i+1;j<n;j++)
   	{
   		if(arr[i]> arr[j])
   		{
   			temp=arr[i];//the element to be changed is i=0 , temp 0.element
   			arr[i]=arr[j]; 
   			arr[j]=temp;
   			
		}
	   }
   }
}





