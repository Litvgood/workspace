#include <stdio.h>

int main(void)
{
    int i, j, H;
    printf("Height: ");
    scanf("%d", &H);
    while ( (H < 0) || (H > 23))
    {
        printf("Retry: ");
        scanf("%d", &H);
    }
    for(i = 0; i < H; ++i){
        for(j = 0; j < H; ++j){
            if(j < H - 1 - i)
                printf(" ");
            else
                printf("#");
        }
        printf("#\n");
    }
}