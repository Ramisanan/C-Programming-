#include <unistd.h>
#include <stdio.h>

int main()
{
    int a = fork();
    int b = fork();
    int c = fork();
    
    int count = 0;
    
    if((getpid()%2) == 0){
        printf("my id is %d  \n", getpid());
        printf("Its even\n");
        printf("No clild will be created!!\n");
        
    }
    else{
        count++;
        printf("my id is %d  \n", getpid());
        printf("Its odd\n");
        printf("Process will create a clild!!\n");
        fork();
        
    }
    printf("Total created process: %d\n", count);
    return 0;
    
}
