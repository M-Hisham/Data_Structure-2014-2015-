/**********************************************************************/
/******     	         	   Data Types Sizes 	     		   */
/* this code function is to illustrate how to check print Data Types memory size
/******  				[DataStructure Course, 2015]  	         		*/
/******   	  Biomedical Engineering, Cairo University	   ******/
/**********************************************************************/
/*                                                            	*/
/*   		      by Mohamed Hisham Feb 2015  	   	*/


#include <stdio.h> 
#include <time.h>

int main(){

	printf("Hello world \n" );

	int A = 0x7fffffff; // give full range incase of int Datatype of 4 bytes
	char C;
	float f;
	short S;
	long l;
	long *lptr;
	int * intptr;
	time_t T;


	printf("size of integer is : %lu \n  ",sizeof(int));
	printf("max capacity for integer is : %d \n ",A);
	printf("size of char is : %lu \n",sizeof(char));
	printf("size of float is : %lu \n",sizeof(f));
	printf("size of short is : %lu \n",sizeof(S));
	printf("size of long is : %lu \n",sizeof(l));
	printf("size of ptr for long is : %lu \n",sizeof(&l));
	printf("size of ptr for int is : %lu \n",sizeof(intptr));
	printf("size of time_t format is : %lu \n",sizeof(intptr));

	return 0;
}
