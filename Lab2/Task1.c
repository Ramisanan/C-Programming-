#include <stdio.h>
int main() {
    int a, b, res;

    printf("Enter two numerical inputs: ");
    scanf("%d %d", &a, &b);

    printf("Enter a operator (+, -, *): ");
    char op;
    scanf("%c", &op);
    op = getchar();

    if(a<b){
        res = a + b;
        printf("Addition is: %d", res);

    }
    else if(a>b){
        res = a - b;
        printf("Subtraction is: %d", res);

    }
    else{
        res = a * b;
        printf("Multiplication is: %d", res);

    }

return 0;
}
