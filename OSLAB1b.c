// C program to demonstrate working of wait()

#include <stdio.h>
#include <unistd.h>
#include <sys/wait.h>

int main()
{
    if (fork() == 0)
    {
        // Child process
        printf("HC: hello from child\n");
        printf("Child is sleeping\n");

        for (int i = 0; i < 10; i++)
        {
            printf("i = %d\n", i);
            sleep(1);
        }
    }
    else
    {
        // Parent process
        printf("HP: hello from parent\n");

        wait(NULL);   // Parent waits for child to finish

        printf("PT: Parent terminated\n");
    }

    printf("Bye\n");
    return 0;
}
