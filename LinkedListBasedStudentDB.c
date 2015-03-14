///**********************************************************************///
///******     	   Linked List Student Database Application	      	   ******///
///******   Title: addtoFront, addtoEnd, Addat Positions ,  *******/
/*             Delete functions and Traverse Functions         ******///
///******                  			                   ******///
///******  	        [DataStructure Course, 2015]  		   ******///
///******	  Biomedical Engineering, Cairo University	   ******///
///**********************************************************************///
/*          		 by Mohamed Hisham March 2015 */
///**********************************************************************///

#include <stdio.h>
#include <stdlib.h>

#define WORKING 1
#define EXIT 0

//Declaring Data Structures
typedef struct record
	{
		char name[20];
		short age;	
	}record;
typedef struct node node;
struct node
{
	record data;
	node * next;
};

//functions prototype
void traverseLinkedList(node *head);
node* addAtPosition(node *head,record data);
node* addToFront(node * head ,record data);
void addToEnd(node* head , record data);
node* deleteFront(node* head);
node* deleteEnd(node* head);
node* deleteAtPosition(node * head);
node* deleteALL(node* head);

void printOptions()
{
	printf("\n................ Ready .......................\n\n #Options::.....\n");
	printf("	a : print All the list\n");
	printf("	f : add new Element to the Front\n");
	printf("	b : add new Element at Position\n");
	printf("	e : add new Element at The End\n");
	printf("	d : Delete Front Element\n");
	printf("	r : Delete End Element\n");
	printf("	q : Delete Element at position\n");
	printf("	A : Delete All Elements\n");
	printf("	x : to Exit\n");
}

int main()
{
	short status = WORKING;
	char option;
	node *head = NULL;
	record TempData;



	printf("        |--------------------------------------------------------|\n");
	printf("        |	    Welcome to my Quick list Tutorial	         |\n");
	printf("        |          'The Linked List Version' 			 |\n");
	printf("        |--------------------------------------------------------|\n");
	

	while(status)
	{	
		printOptions();
		scanf(" %c",&option);
		switch (option)
		{
			case 'a':
				traverseLinkedList(head);
			break;
			case 'b':
				printf("  Kindly Enter the Name of the new Record : ");
				scanf("%s",TempData.name);
				printf("  Kindly Enter the Age of the new Record  : ");
				scanf("%hd",&(TempData.age));
				head = addAtPosition(head,TempData);
			break;
			case 'f':
				printf("  Kindly Enter the Name of the new Record : ");
				scanf("%s",TempData.name);
				printf("  Kindly Enter the Age of the new Record  : ");
				scanf("%hd",&(TempData.age));
				head = addToFront(head,TempData);
			break;
			case 'e':
				printf("  Kindly Enter the Name of the new Record : ");
				scanf("%s",TempData.name);
				printf("  Kindly Enter the Age of the new Record  : ");
				scanf("%hd",&(TempData.age));
				addToEnd(head,TempData);
			break;
			case 'd':
				head = deleteFront(head);
			break;
			case 'r':
				head = deleteEnd(head);
			break;
			case 'q':
				head = deleteAtPosition(head);
			break;
			case 'A':
				head = deleteALL(head);
			break;
			case 'x':
				status = EXIT;
			break;
			default :
				printf(" ERROR : InValid option \n");
		}
	}

	printf("   >>Exiting...... \n    ***Thank You*** \n\n");

	return 0;
}


void traverseLinkedList(node *head)
{
	node *ptr = head;
	short counter = 1;

	if(head == NULL)
	{
		printf("      >>List is Already Empty\n");
		return;
	}

	while(ptr !=NULL)
	{
		printf("    Record [%hd] name is :%s ,and Age is : %d \n",counter,ptr->data.name,ptr->data.age);
		ptr = ptr->next;
		counter++;
	}

}


