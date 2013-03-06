#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <strings.h>
#include <errno.h>
#include <sys/wait.h>

#define BSIZE 256

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
  pipe(pfds);
  dup2(pfds[1], 1);
  dup2(pfds[0], 0); 
  //find $1 name '*'.[ch] | xargs grep -c $2 | sort -t : +1.0 -2.0 --numeric --reverse | head --lines=$3
	
  pid_1 = fork();
  if (pid_1 == 0) {
    /* First Child */

	fprintf(stderr, "In child\n");
    char cmdbuf[BSIZE];
    bzero(cmdbuf, BSIZE);
    sprintf(cmdbuf, "%s %s -name \'*\'.[ch]", FIND_EXEC, argv[0]);
    /* set up pipes */


	if (execl(BASH_EXEC, BASH_EXEC, "-c", cmdbuf, NULL) < 0) {
		
    	fprintf(stderr, "\nError executing find. ERROR#%d\n", errno);
    	return EXIT_FAILURE;
	}
    exit(0);
  }

  pid_2 = fork();
  if (pid_2 == 0) {
	fprintf(stderr, "In the next child\n");

    char cmdbuf[BSIZE];
    bzero(cmdbuf, BSIZE);
    sprintf(cmdbuf, "%s %s -c %s", XARGS_EXEC, GREP_EXEC, argv[1]);
	
	printf("cmdbuf: %s\n", cmdbuf);

	char readbuf[1000];
	bzero(readbuf, 1000); 

    //size_t length = read(pfds[0], readbuf, 1000);
	printf("Buffer: %s\n", readbuf);
	fflush(stdout);

//    execl(BASH_EXEC, BASH_EXEC, "-c", cmdbuf, NULL);
    
    exit(0);
  }

  pid_3 = fork();
  if (pid_3 == 0) {
    /* Third Child */
    exit(0);
  }

  pid_4 = fork();
  if (pid_4 == 0) {
    /* Fourth Child */
    exit(0);
  }

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












