#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    char a[30], b, c,d;
    int x, y, z, flag=0, flagdot=0;

    printf("\nEnter mail id: ");
    gets(a);

    x=strlen(a);
    for(y = 0; y<x; y++){
        b=a[y];
        if(b == 's'){
            flag=1;
        }
        if(b=='x'){
            flagdot=1;
            z=y;
        }
    }
    if(flag==1 && flagdot==1 && (x-z)>2){
        printf("\nEmail address is okay");
    }
    else{
        printf("\nEmail address is outdated");
    }
    return 0;
}

