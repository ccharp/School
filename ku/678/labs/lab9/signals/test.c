
#include <signal.h>
#include <stddef.h>
#include <stdio.h>
#include <sys/wait.h>

void suspend_current_process(int p);

main()
{
  int index; 
  struct sigaction action;
  sigset_t blockall;

  /*
   * Initialize handler for suspention of running process
   * SIGTSTP
   */

  /* Privacy Please: block all signals...don't want to be interrpted */
  sigfillset (&blockall);
  action.sa_mask = blockall;

  /* This function will handle a suspend (SIGTSTP) */
  action.sa_handler = suspend_current_process;

  /* No flags */
  action.sa_flags = 0;

  /* Install the handler */
  sigaction (SIGTSTP, &action, NULL);

  /* Now, let's start a loop, so we can test it out. */
  while(1){
	pause();
  }
  
  
}

/*
 * This is the signal hander that we installed
 */
void suspend_current_process(int p)
{
  printf ("No, I wont stop!\n");
}
