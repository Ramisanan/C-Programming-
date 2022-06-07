#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    int pid;
    int pid1;
    int pid2;
    
    pid = fork();
    if (pid == 0) {
        sleep(3);
        printf("Child process ID : %d \n", getpid());
    }
    
    else {
        pid1 = fork();
        if (pid1 == 0) {
            sleep(2);
            printf("Grand Child process ID : %d \n", getpid());
        }
        else {
            pid2 = fork();
            if (pid2 == 0) {
                printf("Grand Child process ID : %d \n", getpid());
            }
            
            else {
                pid2 = fork();
                if (pid2 == 0) {
                    printf("Grand Child process ID : %d \n", getpid());
                }
                else {
                    sleep(3);
                    printf("Parent process ID : %d\n", getpid());
                }
            }
        }
        
    }
    return 0;
}
