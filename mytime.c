
/**********************************************************************/
/****** data and time using time fnuction  */
/* this function callculate the date and time of today using number of seconds since epoch
/****** [DataStructure Course, 2015] */
/****** Biomedical Engineering, Cairo University ******/
/**********************************************************************/
/* */
/* by Mohamed Hisham Feb 2015 */

#include <stdio.h>
#include <time.h>	 // add for the built in function time
#include <stdlib.h>  // added for the exit function

#define EPOCH_YEAR 1970

// Functions Decleration ( prototype )
int getLeapYears_Num(int currentYear);
void printDate(int seconds_1970 , int leapYears_Num,int currentYear);
int isLeapYear (int year);

// The main Function 
void main()
{

	short leapYears_Num;
	// get number of 
	time_t seconds_1970 = time(	NULL);
	//seconds_1970 += 60*60*24*2;  // jumper in days for testing
	// check for errors
	if(seconds_1970 == (time_t)-1 )
	{
		printf("Error to get time \n");
		exit(EXIT_FAILURE);
	}

	printf("\nTime in second since \"UNIX EPOCH\" Thursday, 1 January 1970: %d \n",(int)seconds_1970);
	// calculating number of elapsed Years elapsed
	int elapsedYears = (int)seconds_1970 / (60*60*24*365);

	//printf("Number of elapsed Years since 1970 is %d \n& your are in %d \n",elapsedYears ,( EPOCH_YEAR+elapsedYears));
	leapYears_Num = getLeapYears_Num(EPOCH_YEAR+elapsedYears);

	printf("\n\tNumber of Leap Years Since %d is %d \n", EPOCH_YEAR ,leapYears_Num);

	//print current date
	printDate(seconds_1970,leapYears_Num, EPOCH_YEAR+elapsedYears);


}

/* function to print the Date 
Input : number of seconds since 1 jan 1970
	  : number of leap Years
	  : current Year 
Output: printing the Date*/
void printDate(int seconds_1970 , int leapYears_Num,int currentYear)
{
	int temp 		= seconds_1970 / (60) ; //give minutes
	int min 		= temp % (60) ;  // lefted min
	temp 			= temp / 60; //give hours
	int hours   	= temp % 24;    //lefted hours that don't complete a Day
	temp			= temp / 24; // give Days 
	int days 	 	= (temp % 365)-leapYears_Num+1; // lefted Days that dont fill a Year ,days compensated in leap years (366 days) 
	// one is added to the days at printing at number of days don't include that day yet( not complete )
	char *month;
	temp=28+isLeapYear(currentYear); // number of days to be removed from days
	//printf("temp is %d\n", temp); // testing
	/*Getting Month */
	if(days <= 31 )
		month ="Jan";
	else if ( (days-=31) <=temp)
		month ="Feb";
	else if ( (days-=temp) <= 31)
		month ="Mar";
	else if ((days-=31) <= 30)
		month ="Apr";
	else if ((days-=30) <= 31)
		month ="May";
	else if ((days-=31) <= 30)
		month ="Jun";
	else if ((days-=30) <= 31)
		month ="Jul";
	else if ((days-=31) <= 31)
		month ="Aug";
	else if ((days-=31) <= 30)
		month ="Sep";
	else if ((days-=30) <= 31)
		month ="Oct";
	else if ((days-=31) <= 30)
		month = "Nov";
	else
	{
		month ="Dec";
		days -=30;
	} 
	
printf("Today is %d %s %d and Time is %d:%d in GMT\n\n",days,month,currentYear,hours,min );
	
}


/* function to calculate number if leap years
Input : current Year 	  
Output: return number of Leap Years*/
int getLeapYears_Num(int currentYear)
{
	printf("\nPrinting Leap Years Since 1970 ...... \n \t");
	int leapYears_Num = 0;
	for (int i =0 ; i<=(currentYear-EPOCH_YEAR) ; i++)
	{
		if( ( (EPOCH_YEAR+i)%4 == 0 ) && ( (EPOCH_YEAR+i)%100 != 0) || ( (EPOCH_YEAR+i)%400 == 0) )
		{
			leapYears_Num++;
			printf("%d ",EPOCH_YEAR+i);
		}
	}
	return leapYears_Num;
}

/* function to check if a Year is a leap one or not
Input : Year to be tested	  
Output: return 1 for leap year , and zero for common Year*/
int isLeapYear (int year)
{
	int result = 0;
	if( ( (year)%4 == 0 ) && ( (year)%100 != 0) || ( (year)%400 == 0) )
		result = 1;

	return result;
}
