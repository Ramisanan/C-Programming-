#include <stdio.h>
#include <stdlib.h>

int main(){
    int a;
    int b;
    int c;
    int d;
    int e;
    int f;
    int g;
    
    printf("\n Quantity of paratha: ");
    scanf("%d", &a);
    
    printf("\n Unit Price: ");
    scanf("%d", &b);
    
    printf("\n Quantity of vegetable: ");
    scanf("%d", &c);
    
    printf("\n Unit Price: ");
    scanf("%d", &d);
    
    printf("\n Quantity of Mineral Water: ");
    scanf("%d", &e);
    
    printf("\n Unit Price: ");
    scanf("%d", &f);
    
    printf("\n Number of People: ");
    scanf("%d", &g);
    
    float output = (a*b + c*d + e*f)/g;
    printf("\n Individual people will pay: ");
    printf( "%.2f", output);
    printf(" tk");
    
    return 0;
}
