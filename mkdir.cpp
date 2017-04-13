
/**mkdir.cpp
 * Author: Sallie Torell
 * This creates a new directory with a name specified.
 */

#include <iostream>
#include <unistd.h>
#include <err.h>
#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <sysexits.h>
#include <sys/cdefs.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <libgen.h>
#include <stdlib.h>

using namespace std;

int main(int argc, char *argv[]){

  char *mode = NULL;
  int flag=0, exitval, success;
  mode_t omode, *set = (mode_t *)NULL;

  if(argc < 2){
    perror("No name specified");
  }//if

  else if(argc == 3 || argc ==4){

    for(int i=1; i!=3; i++){
      if(strcmp(argv[i],"-m")==0){
        mode = optarg;
      }//if -m
      else if(strcmp(argv[i],"-p")==0){
        flag = 1;
      }//else if -p
    }//for

  }//else if

else if(argc > 4){
    cout<<"Too many arguments"<<endl;
    return(EXIT_FAILURE);
  }//else if

  /*  if(mode == NULL){
    omode = S_IRWXU | S_IRWXG | S_IRWXO;
    }//if mode's null*/
  else{
    if((set = setmode(mode)) ==NULL){
      errx(1, "invalid file mode: %s", mode);
    }//if
    //    omode = getmode(set, S_IRWXU | S_IRWXG | S_IRWXO);
    free(set);
  }//else mode not null

  for(exitval = 0; *argv != NULL; argv++){
    success = 1;
    if(flag){
      int status = mkpath_np(*argv[2], omode);
      if(status && status != EEXIST){
        warn(status, "%s", *argv);
        success = 0;
      }//if status
    }//if flag
    else if(mkdir(*argv, omode) <0){
      if(errno == ENOTDIR || errno == ENOENT){
        warn("%s", dirname(*argv));
      }
      else{
        warn("%s", *argv);
      }
      success = 0;
    }//else if mkdir<0

    if(!success){
      exitval = 1;
    }

    if(success && mode != NULL && chmod(*argv, omode) == -1){
      warn("%s", *argv);
      exitval = 1;
    }
  }
  exit(exitval);

}//main
