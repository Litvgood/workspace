#include <stdio.h>

main(void)
{
    int i = 0;
    float a;
    printf("enter the amount: \n");
    scanf("%e", &a);
    a = a * 100;
    while(a - 25 >= 0)
       {
        a = ( a - 25 );
        i++;
        }
    while(a - 10 >= 0)
       {
          a = ( a - 10 );
          i++;
       }
    while(a - 5 >= 0)
       {
          a = ( a - 5 );
          i++;
       }
    while(a - 1 >= 0)
        {
          a = ( a - 1 );
          i++;
        }

    printf("%d\n",i);
}