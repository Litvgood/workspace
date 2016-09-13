#include <stdio.h>

int main(void)
{
    int minutes = 0;
    printf("minutes: ");
    scanf("%d", &minutes);
    while (minutes < 0 )
    {
        printf("Retry: ");
        scanf("%d", &minutes);
    }
    printf("bottles: %d\n", minutes * 12);
}
