#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{

    // recieving array of digits
    
    printf("Number: ");
    string a = GetString();
    int n = 0; // counter
    int i = strlen(a);
    int arr[i]; // digit array
    int ver[i];  // symbol verification array
    int c = 0;  // counter
    for (int b = 0; b < i; b++)
        arr[b] = (int)a[b] - 48;
        
    // verification of recieved array, to be composed of digits only
    
    for (int b = 0; b < i; b++)
    {
//        printf("number %d and position in first array %d\n", arr[b], b);    // will be remover after testing
        if (arr[b] >= 0 && arr[b] <= 9)
        {
            ver[b] = 1;
//            printf("number %d and position in second array %d\n", ver[b], b);// will be remover after testing
        }
        else
        {
            ver[b] = 0;
//            printf("number %d and position in second array %d\n", ver[b], b);// will be remover after testing
        }
    }
    for (int b = 0; b < i; b++)
        c = c + ver[b];
//    printf("number of digits %d and i = %d\n", c, i);                                     // will be remover after testing
    
    if ( c < i)
        printf("INVALID INPUT\n");
    
    // card verification    
    
    else
    {
        if ((arr[0] * 10 + arr[1] == 34 && i == 15) ||
            (arr[0] * 10 + arr[1] == 37 && i == 15) ||
            (arr[0] == 4 && i == 13) ||
            (arr[0] == 4 && i == 16) ||
            (arr[0] * 10 + arr[1] >= 51 && arr[0] * 10 + arr[1] <= 55 && i == 16))
        {
        
    // calculation     
        
            for (int b = i - 2; b >= 0; b-=2)
            {
                if (arr[b] * 2 < 9)
                    n = n + arr[b] * 2;
                else
                {
                    int p = arr[b] * 2 - 10;
                    p = p + 1;
                    n = n + p;
                }
            }
//            printf("number %d\n", n);
            for (int b = i - 1; b >= 0; b-=2)
                n = n + arr[b];
//            printf("another number %d\n", n);
            int m = n / 10;
            m = m * 10;
            if (m != n)
                printf("INVALID\n");
                
    // card type determination                
                
            else if ((arr[0] * 10 + arr[1] == 34 && i == 15) ||
                     (arr[0] * 10 + arr[1] == 37 && i == 15))
                     printf("AMEX\n");
            else if ((arr[0] == 4 && i == 13) ||
                     (arr[0] == 4 && i == 16))
                     printf("VISA\n");
            else if (arr[0] * 10 + arr[1] >= 51 && arr[0] * 10 + arr[1] <= 55 && i == 16)
                    printf("MASTERCARD\n");
        }
        else
            printf("INVALID CARD NUMBER\n");
    }
     
    // PROFIT!     
       
}
