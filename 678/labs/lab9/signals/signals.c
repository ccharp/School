#include <stdio.h>     /* standard I/O functions                         */
#include <stdlib.h>    /* exit                                           */
#include <unistd.h>    /* standard unix functions, like getpid()         */
#include <signal.h>    /* signal name macros, and the signal() prototype */
#include <string.h>

/* first, define the Ctrl-C counter, initialize it with zero. */
int ctrl_c_count = 0;
int got_response = 0;

int alarm_resolved = 0;
#define CTRL_C_THRESHOLD  5 

/* the Ctrl-C signal handler */
void catch_int(int sig_num)
{
	/* increase count, and check if threshold was reached */
	ctrl_c_count++;
	if (ctrl_c_count >= CTRL_C_THRESHOLD) {
		char answer[30];
		
		alarm(5);
		alarm_resolved = 0;

		/* prompt the user to tell us if to really
		 * exit or not */
		printf("\nReally exit? [Y/n]: ");
		fflush(stdout);
		fgets(answer, sizeof(answer), stdin);
		
		if (answer[0] == 'n' || answer[0] == 'N') {
			printf("\nContinuing\n");
			fflush(stdout);
			/* 
			 * Reset Ctrl-C counter
			 */
			ctrl_c_count = 0;
		}
		else {
			printf("\nExiting...\n");
			fflush(stdout);
			exit(0);
		}
	}
}

/* the Ctrl-Z signal handler */
void catch_tstp(int sig_num)
{
	/* print the current Ctrl-C counter */
	printf("\n\nSo far, '%d' Ctrl-C presses were counted\n\n", ctrl_c_count);
	fflush(stdout);
}

void catch_alrm(int sig_num) 
{
	if(!alarm_resolved) {
		printf("\nAlarm not resolved in time. Exiting...\n");
		fflush(stdout);
		exit(0);
	}
}

void signalHandler(int sig_num)
{
	switch(sig_num) {
		case SIGINT:
			catch_int(SIGINT);
			break;
		case SIGTSTP:
			catch_tstp(SIGTSTP);	
			break;
		default: 
			printf("\n No way of handling signal %i\n", sig_num);
			fflush(stdout);
	}

	if(!alarm_resolved) {
		alarm_resolved = 1;	
	}
}

int main(int argc, char* argv[])
{
	struct sigaction sa;
	sigset_t mask_set;  /* used to set a signal masking set. */

	/* setup mask_set */
	sigaddset(&mask_set, SIGINT);
	sigaddset(&mask_set, SIGTSTP);
	sa.sa_mask = mask_set; 

	/* set signal handlers */
	sa.sa_handler = signalHandler;
	sigaction(SIGINT, &sa, NULL);
	sigaction(SIGTSTP, &sa, NULL);

	signal(SIGALRM, catch_alrm);

	while(1) {
		pause();	
	}
	return 0;
}

















