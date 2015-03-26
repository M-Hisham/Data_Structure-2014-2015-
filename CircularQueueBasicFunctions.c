///**********************************************************************///
///******     	   Circular Queue Basic Functions	      	   ******///
///******  Title: Insert, Traverse, Delete, and GetSize Functions  ******///
///******                  			                   ******///
///******  	        [DataStructure Course, 2015]  		   ******///
///******	  Biomedical Engineering, Cairo University	   ******///
///**********************************************************************///
/*       by Ahmed AbdelHady 2014 , Modified By Mohamed Hisham March 2015 */
///**********************************************************************///

#include <stdio.h>
#include <stdlib.h>



/// Maxnumber for the Array is 10
#define MaxSize 10

//Front and rear are declared here as a Global Variables
/// initialization of front and rear with -1 to point at nothing 
/// note that the first index to insert in is 0
int front= -1; // front is designed to point at the element before the one that should be dequeued
int rear= -1; // rear is designed to point at the recent added element 

void inQueue (int* queue, int value);// pass the Queue Array , and the Value to be Added
void cirQueueTraverse (int* queue);
int dequeue (int* queue);
int cirQueueSize();// need rear and front to calculated the size , so nothing to pass

int main ()
{
	int queue[MaxSize]; 
	int data;
	
 //calling the inqueue Function 
	inQueue (queue, 4);

	// calling the Traverse function
	cirQueueTraverse(queue);
	


//calling the dequeue Function 
	data= dequeue(queue);

printf("Queue Size=%d \n", cirQueueSize());
	
}



/// add new element in the circular queue
void inQueue (int* queue, int value)
{
	if ( ((rear+1) % MaxSize) == front)
		printf("Error: queue full \n");
	else
	{
		rear= (rear+1) % MaxSize; // the same as regular Queue , but we get aslo the modulos to jump
		queue[rear] = value;
	}
}


/// remove element out of the circular queue
int dequeue (int* queue)
{
	if (front == rear)
	{
		printf("Error: queue empty \n");
		exit(1);
	}
	else
	{
		front= (front+1) % MaxSize;  // the same as regular Queue , but we get aslo the modulos to jump
		return queue[front];
	}
}

/// return the occupied size of the circular queue
int cirQueueSize()
{ // please note that the % is usless when the number is less than MaxSize
	int size= ((rear-front) + MaxSize) % MaxSize;// rear - front to get the size , but what if front is bigger than the rear , at then we get the size of the empty part , so we add the max to get the full part 
	return size;  // and get the % to cut the size if ( rear-front) is positive 
}

/// print all circular Queue elements 
void cirQueueTraverse (int* queue)
{

	if (front==rear)
	{
		printf("Error: queue empty \n");
		exit(1);
	}
	else
	{
		int temp= front; // start from front , and and stop at rear
		while (temp != rear)
		{
			temp= (temp+1) % MaxSize;// increment the index ( add normally then get the % to jump )
			printf("queue[%d]=%d\n", temp, queue[temp]);	
		}
	}
}


