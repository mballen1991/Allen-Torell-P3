#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <limits.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <dirent.h>
#include <iostream>
#include <time.h>
#include <cstdlib>
#include <grp.h>
#include <sstream>
#include <time.h>

using namespace std;

void printMonth(int startDay, int numDays, int month, int year)
{

	time_t t = time(NULL);
	tm* timePtr = localtime(&t);

	cout << "    ";

	switch(month)
	{
		case 1 : cout << "January";
			break;
		case 2 : cout << "February";
			break;
		case 3 : cout << "March";
			break;
		case 4 : cout << "April";
			break;
		case 5 : cout << "May";
			break;
		case 6 : cout << "June";
			break;
		case 7 : cout << "July";
			break;
		case 8 : cout << "August";
			break;
		case 9 : cout << "Septermber";
			break;
		case 10: cout << "October";
			break;
		case 11: cout << "November";
			break;
		case 12: cout << "December";
			break;
	}
	
	cout << " ";

	cout << year << "   " << endl;

	cout << "Su Mo Tu We Th Fr Sa" << endl;

	



	int jumpCounter = 0;


	//cout << startDay << endl;
	
	if ( startDay != 0 ) 
	{
		for ( int i = 0; i < startDay; i++)
		{
			cout << "   ";
			jumpCounter ++;
		}
	}
	
	for ( int i = 1; i <= numDays; i++)
	{

		if ( ( year == timePtr->tm_year + 1900 ) && ( month == (timePtr->tm_mon)+1 )
			&& ( i == timePtr->tm_mday) )
		{
			cout << "\x1b[7m";
		}
		
		if ( jumpCounter%7 == 0 && i != 1)
		{
			cout << "\n";
		}

		if ( i < 10 )
		{
			cout << " ";
		}
	
		cout << i;

		cout << "\x1b[0m";
	
		cout << " ";

		if ( year == 1752 && month == 9 && i == 2)
		{
			i += 11;
		}

		jumpCounter++;
	}
	cout << endl << endl;

		

}

void calcMonth(int month, int year)
{
	
	//int iMonth = month;
	int iYear = year;
	int firstDay;

	
	if (( year < 1752) || (year == 1752 && month <= 8))
	{	
			int yearCounter = 1;
			firstDay = 6;
			while ( yearCounter < year )
			{
				firstDay++;
				yearCounter++;
				if ( (yearCounter-1)%4 == 0)
				{
					firstDay ++;
				}
				//cout << "bing!" << endl;
			}
			firstDay = firstDay%7;
	}
	if (( year > 1752) || (year == 1752 && month >=10))
	{
	
	int day = 1;
	int y = iYear - (14-1/**month**/)/12;
	int m = 1/**iMonth**/ + 12 * ((14-1/**month**/) / 12) -2;
	firstDay = (day+y+y/4-y/100+y/400+(31*m/12))%7;
	}

	int numberOfDays = 0;
	int dayCount;
	int monthCount = 1;

	while ( monthCount < month )
	{
		if ( monthCount == 1 )
		{
			numberOfDays += 31;
			if ( year%4 == 0)
			{
				if ( year%100 == 0)
				{
					if ( year%400 == 0)
					{
						dayCount = 29;
					}
					else
					{
						dayCount = 28;
					}
				}
				else
				{
					dayCount = 29;
				}
			}
			else
			{
				dayCount = 28;
			}
			
			
		}
		if ( monthCount == 2)
		{
			if ( year%4 == 0 )
			{
				if ( year%100 == 0 )
				{
					if ( year%400 == 0)
					{
						numberOfDays += 29;
					}
					else
					{
						numberOfDays += 28;
					}
				}
				else
				{
					numberOfDays += 29;
				}
			}
			else
			{
				numberOfDays += 28;
			}
			dayCount = 31;	//dayCount keeps count of the number of days in that month(which is next)
		}
		if ( monthCount == 3)
		{
			numberOfDays += 31;
			dayCount = 30;
		}
		if ( monthCount == 4)
		{
			numberOfDays += 30;
			dayCount = 31;
		}
		if ( monthCount == 5)
		{
			numberOfDays += 31;
			dayCount = 30;
		}
		if ( monthCount == 6)
		{
			numberOfDays += 30;
			dayCount = 31;
		}
		if ( monthCount == 7)
		{
			numberOfDays += 31;
			dayCount = 31;
		}
		if ( monthCount == 8)
		{
			numberOfDays += 31;
			dayCount = 30;
		}
		if ( monthCount == 9)
		{
			numberOfDays += 30;
			dayCount = 31;
		}
		if ( monthCount == 10)
		{
			numberOfDays += 31;
			dayCount = 30;
		}
		if ( monthCount == 11)
		{
			numberOfDays += 30;
			dayCount = 31;
		}
		if ( monthCount == 12)
		{
			numberOfDays += 31;
		}
		monthCount ++;
	}

	if ( month > 1 )
	{
		firstDay = firstDay + numberOfDays;
		firstDay = firstDay%7;
	}
	else
	{
		numberOfDays = 31;
		dayCount = 31;
	}

	if ( year == 1752 && month == 9 )
	{
		dayCount = 30;
		firstDay = 2;
	}
	
	//cout << firstDay << endl; 
	printMonth(firstDay, dayCount, month, year);
}

int main (int argc, char **argv)
{

	time_t theTime = time(NULL);
	struct tm *aTime = localtime(&theTime);

	int month = aTime->tm_mon + 1;
	int year = aTime->tm_year + 1900;

	cout.setf(ios_base::unitbuf);	
	
	if ( argc == 1)
	{
		calcMonth(month, year);
	}
	else
	{
		if ( argc == 2 )
		{
			for ( int i = 1; i <= 12; i++)
			{
				calcMonth(i, atoi(argv[1]));
			}
		}
		else
		{
			if ( argc == 3)
			{
				calcMonth(atoi(argv[1]), atoi(argv[2]));
			}
			else
			{
				cout << "Please enter valid entries!" << endl;
			}
		}
	}
	
	

}
