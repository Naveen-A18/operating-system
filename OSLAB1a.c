#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    pid_t child_pid;
    int status;

    /* Create a child process */
    child_pid = fork();

    if (child_pid < 0)
    {
        /* Fork failed */
        perror("Fork failed");
        exit(1);
    }
    else if (child_pid == 0)
    {
        /* Child process */
        printf("Child process is running\n");
        printf("Child PID: %d\n", getpid());

        /* Replace child process with a new program */
        execlp("/bin/ls", "ls", "-l", NULL);

        /* This code runs only if exec fails */
        perror("Exec failed");
        exit(1);
    }
    else
    {
        /* Parent process */
        printf("Parent process is running\n");
        printf("Parent PID: %d\n", getpid());
        printf("Created Child PID: %d\n", child_pid);

        /* Wait for child to finish */
        wait(&status);

        if (WIFEXITED(status))
        {
            printf("Child exited normally with status %d\n",
                   WEXITSTATUS(status));
        }
        else
        {
            printf("Child did not exit normally\n");
        }
    }

    return 0;
}
