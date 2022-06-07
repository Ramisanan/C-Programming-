#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main()
{
    char sentence[1000];
    FILE *fptr;
    int pid;
    int pid1;
    int pid2;
    
    pid = fork();
    if (pid == 0) {
        sleep(3);
        printf("Child process ID : %d \n", getpid());
        fptr = fopen("CSE321mid.txt", "w");
    }
    else {
        sleep(3);
        printf("Parent process ID : %d\n", getpid());
        fptr = fopen("CSE321mid.txt", "r");
    }
return 0;
}









