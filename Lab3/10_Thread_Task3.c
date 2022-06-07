#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <pthread.h>

int sum1= 0 ,sum2=0,sum3=0;
char string1[50],string2[50],string3[50];

int sumascii(char str[], int num)
{
    if (num < strlen(str))
    {
        return (str[num] + sumascii(str, num + 1));
    }
    
    return 0;
}


void * ThreadFun1(void * str1){
    
    sum1 = sumascii(str1, 0);
    printf("The sum of all ascii values in '%s' is %d.\n", str1, sum1);
    pthread_exit(NULL);
    
}

void * ThreadFun2(void * str2){
    sum2 = sumascii(str2, 0);
    printf("The sum of all ascii values in '%s' is %d.\n", str2, sum2);
    pthread_exit(NULL);
}

void * ThreadFun3(void * str3){
    sum3 = sumascii(str3, 0);
    printf("The sum of all ascii values in '%s' is %d.\n", str3, sum3);
    pthread_exit(NULL);
}


int main()
{
    char str1[30],str2[30],str3[30];
    
    printf("Enter first string: ");
    scanf("%s", str1);
    printf("Enter second string: ");
    scanf("%s", str2);
    printf("Enter third string: ");
    scanf("%s", str3);
    
    pthread_t tid1;
    pthread_t tid2;
    pthread_t tid3;
    
    pthread_create(&tid1, NULL, ThreadFun1, (void *)str1);
    pthread_create(&tid2, NULL, ThreadFun2, (void *)str2);
    pthread_create(&tid3, NULL, ThreadFun3, (void *)str3);
    
    pthread_exit(NULL);
    
    
    return 0;
}
