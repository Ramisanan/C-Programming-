#include <stdio.h>

void isPalindrome(char* string) {
    char *ptr, *rev;

    ptr = string;

    while (*ptr != '\0') {
        ++ptr;
    }
    --ptr;

    for (rev = string; ptr >= rev;) {
        if (*ptr == *rev) {
            --ptr;
            rev++;
        }
        else
            break;
    }

    if (rev > ptr)
        printf("Palindrome");
    else
        printf("Not Palindrome");
}

int main() {
    char str[1000];
    printf("Input: ");
    gets(str);
    isPalindrome(str);

    return 0;
}



