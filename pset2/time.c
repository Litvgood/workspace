#include<stdio.h>
#include<time.h>


time_t time(time_t *t);

int main(void)
{
    time_t t;
    
    t = time(NULL);
    
    printf("%ld\n", t);

    return 0;
    
}
