///**********************************************************************///
///******     	   Array Student Database Application	      	   ******///
///******   Title: add , Delete , Print Functions ,  *******/

///******                  			                   ******///
///******  	        [DataStructure Course, 2015]  		   ******///
///******	  Biomedical Engineering, Cairo University	   ******///
///**********************************************************************///
/*          		 by Mohamed Hisham March 2015 */
///**********************************************************************///

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define Working 1
#define Exit 0
#define MAX_SIZE 10

typedef struct record
	{
		char name[20];
		short age;	
	}record;

void showlist(record *list,short listsize);
void addNewElement(record *list ,short *listsize);
void printOptions();
void deleteElement(record *list ,short *listsize);
void copyArray(record *list,short index,short listsize);

int main()
{
	short status = Working;
	char option;
	// or typedef struct record record
	

	record mylist[MAX_SIZE];
	short listsize = 0;
	printf(" 	-----------------------------------------------------\n");
	printf("		Welcome to my Quick List\n");
	

	while(status)
	{	
		printOptions();
		scanf(" %c",&option);
		switch (option)
		{
			case 'a':
				showlist(mylist,listsize);
			break;
			case 'b':
				addNewElement(mylist,&listsize);
			break;
			case 'd':
				deleteElement(mylist ,&listsize);
			break;
			case 'x':
				status = Exit;
			break;
			default :
				printf(" ERROR : InValid option \n");
		}
	}

	printf("Exiting...... \n  ***Thank You*** \n\n");

	return 0;
}


void showlist(record *list,short listsize)
{
	short i=0;
	if(listsize!=0)
	{
		for(i=0;i<listsize;i++)
		{
			printf("record [%d] Name is: %s , Age is : %hd \n",i, list[i].name,list[i].age);
		}	
	}else 
	printf("  >>>Error :List is empty\n");
	
}

void printOptions()
{
	printf("\n..... Ready .......................\n\n #Options::.....\n");
	printf("	a : print All the list\n");
	printf("	b : add new Element to the Database\n");
	printf("	d : Delete an Element\n");
	printf("	x : to Exit\n");
}

void addNewElement(record *list,short *listsize)
{
	int AddFlag = 1;
	int counter = *listsize;
	char status = 'n';

	if(*listsize>=MAX_SIZE)
	{
		printf("List is FULL\n");
		return;
	}

	do
	{	
		printf("Kindly Enter the Name of the new Record : ");
		scanf("%s",(list+*listsize)->name);
		printf("Kindly Enter the Age of the new Record : ");
		scanf("%hd",&((list+*listsize)->age));
		*listsize = *listsize +1;
		printf("\n would you like to add new Element? \n>> Type :Y to add\n>> other to Exit\n ::");
		scanf(" %c",&status);
		if(status != 'Y')
			AddFlag = 0;


	}while(AddFlag && (*listsize<10));

	printf("\nDone %d record added\n--------------------------------\n\n",*listsize-counter);
}


void deleteElement(record *list ,short *listsize)
{
	short index;
	char confirm = 'n';
	printf("..... Here is the list......\n.....kindly give me the index of the element that you want to delete\n\n");
	showlist(list,*listsize);
	printf("\n  >>>index of element to be deleted :  ");
	scanf("%hd",&index);

	if(index>=0 && index <*listsize)
	{
		printf("\n  >>>Are you sure you want to Delete Record : %d (type 'Y' to confirm } ::",index);
		scanf(" %c",&confirm);
		if(confirm == 'Y')
		{
			if(index+1 != *listsize)
			{
				copyArray(list,index,*listsize);
			}
			
			*listsize = *listsize -1;
		}
		else
			printf("\n .......Nothing Done \n");
			
	}else 
		printf("\n.......Error Invalid index or list is empty\n");

}

void copyArray(record *list,short index,short listsize)
{
	short i ;
	for(i=index ; i<listsize-1;i++)
	{
		strcpy(list[i].name,list[i+1].name);
		list[i].age = list[i+1].age;
	}
}
