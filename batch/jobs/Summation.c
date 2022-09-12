#include <stdio.h>

int main(void)
{
    printf("Summing Numbers: 0-10\n------------------\n");
    int sum = 0;
    for(int i = 0; i <= 10; i = i + 1) {
        sum = sum + i;
        printf("Current Sum: %d \n", sum);
    }
    return sum;
}