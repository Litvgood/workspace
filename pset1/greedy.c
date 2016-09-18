#include <stdio.h>
#include <cs50.h>

int main(void)
{
    int i = 0;
    int a;
    printf("enter the amount: \n");
    do {
        float k = get_float();
        k = k * 100;
        a = k;
    }
    while (a < 1);
    
    while(a - 25 >= 0)
       {
            i++;
            a = ( a - 25 );
        }
    while(a - 10 >= 0)
       {
            i++;
            a = ( a - 10 );
       }
    while(a - 5 >= 0)
       {
            i++;
            a = ( a - 5 );
       }
    while(a - 1 >= 0)
        {
            i++;
            a = ( a - 1 );
        }

    printf("%i\n",i);
}
