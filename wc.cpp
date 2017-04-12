#include<string.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<iostream>
#include<clocale>
#include<cwctype>

using namespace std;

void printInfo( const char * file, int ci, int li, int mi, int wi)
{
	
	//const char * file = argv[1];

	FILE *f = fopen(file, "r");
	if ( f == NULL)
	{
		perror("Error");
	}

	char p;
	char c;

	int wordCount = 1;
	int lineCount = 0;
	int charNum = 0;
	
	while(!feof(f))
	{
		if ( c = fgetc(f))
		{
			charNum ++;
		}
		//if ( (c == ' ' || c == '\n')  && p !=' ')
		if ( c == ' ' || c == '\n')
		{
			wordCount ++;
		}
		if ( c == '\n' )
		{
			lineCount++;
		}
		p = c;
	}
	fclose(f);

	//cout << "Number of words are: " << wordCount << endl;
	if ( li == 1)
	{
		cout << "  " << lineCount;
	}
	if ( wi == 1)
	{
		cout << "  " << wordCount;	//what constitutes a word?
	}
	if ( mi == 1)
	{
		cout << "  " << charNum-1;
	}
	cout << "  " << file << endl;

}

int main (int argc, char **argv)
{

	cout.setf(ios_base::unitbuf);

	if ( argc == 1)
	{
		cout << "Please enter any file." << endl;
	}
	else
	{
		if ( argc == 2)
		{
			printInfo(argv[1], 1, 1, 1, 1);
		}
	}
}
