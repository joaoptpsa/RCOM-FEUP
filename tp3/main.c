#include <stdio.h>
#include "app_layer.h"
#include "data_layer.h"
#include <fcntl.h>
#include <signal.h>
#include <stdlib.h>
#include <string.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <termios.h>
#include <unistd.h>

#define MODEMDEVICE "/dev/ttyS1"

int main(int argc, char** argv)
{
	int mode,fd;
  struct stat st;

    if ( (argc < 2) ||
  	     ((strcmp("/dev/ttyS0", argv[1])!=0) &&
  	      (strcmp("/dev/ttyS1", argv[1])!=0) )) {
      printf("Usage:\tnserial SerialPort\n\tex: nserial /dev/ttyS1\n");
      exit(1);
    }

    while (mode != 0 && mode != 1) {
        printf("Invalid mode!\nTry Again!\n");
      }

      // TRANSMITTER -> 0
      // RECEIVER -> 1


    if(!mode){

      char filename[50];
      printf("File: ");
      fgets(filename,50,stdin);
      filename[strlen(filename)-1] = '\0';

      // TRANSMITTER
      fd = connection(argv[1], mode);

      if(fd == -1)
        return -1;

        // send_data(filename);
    }
    else if(mode){
      // RECEIVER
      fd = connection(argv[1], mode);

      if(fd == -1)
        return -1;

        // receive_data();


    }


	// fi = open(argv[2],O_RDONLY);
	// fseek(fi, 0, SEEK_END); // seek to end of file
	// size = ftell(fi); // get current file pointer
	// fseek(f, 0, SEEK_SET); // seek back to beginning of file
  // fstat(fi, &st);
  // size = st.st_size;
  // atual = 0;
	// mode = 1;

    //
    llclose();
    return 0;
  }