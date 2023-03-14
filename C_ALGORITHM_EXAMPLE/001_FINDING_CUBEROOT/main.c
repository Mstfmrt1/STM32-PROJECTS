#include <stdio.h>
#include <stdlib.h>

//Write a program that finds the cube root of a given number ("X") (without function).
// num^3 = num*num*num
// num = cuberoot(num)*cuberoot(num) 
// cube root num= i , i*i*i 
int main(int argc, char *argv[]) {
	
	
	//FINDING SQUARE ROOT


	/*double sayi,i;
	printf("please enter a number\n");
	scanf("%lf",&sayi);
	for(i=0;i*i<sayi;i+=0.000001);
	printf("%f\n",i);
	*/
	
	//FINDING CUBE ROOT
	double i,number ;
	
	double precision =0.000001;
	printf("Please enter a number\n");
	scanf("%lf",&number);
	for(i=0;i*i*i<=number;i+=precision);
	printf("The cube root of %f is  %.2f\n",number,i);
	
	
   
	 getch(); 
	

	return 0;
}
