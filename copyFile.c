/******************************************************************************/
/******     	         Read and writing in Functions 	     		   ********/
/* this function copy the file you type it's name in to new file that the program asks for its name too */
/*the code it also provided with myread function to illustrate how to read in buffers      */
/******  				[DataStructure Course, 2015]  	         		*/
/******   	  Biomedical Engineering, Cairo University	   ******/
/**********************************************************************/
/*                                                            	*/
/*   		      by Mohamed Hisham March 2015  	   	*/

#include <stdio.h>
#include <stdlib.h>

void myread() // unused function , you may use it to read a file and write it's contents on a screen
{
	//first lets read a file , we need to open the file first
	FILE *fPointer = NULL;
	char buff[100];
	fPointer = fopen("words","r");  // read a file named "words" found in the current directory 

	if(fPointer == NULL)
	{
		printf("Error to open file\n");
		exit(EXIT_FAILURE);
	}

	while(!feof(fPointer))
	{
		
		//printf("%c",fgetc(fPointer));
		fgets(buff,100,fPointer);
		printf("%s",buff );		
	}

	


    //close the file after reading
	fclose(fPointer);
}

void main()
{

	char filename[20];
	FILE * fptr_R = NULL ;
	FILE * fptr_w = NULL ;
	int carrier  = 0;
	printf("kindly write the name of the file you want to copy ::");
	scanf("%s",filename);

	printf("printing file :%s ......\n",filename );

	fptr_R = fopen(filename,"r");
	if(fptr_R == NULL)
	{
		printf("....Error Cannot open file \n");
		exit(EXIT_FAILURE);
	}

	printf("kindly write the name of the New ::");
	scanf("%s",filename);

	fptr_w = fopen(filename,"w");
	if(fptr_w == NULL)
	{
		printf("Cannot Create the New file \n");
		exit(EXIT_FAILURE);
	}
	/// way one ( this part has a bug which we read the EOF charachter before we terminate the Array so it is printed)
	
	// while(!feof(fptr_R))
	// {
	// carrier = fgetc(fptr_R);
	// carrier = fputc(carrier,fptr_w);
	// }
	
	// another way  this solution we terminat the while if we find EOF (end of file character) , so it will not print the EOF
	while((carrier = fgetc(fptr_R)) != EOF)
		carrier = fputc(carrier,fptr_w);

	printf("File copied Successfuly \n");
}


