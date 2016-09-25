#include <stdio.h>
#include <cs50.h>
#include <math.h> 

int main(void)
{
    int i = 0;
    int a;
    do {
        printf("enter the amount: \n");
        float k = get_float();
        
        k = k * 100;
        a = round(k);
    }
    while (a < 1);
    
    while(a >= 25)
       {
            i++;
            a = ( a - 25 );
        }
    while(a >= 10)
       {
            i++;
            a = ( a - 10 );
       }
    while(a >= 5)
       {
            i++;
            a = ( a - 5 );
       }
    while(a >= 1)
        {
            i++;
            a = ( a - 1 );
        }

    printf("%d\n",i);
}
