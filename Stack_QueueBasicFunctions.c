///**********************************************************************///
///******     	   Not Completed Palindron Checker Application	      	   ******///
///******   	Title: push , pop , enqueue ,dequeue Functions  	*******/
/*            		with Linked List Structure    			  ******///
///******                  			                   ******///
///******  	        [DataStructure Course, 2015]  		   ******///
///******	  Biomedical Engineering, Cairo University	   ******///
///**********************************************************************///
/*          		 by Mohamed Hisham , March 2015 */
///**********************************************************************///

#include <stdio.h>
#include <stdlib.h>


typedef struct element node;
struct element
{
	char Character;
	node *next;
};

//Global Varibles
node *top   = NULL;
node *front = NULL;
node *rear = NULL;

//Stack Functions.................................
void pushToStack(char Data)
{
	//Create new node
	node *newElement 	= NULL;
	newElement          = (node*)malloc(sizeof(node));

	if(newElement == NULL)
	{
		printf("No Memory Avaliable\n");
		exit(EXIT_FAILURE);
	}
	//update the data
	newElement->Character = Data;

	//update LL
	newElement->next 	  = top;
	top 				  = newElement;

	return;
}

char popFromStack()
{
	if(top == NULL)
		return;
	node *oldTop 	= top;
	top 			= top->next;

	char popElement = oldTop->Character;
	free(oldTop);

	return popElement;
}

//Queue Functions.................................

void enqueue(char Data)
{
	node *newElement 	= NULL;
	newElement          = (node*)malloc(sizeof(node));

	if(newElement == NULL)
	{
		printf("No Memory Avaliable\n");
		exit(EXIT_FAILURE);
	}

	//filling Date:
	newElement->Character = Data;
	newElement->next	  = NULL;
	//updating Addresses
	if(rear != NULL)
		rear->next	= newElement;
	else //rear == NULL
		front       = newElement;;
	
		rear 		= newElement;

}

char dequeue()
{
	if(front == NULL)
	{
		printf("Error Queue is Empty\n");
		exit(EXIT_FAILURE);
	}
	//Data
	char dequeuedData = front->Character;
	//updating address
	node* freeNode 	  = front;
	front			  = front->next;

	if(front == NULL)
		rear = NULL;   //this condition works if we dequeue the last element in the queue , so we can reset the rear too

	free(freeNode);
	return dequeuedData;

}


// warning this function is not compeleted 
// continue it in your ownway
void main()
{
	char inputChar;
	printf("Kindly Enter the Word to be checked :");

	while( (inputChar = getchar()) != '\n' )
	{
		pushToStack(inputChar);
		enqueue(inputChar);
	}
	
}
