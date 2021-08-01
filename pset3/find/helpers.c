/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include "cs50.h"

#include "helpers.h"

/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    bool checker = false;
    int left = 0;
    int right = n-1;

    while(left<=right)
    {
        int middle = (left+right)/2;

        if (value < values[middle])
        {
            right = middle - 1;
        }

        else if (value > values[middle])
        {
            left = middle + 1;
        }

        else if (value == values[middle])
        {
            checker = true;
            return checker;
        }
    }

    return false;
}

/**
 * Sorts array of n values.
 */
void sort(int values[], int n)
{

    for (int i = 1; i < n; ++i)
    {
        int fixed = values[i];
        int j = i;

        while(fixed<values[j-1] && j>0)
        {
            values[j] = values[j-1];
            j--;
            values[j] = fixed;
        }
    }
    return;
}