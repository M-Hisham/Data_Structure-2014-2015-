/**********************************************************************/
/****** 				Linked List Basic Tutorial */
/* *this code is to illustrate how to:
	    ** add node to the front
	    ** Delete node at arbitrary Position              */
	  
/* Please Node that this code Don't contain any safety or error Handling */

/****** 			[DataStructure Course, 2015] */
/****** 			Biomedical Engineering, Cairo University ******/
/**********************************************************************/
/* 				by Mohamed Hisham March 2015 */


#include <stdio.h>

typedef struct Node node;

struct Node
{
	short data;
	node *next;
};

void main()
{
	node * head = NULL;
	short Data = 5;
	head = addToFront(Data,head);
}

node* addToFront(short x,node* head)
{
	node* newNode =NULL;
	newNode = (node*)malloc(sizeof(node));// Create Node
	if(newNode == NULL)
	{
		printf("No Available Memory\n");
		return head;
	}
	//
	newNode->data = x;
	//
	newNode->next = head;
	head 		  = newNode;

	return head;
}

void DeleteAtPosition(int position,node* head)
{
	int index;
	node* ptr = head;
	for(index=1;index<position-1;index++) //[1]
		ptr = ptr->next;

	node* ptr_ToBeDeleted = ptr->next; //[2] saving pointer of the node to be deleted
	ptr->next = ptr_ToBeDeleted->next;//  [3]
		
	free(ptr_ToBeDeleted) //[4]
}