// this function Add Node at Position
node* addAtPosition(node *head,record data)
{
	short newNode_Position  = 0 ;
	short i 	 			= 1 ;	 
	node *ptr 				= head;


	printf("  Kindly Enter the position of the new Node : ");
	scanf("%hd",&newNode_Position);

	if(head == NULL || newNode_Position == 1) // case of empty list
	{
		if(head == NULL) printf(">>Adding to front as list is empty\n");
		head = addToFront(head,data);
		return head ;
	}

	for(i=1;i<newNode_Position-1;i++) // moving to the node just before the postion we want to add new node at
	{
		if(ptr==NULL)
		{
			printf("\n Invalid Position!!, as the List is Shorter than %d elements \n",newNode_Position);
			return head;
		}
		ptr = ptr->next;
	}

 //Creating a New node
	node *newnode = NULL;
	newnode = (node*)malloc(sizeof(node));
	if(newnode == NULL)
	{
		printf("Error , No Available Memory\n");
		return head;
	}
 //updating Data
	newnode->data = data;
 //updating linked list
	newnode->next = ptr->next;
	ptr->next     = newnode;


	printf("New Node is Added");
	return head;
}
node* addToFront(node * head ,record data)
{	
	//Creating a New node
	node *newnode = NULL;
	newnode = (node*)malloc(sizeof(node));
	if(newnode == NULL)
	{
		printf("Error , No Available Memory\n");
		return head;
	}
	//updating Data
	newnode->data = data;
	//updating Linked List
	newnode->next = head;  
	head = newnode;

	printf("New Node is Added");
	return head;
}
void addToEnd(node* head , record data)
{
	node* ptr   = head;
	if(head == NULL)
	{
		printf("List is Empty !!, add to Front First\n");
		return;
	}

	//go to the end
	while(ptr->next !=NULL )
		ptr = ptr->next;

	ptr->next = (node*)malloc(sizeof(node));
	if(ptr->next == NULL)
	{
		printf("Error , No Available Memory\n");
		return;
	}
	ptr = ptr->next;
	ptr->data = data;
	ptr->next = NULL; 
}

node* deleteFront(node* head)
{
	node *ptr = head;
	if(head == NULL)
	{
		printf(" List is Already Empty \n\n");
		return head;
	}
	head 	  = head->next; //works fine if only one node exist.
	free(ptr);
	return head ;
}

node* deleteEnd(node* head)
{
	node *ptr = head;
	if(head == NULL)
	{
		printf(" List is Already Empty \n\n");
		return head;
	}
	if(ptr->next == NULL) // one element condition
	{
		free(ptr);
		return (head = NULL);
	}

	while((ptr->next)->next !=NULL) //go to the end
		ptr = ptr->next;

	free(ptr->next);
	ptr->next = NULL;
	return head;
}

node* deleteAtPosition(node * head)
{
	short Delete_Position  = 0 ;
	short i 	 		   = 1 ;	
	node* ptr 			   = head;
	node* DeletedNode      = NULL;

	printf("  Kindly Enter the position of the Node to be Deleted : ");
	scanf("%hd",&Delete_Position);

	if(head == NULL) // case of empty list
	{
		printf(">> list is Already empty\n");
		return head ;
	}
	if(Delete_Position == 1) // case of Deleting the head Node
		return deleteFront(head);
	if(Delete_Position < 1) // in case of wrong index
		printf("There is no Such Position Crazy !!\n");

	for(i=1;i<Delete_Position-1;i++)
	{
		if(ptr==NULL)
		{
			printf("\n Invalid Position!!, as the List is Shorter than %d elements \n",Delete_Position);
			return head;
		}
		ptr = ptr->next;
	}
	DeletedNode = ptr->next;
	ptr->next = (ptr->next)->next;
	free(DeletedNode);
	return head;

}

node* deleteALL(node* head)
{
	while(head != NULL)
		head = deleteFront(head);


	printf("Done!! , List have been evacuated \n");
	return head;
}

