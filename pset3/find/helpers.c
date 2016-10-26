/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
      
#include <cs50.h>

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    int low, high, middle;
    low = 0;
    high = n - 1;
    
    if ( (values[0] == value) || (values[n-1] == value) )
    {
        return 1;
    }
    
    while ( low <= high )
    {
        middle = ( low + high ) / 2;
        if ( value < values[middle] )
            high = middle - 1;
        else if ( value > values[middle] )
            low = middle + 1;
        else 
            return 1;
    }
    return 0;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{
    int e, //Element
        l; //Location
 
    for ( int i = 1; i < n; i++ )
    {
        e = values[i];
        l = i - 1;
        while( l >= 0 && values[l] > e )
        {
            values[l+1] = values[l];
            l = l - 1;
        }
        values[l+1] = e;
    }
}
