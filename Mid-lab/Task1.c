#include <stdio.h>

float radius;
float volume;
char line_text[50];

const float PI = 3.1416;

int main() {
    printf("Input the radius: ");
    fgets(line_text, sizeof(line_text), stdin);
    scanf(line_text, "%f", &radius);

    volume = (4.0 / 3.0) * PI * (radius * radius * radius);
    printf("The volume of sphere is: %f.\n", volume);

    return(0);
}

