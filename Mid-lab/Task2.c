#include <stdio.h>

int main() {
    int i;
    int number;
    int sum = 0;
    
    printf("Enter number: ");
    scanf("%d", &number);
    
    for(i = 1; i <= number/2; i++) {
        if(number % i == 0) {
            sum = sum + i;
        }
    }
    
    if(sum == number && number > 0) {
        printf("I am the perfect number");
    }
    else {
        printf("I am not the perfect number");
    }
    
    return 0;
}

