#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <signal.h>

void sig_handler(int signum)
{
    printf("Signal catched SIGINT : %d\n", signum);
}

void sig_handler2(int signum)
{
    printf("Signal catched SIGUSR1 : %d\n", signum);
}

void sig_handler3(int signum)
{
    printf("Signal catched SIGUSR2 : %d\n", signum);
}

int main()
{
    if (signal(SIGINT, sig_handler) == SIG_ERR) {
		fprintf(stderr, "Cannot handle SIGINT\n");
		exit(EXIT_FAILURE);
	}

    signal(SIGUSR1, sig_handler2);
    signal(SIGUSR2, sig_handler3);

    printf("process ID: %d\n", getpid());
    while(1)
    {
        printf("Hello!\n");
        sleep(2);
    }

    return 0;
}