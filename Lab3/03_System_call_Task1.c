#include <stdio.h>
#include <stdlib.h>

int main() {
    char sentence[1000];
    FILE *fptr;
    
    fptr = fopen("program.txt", "w");
    
    if (fptr == NULL) {
        printf("Error!");
        exit(1);
    }
    
    printf("Enter string( press '-1' to end!!)\n");
    scanf("%[^-1]s", sentence);
    
    {fprintf(fptr, "%s", sentence);
    }
    fclose(fptr);
    return 0;
}
