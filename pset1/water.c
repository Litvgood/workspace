#include <stdio.h>
#include <cs50.h>

int main(void)
{
    printf("minutes: ");
    int minutes = get_int();
    printf("bottles: %d\n", minutes * 12);
}
