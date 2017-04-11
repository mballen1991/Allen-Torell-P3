#include<string.h>
#include<stdio.h>
#include<fcntl.h>
#include<unistd.h>
#include<stdlib.h>
#include<iostream>

using namespace std;

void printLines( const char * file, int count)
{
	
	int lines = 0;
	
	FILE *f = fopen(file, "r"); //sets output to be unbuffered
	if ( f == NULL)
	{
		perror("Error");
	}
	char c;

	while(!feof(f) && lines < count)
	{
		c = fgetc(f);
		putchar(c);
		if(c == '\n')
		{
			lines++;
		}
	}
	fclose(f);
	//cout << endl;
}

int main (int argc, char **argv)
{
	cout.setf(ios_base::unitbuf);

        long int input;

	if ( argc == 1)
	{
		cout << "Please enter any text file." << endl;
	}
	else
	{
		if ( argc < 1 )
		{
			cout << "error" << endl;
		}
		else
		{
			if ( argc == 2 )
			{
				 printLines(argv[1], 20);
			}
			else
			{
				if ( argc > 2 )
				{
					if ( strcmp(argv[1], "-n") == 0)
					{
						input = strtol(argv[2],&argv[2],10);
						if ( input != 0 && argc > 3)
						{
							for ( int i = 3; i < argc; i++)
							{
								printLines(argv[i], input);
							}
						}
						else
						{
							cout << "Error: 1" << endl;
						}
					}
					else
					{
						cout << "Error: 2" << endl;
					}
				}
				else
				{
					cout << "Error: 3" << endl;
				}
			}
		}
	}
}
