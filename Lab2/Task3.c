#include <stdio.h>
#include <string.h>
#define N 30

int main(void){
    char pass[N];
    int p,j;

    printf("\nEnter a password: ");
    scanf("%s", pass);

    int i;
    int lower_case_count = 0;
    int upper_case_count = 0;
    int digit_count = 0;
    int special_char_count=0;
    p=strlen(pass);
    if(p< 8 || p >30)
    {
        printf("Sorry try again\n");
    }
    else
    {
        for (i = 0; i < 30; i++)
        {
            if (pass[i] >= 'a' && pass[i] <= 'z'){ lower_case_count++;}
            if (pass[i] >= 'A' && pass[i] <= 'Z') {upper_case_count++;}
            if (pass[i] >= '0' && pass[i] <= '9') {digit_count++;}
            if (pass[i]=='@' ||pass[i]=='#' || pass[i]=='$' || pass[i]=='%'){ special_char_count++;}
        }
        if (lower_case_count > 0 && upper_case_count > 0 && digit_count > 0 && special_char_count> 0)
        {
            printf("OK\n");
        }
        else
        {
            if (lower_case_count == 0)
            {
                printf("\nLowercase character missing");
            }
            if (upper_case_count == 0)
            {
                printf("\nUppercase character missing");
            }
            if (digit_count == 0)
            {
                printf("\nDigit missing");
            }
            if (special_char_count == 0)
            {
                printf("\nSpecial Char missing");
            }
        }
    }
}
