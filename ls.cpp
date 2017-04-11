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

void longInformation(const char *dName)
{
	struct stat sb;
	stat(dName, &sb);

	                        if ( sb.st_mode & S_IFDIR)
                                {
                                        cout << "d";
                                }
                                else
                                {
                                        if ( sb.st_mode & S_IFIFO)
                                        {
                                                cout << "p";
                                        }
                                        else
                                        {
                                                cout << "-";
                                        }
                                }
                                if ( sb.st_mode & S_IRUSR)
                                {
                                        cout << "r";
                                }
                                else
                                {
                                        cout << "-";
                                }
                                if ( sb.st_mode & S_IWUSR)
                                {
                                        cout << "w";
                                }
                                else
                                {
                                        cout << "-";
                                }
                                if ( sb.st_mode & S_IXUSR)
                                {
                                        cout << "x";
                                }
                                else
                                {
                                        cout << "-";
                                }
                                if ( sb.st_mode & S_IRGRP)
                                {
                                        cout << "r";
                                }
                                else
                                {
                                        cout << "-";
                                }
                                if ( sb.st_mode & S_IWGRP)
                                {
                                        cout << "w";
                                }
                                else
                                {
                                        cout << "-";
                                }
                                if ( sb.st_mode & S_IXGRP)
                                {
                                        cout << "x";
                                }
                                else
                                {
                                        cout << "-";
                                }
                                if ( sb.st_mode & S_IROTH)
                                {
                                        cout << "r";
                                }
                                else
                                {
                                        cout << "-";
                                }
                                if ( sb.st_mode & S_IWOTH)
                                {
                                        cout << "w";
                                }
                                else
                                {
                                        cout << "-";
                                }
                                if (sb.st_mode & S_IXOTH)
                                {
                                        cout << "x";
                                }
                                else
                                {
                                        cout << "-";
                                }
				cout << ". ";
				cout << sb.st_nlink;
				cout << " ";
				//cout << (long)sb.st_uid;
				cout << getlogin();
				cout << " ";
				cout << getgrgid(sb.st_gid)->gr_name;
				cout << " ";
				cout << sb.st_size;
				cout << " ";
				
				char time[10] = "";
				strftime(time, 10, "%m", localtime( &sb.st_mtime));
				
				switch (atoi(time))
				{	
					case 1: cout << "January"; break;
					case 2: cout << "February"; break;
					case 3: cout << "March"; break;
					case 4:	cout << "April"; break;
					case 5: cout << "May"; break;
					case 6: cout << "June"; break;
					case 7: cout << "July"; break;
					case 8: cout << "August"; break;
					case 9: cout << "September"; break;
					case 10: cout << "October"; break;
					case 11: cout << "November"; break;
					case 12: cout << "December"; break;
				}
				
				cout << " ";
				strftime(time, 10, "%d", localtime( &sb.st_mtime));
				cout << time;
				cout << " ";
				strftime(time, 10, "%H:%M", localtime( &sb.st_mtime));
				cout << time;
				cout << " ";

}

void directorySearch(const char *dName, int a, int l, int r)
{
	DIR *dir;
        struct dirent *enter;
        if ((dir = opendir (dName)) != NULL)
        {
                while ((enter = readdir (dir)) != NULL)
                {

                        if ( enter->d_type!=DT_DIR)
                        {
                                //char path[PATH_MAX];
                                //const char * d_name = enter->d_name;

                                //snprintf (path, PATH_MAX, "%s/%s", dName, d_name);
                                if ( l > 0)
				{
					longInformation(enter->d_name);
					cout << " " << enter->d_name << endl;
				}
				else
				{
					cout << enter->d_name << endl;
				}
                        }
			if ( (strcmp(enter->d_name, ".") == 0 || strcmp(enter->d_name, "..") == 0) && a > 0 && r == 0)
			{
				if ( l > 0)
				{
					longInformation(enter->d_name);
					cout << " " << enter->d_name << endl;
				}
				else
				{
					cout << enter->d_name << endl;
				}
			}
                        if ( enter->d_type==DT_DIR && strcmp(enter->d_name, ".")!= 0 && strcmp(enter->d_name, "..") != 0)
                        {
                                //char path[PATH_MAX];
                                const char * d_name = enter->d_name;

                                //snprintf (path, PATH_MAX, "%s/%s", dName, d_name);
                                if ( l > 0)
				{
					longInformation(enter->d_name);
					cout << " " << enter->d_name << endl;
				}
				else
				{
					cout << d_name << endl;
				}
				if ( a > 0)
				{
					directorySearch(enter->d_name, 1, l, 1);
				}
                        }
                }
                closedir (dir);
        }
}

int main (int argc, char **argv)
{
	
	cout.setf(ios_base::unitbuf);
	
	const char *local = "../Allen-Torell-p3/";
	if ( argc == 1)
	{
		directorySearch(local, 0, 0, 0);
	}
	else
	{
		if ( strcmp(argv[1],"-a") == 0 )
		{
			if ( argc == 2)
			{
				directorySearch(local, 1, 0, 0);
			}
			else
			{
				for ( int i = 2; i < argc; i ++ )
				{
					directorySearch(argv[i], 1, 0, 0);
				}
			}
		}
		if ( strcmp(argv[1],"-l") == 0 )
		{
			if ( argc == 2)
			{
				directorySearch(local, 0, 1, 0);
			}
			else
			{
				for ( int i = 2; i < argc; i++ )
				{
					directorySearch(argv[i], 0, 1, 0);
				}
			}
		}
		if ( strcmp(argv[1],"-ls") == 0)
		{
			if ( argc == 2)
			{
				directorySearch(local, 1, 1, 0);
			}
			else
			{
				for ( int i = 2; i < argc; i ++ )
				{
					directorySearch(argv[i], 1, 1, 0);
				}
			}
		}
		else
		{
			for ( int i = 1; i < argc; i ++)
			{
				directorySearch(argv[i], 0, 0, 0);
			}
		}
	}

		//directorySearch(argv[1], 0);
}

