#include<stdlib.h>
#include<unistd.h>
#include<stdio.h>
#include<signal.h>
#include<time.h>

int main()
{
    sigset_t new_set;

    // sigemptyset(&new_set);
    // sigaddset(&new_set, SIGINT);
    if (sigprocmask(SIG_SETMASK, &new_set, NULL) == 0) {
		// sigprocmask(SIG_SETMASK, NULL, &old_set);
      if (sigismember(&new_set, SIGINT) == 1 ) {
        printf("SIGINT exist\n");
        sigdelset(&new_set, SIGINT);
      } else if (sigismember(&new_set, SIGINT) == 0) {
        printf("SIGINT does not exist\n");
        sigaddset(&new_set, SIGINT);
      }
    } 

    sigprocmask(SIG_SETMASK, &new_set, NULL);
    while(1);

    return 0;
}