#include <stdio.h>

int main(void)
{
    printf("Factorial of 10\n");
    int total = 1;
    for(int i = 1; i <= 10; i = i + 1) {
        total = total * i;
        printf("%d! =  %d \n", i, total);
    }
    return total;
}