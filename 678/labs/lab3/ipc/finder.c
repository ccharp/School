#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <strings.h>
#include <errno.h>
#include <sys/wait.h>

#define BSIZE 256
#define BUFF_LENGTH 5000

#define BASH_EXEC  "/bin/bash"
#define FIND_EXEC  "/bin/find"
#define XARGS_EXEC "/usr/bin/xargs"
#define GREP_EXEC  "/bin/grep"
#define SORT_EXEC  "/bin/sort"
#define HEAD_EXEC  "/usr/bin/head"

int main(int argc, char *argv[])
{
  int status;
  pid_t pid_1, pid_2, pid_3, pid_4;

  if (argc != 4) {
    printf("usage: finder DIR STR NUM_FILES\n");
    exit(0);
  }

  // pfd will not take the place of stdin  
  int pfds[2]; 
  int pfds1[2]; 
  int pfds2[2]; 

  pipe(pfds);
  pipe(pfds1);
  pipe(pfds2);

	
  pid_1 = fork();
  if (pid_1 == 0) {
    /* First Child */

	dup2(pfds[1], 1); 
	
	close(pfds[0]);
	close(pfds[1]);
	close(pfds1[0]);
	close(pfds1[1]);
	close(pfds2[0]);
	close(pfds2[1]);

    char cmdbuf[BSIZE];
    bzero(cmdbuf, BSIZE);
    sprintf(cmdbuf, "%s %s -name \'*\'.[ch]", FIND_EXEC, argv[1]);
    /* set up pipes */

	if (execl(BASH_EXEC, BASH_EXEC, "-c", cmdbuf, NULL) < 0) {
		
    	return EXIT_FAILURE;
	}
    exit(0);
  }

  pid_2 = fork();
  if (pid_2 == 0) {

    char cmdbuf[BSIZE];
    bzero(cmdbuf, BSIZE);
	
	dup2(pfds1[1], 1); 
    dup2(pfds[0], 0); 

	close(pfds[0]);
	close(pfds[1]);
	close(pfds1[0]);
	close(pfds1[1]);
	close(pfds2[0]);
	close(pfds2[1]);

    sprintf(cmdbuf, "xargs grep -c %s", argv[2]);
	
    execl(BASH_EXEC, BASH_EXEC, "-c", cmdbuf, NULL);
    
    exit(0);
  }

  pid_3 = fork();
  if (pid_3 == 0) {
    char cmdbuf[BSIZE];
    bzero(cmdbuf, BSIZE);
	
	dup2(pfds2[1], 1); 
    dup2(pfds1[0], 0); 

	close(pfds[0]);
	close(pfds[1]);
	close(pfds1[0]);
	close(pfds1[1]);
	close(pfds2[0]);
	close(pfds2[1]);

    sprintf(cmdbuf, "sort -t : +1.0 -2.0 --numeric --reverse");
	
    execl(BASH_EXEC, BASH_EXEC, "-c", cmdbuf, NULL);

	exit(0);
  }

  pid_4 = fork();
  if (pid_4 == 0) {
    char cmdbuf[BSIZE];
    bzero(cmdbuf, BSIZE);

    dup2(pfds2[0], 0); 

	close(pfds[0]);
	close(pfds[1]);
	close(pfds1[0]);
	close(pfds1[1]);
	close(pfds2[0]);
	close(pfds2[1]);

    sprintf(cmdbuf, "head --lines=%s", argv[3]);
	
    execl(BASH_EXEC, BASH_EXEC, "-c", cmdbuf, NULL);
    exit(0);
  }


	close(pfds[0]);
	close(pfds[1]);
	close(pfds1[0]);
	close(pfds1[1]);
	close(pfds2[0]);
	close(pfds2[1]);

  if ((waitpid(pid_1, &status, 0)) == -1) {
    fprintf(stderr, "Process 1 encountered an error. ERROR%d", errno);
    return EXIT_FAILURE;
  }
  if ((waitpid(pid_2, &status, 0)) == -1) {
    fprintf(stderr, "Process 2 encountered an error. ERROR%d", errno);
    return EXIT_FAILURE;
  }
  if ((waitpid(pid_3, &status, 0)) == -1) {
    fprintf(stderr, "Process 3 encountered an error. ERROR%d", errno);
    return EXIT_FAILURE;
  }
  if ((waitpid(pid_4, &status, 0)) == -1) {
    fprintf(stderr, "Process 4 encountered an error. ERROR%d", errno);
    return EXIT_FAILURE;
  }

  return 0;
}












