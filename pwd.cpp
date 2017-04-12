#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <iostream>

using namespace std;

int main( void )
{
    	char* c;
    	char buffer[PATH_MAX + 1];

    	c = getcwd( buffer, PATH_MAX + 1 );

	cout << c << endl;
}
