/**tail.cpp
 * Author: Sallie Torell
 * this will print from a specified place in a file to the screen.
 */

#include <string.h>
#include <stdio.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdlib.h>
#include <iostream>

using namespace std;

void printLines(const char *file, int start){


  FILE *f = fopen(file, "r");
  if(f == NULL) perror("Error");

  int lines = 0;
  char c;

  if(start != 0){
    while(!feof(f) && lines<start){
      c = fgetc(f);
      if(c == '\n'){
        lines++;
      }
    }//while
 }//if start !=0

  while(!feof(f) && c != '\0'){
    c = fgetc(f);
    putchar(c);

  }//while

}//printLines

int main(int argc, char* argv[]){

  if(argc == 1){
    cout<<"No text file"<<endl;
    return(EXIT_FAILURE);
  }//if =1
  else if(argc < 1){
    perror("Error");
  }//else if <1

  else if(argc == 2){
    printLines(argv[1], 0);
  }//else if =2

  else if(argc > 2){
    if(strcmp(argv[1], "-n") ==0){
      long int input = strtol(argv[2], &argv[2], 10);

      if(input != 3 && argc>3){

        for(int i=3; i<argc; i++){
          printLines(argv[i], input);
        }//for
      }//if input !=3

      else perror("Error");

    }//if argv[2] = -n

    else if(strcmp(argv[1], "-c") == 0){

      long int input = strtol(argv[2], &argv[2], 10);

      if(input !=3 && argc>3){
        for(int i=3; i<argc; i++){
          printLines(argv[i], input);
        }//for

      }//if input !=3

      else perror("Error");
    }//else if argv[2] = -c

  }//else if >2

  else perror("Error");

}//main


