
/**date.cpp
 * Author: Sallie Torell
 * This takes a format needed by the user and prints out the current date and time
 */
#include <time.h>
#include <iostream>
using namespace std;

int main(int argc, char *argv[]){

  for(int i=1; i<argc; i++){
    char ostr[200];
    time_t t;
    struct tm *tmp;

    t = time(NULL);
    tmp = localtime(&t);
    if (tmp == NULL) {
      perror("localtime");
      exit(EXIT_FAILURE);
    }

    if (strftime(ostr, sizeof(ostr), argv[i], tmp) == 0) {
      fprintf(stderr, "strftime returned 0");
      exit(EXIT_FAILURE);
    }

    printf("%s \n", outstr);
  }
  exit(EXIT_SUCCESS);

}//main
