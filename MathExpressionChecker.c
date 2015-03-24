///**********************************************************************///
///******     	   Math Expression Paranthesis Checker	      	   ******///
///******  		Stack Application with Linked List Implementation  *******/

///******                  			                   ******///
///******  	        [DataStructure Course, 2015]  		   ******///
///******	  Biomedical Engineering, Cairo University	   ******///
///**********************************************************************///
/*          		 by Mohamed Hisham March 2015 */
///**********************************************************************///
#include <stdio.h>
#include <stdlib.h>


typedef struct element element;
struct element
{
	char Character;
	element *next;
};

element *top = NULL;

void pushToStack(char Data)
{
	element *newElement = NULL;
	newElement          = (element*)malloc(sizeof(element));

	if(newElement == NULL)
	{
		printf("No Memory Avaliable\n");
		return;
	}

	newElement->Character = Data;
	newElement->next 	  = top;
	top 				  = newElement;

	return;
}

char popFromStack()
{
	if(top == NULL)
		return;  //or return any thing rather than () []
	element *oldTop = top;
	top 			= top->next;

	char popElement = oldTop->Character;
	free(oldTop);

	return popElement;
}

char topStack()
{
	if(top == NULL)
		return;  //or return any thing rather than () []
	return top->Character;
}

void main()
{
	char inputChar;
	char collector;

	printf("Kindly Enter the Mathematical Expression to be checked :");

	while((inputChar=getchar()) != '\n' )
	{
		if( (inputChar == '(') || (inputChar == '[')  )
			pushToStack(inputChar);

		else if( (inputChar == ')') || (inputChar == ']') )
		{// check if the detected Char is pair for the stack top character
			collector   = topStack(); // if nothing is returned then the stack is empty and the expression is not balanced
			if( (inputChar-1 == collector) || (inputChar-2 == collector) ) //inputchar-1 , '(' > ')', inputchar-2 '[' > ']'
			{
				popFromStack();
			}else
			{
				printf("Expression is Not Balanced\n");
				return;
			}
		}
	}
	if(top == NULL)
		printf("Expression is Balanced \n");
	else
		printf("Expression is Not Balanced\n");

}


