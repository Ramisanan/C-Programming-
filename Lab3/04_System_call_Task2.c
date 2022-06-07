#include <unistd.h>
#include <stdio.h>

int main()
{
    int n1 = fork();
    int n2 = fork();
    
    if (n1 > 0 && n2 > 0) {
        printf("I am parent\n");
    }
    else if (n1 == 0 && n2 > 0)
    {
        printf("I am child\n");
    }
    else if (n1 > 0 && n2 == 0)
    {
        printf("I am grandchild\n");
    }
    return 0;
}

