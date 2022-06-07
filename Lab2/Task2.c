#include<stdio.h>

int main(){
    int j = 0, i=0;
    char str[30], str2[40];
    printf("\n\t Enter a string : ");
    gets(str);
    while(str[i] != '\0'){
        if(!(str[i] == ' ' && str[i+1] == ' ')){
            str2[j] = str[i];
            j++;

        }
        i++;
    }
    str2[j] = '\0';
    printf("%s", str2);

}
