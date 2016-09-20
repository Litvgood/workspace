#include <stdio.h>
#include <cs50.h>
#include <string.h>

int main(void)
{

    // recieving array of digits
    
    
    int c = 0;  // counter
    do
    {
    printf("Number: ");
    string a = GetString();
    int i = strlen(a);
    int arr[i]; // digit array
    int ver[i];  // symbol verification array
    for (int b = 0; b < i; b++)
        arr[b] = (int)a[b] - 48;
        
    // verification of recieved array, to be composed of digits only
    
    for (int b = 0; b < i; b++)
    {
        if (arr[b] >= 0 && arr[b] <= 9)
        {
            ver[b] = 1;
        }
        else
        {
            ver[b] = 0;
        }
    }
    for (int b = 0; b < i; b++)
        c = c + ver[b];
    }
    while (c < i);
    if (c < i)
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
            int n = 0; // couner
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
            for (int b = i - 1; b >= 0; b-=2)
                n = n + arr[b];
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
            printf("INVALID\n");
    }
     
    // PROFIT!     
    return 0;   
}
