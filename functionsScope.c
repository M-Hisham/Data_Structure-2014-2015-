/**********************************************************************/
/******     	         Functions & Variable Scope 	     		   */
/* this code is to illustrate how to declare/indentify/call a function
/******  				[DataStructure Course, 2015]  	         		*/
/******   	  Biomedical Engineering, Cairo University	   ******/
/**********************************************************************/
/*                                                            	*/
/*   		      by Mohamed Hisham Feb 2015  	   	*/


#include <stdio.h>
int x = 1000;  // here we Declare and indentify x as a Global Variable
// extern int x; here is only to declare but don't make a place in the memory
// Note: use extern only if you want to use x in other files
int sum(int x,int y);//  function declaration
int print();  //  function declaration
void print2 ();  //  function declaration

void main()
{
	printf("size of integer is %lu \n",sizeof(int));
	int x = 10;  
	int y = 20;
	int result;
	result = sum(x,y);
	//printf("result of summation of %d + %d is :%d \n",x,y,result);
	printf("print x in main :%d \n",x);
	result=print();
	print2();
}

int print() //  function identification
{
	int x = 100;  // use is local variable 
	//x = 100 ;
	printf("print x in external function :%d \n",x);
	return 0;

}

void print2()  //  function identification
{
	//int x ;
	printf("print x in external function2 :%d \n",x);

}

int sum(int x,int y) // //  function identification
{
	int sumresult = x+y ;

	return sumresult;
}
