///**********************************************************************///
///********     	     Sorting Techniques     		 ********///
///********   Title: SelectionSort, BubbleSort , QuickSort	 ********///

///******  	        [DataStructure Course, 2015]  		   ******///
///******	  Biomedical Engineering, Cairo University	   ******///
///**********************************************************************///
/*          		 by Mohamed Hisham , March 2015 */
///**********************************************************************///



#include <stdio.h>
#include <stdlib.h>

#define MaxSize 10

void selectionSort(int *sortMe , short start,short end);
void quickSort(int *sortMe , short start,short end);
void bubbleSort(int *sortMe , short start,short end);
void swap(int *x, int *y);

int main ()
{

	int arr[MaxSize],i;
	
	/// Initialization of the array with random numbers 
	for(i=0; i<MaxSize; i++)
	arr[i]=rand()%100;
	
	/// print all array elements before sorting.
	printf("\n** Unsorted Original %d Elements :\n     ",MaxSize);
	for(i=0; i<MaxSize; i++)
	printf("%d ", arr[i]);

	//sorting
	//selectionSort(arr,0,MaxSize-1);
	//quickSort(arr,0,MaxSize-1);
	bubbleSort(arr,0,MaxSize-1);

	/// print all array elements after sorting
	printf("\n** Sorted Elements : \n     ");
	for(i=0; i<MaxSize; i++)
	printf("%d ",arr[i]);
	printf("\n\n ****************Thanks************* \n");
	
	
}

void bubbleSort(int *sortMe , short start,short end)
{
	short i,j,flag;

	for(j=0;j<=end;j++) // or do while loop with swaping flag is the most efficient 
	{
		for(i=0;i<end-j;i++)// enhanced 
		{
			if(sortMe[i] > sortMe[i+1])
			{
				swap(&sortMe[i],&sortMe[i+1]);
			}
		}
	}

}

void quickSort(int *sortMe , short start,short end )
{
	if(start<end)
	{
		// initiating variables
		short i;
		// Selecting pivot
		int pivot   		 = sortMe[end];
		short partitionIndex = start;

		// partitioning
		for(i=start;i<end;i++)
		{
			if(sortMe[i] <= pivot)
			{
				swap(&sortMe[i],&sortMe[partitionIndex]);
				partitionIndex++;
			}
		}
		swap(&sortMe[partitionIndex],&sortMe[end]);

		quickSort(sortMe,partitionIndex+1,end);  // quicksort the rightpart
		quickSort(sortMe,start,partitionIndex-1); // quicksort the left part
	}

}	



void selectionSort(int *sortMe , short start,short end)
{

	short i ,j;
	int minIndex;

	for(j=start ;j<=end;j++)
	{
		// searching for min
		minIndex = j;
		for(i=j+1;i<=end ; i++)
		{
			if(sortMe[i] < sortMe[minIndex] )
				minIndex = i;
		}
		// swap min with first location
		swap(&sortMe[j],&sortMe[minIndex]);
	}

}


void swap(int *x, int *y)
{
	int temp = *x;
	*x		 = *y;
	*y    	 = temp;
}
