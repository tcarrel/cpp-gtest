#include "rando.h"
#include<cmath>
//#include <stdlib.h>

using std::sqrt;
using std::ceil;

/**
 * Worry if only one child is smiling or if all children are smiling
 **/
bool Rando::shouldWorry(bool childASmile, bool childBSmile, bool childCSmile)
{
    if( childASmile && childBSmile && childCSmile )
        return true;
    else if( childASmile ^ childBSmile ^ childCSmile )
        return true;
    else
        return false;
}
/**
 * Determines if first or second are evenly divisible by the other.
 **/
bool Rando::isDivisibleBy(int first, int second)
{
    return false;
}

/**
 * Given a number, num, says whether or not that number is prime
 * (that is, only evenly divisible by itself and 1. For the sake
 * of this function, do NOT consider 0 prime)
 **/
bool Rando::isPrime(int num)
{
    double check = (double) num;

    // Take care of the base cases first.
    if( check <= 1 ) 
        return false;

    if( check == 2 || check == 3 )
        return true;

    //  '2' was already checked, so all even checkbers can
    // now be rejected out-of-hand.
    if( !((int) check % 2) ) 
        return false;

    double highest = floor( sqrt( check ) ); // Calculate once.

    for( double k = 3.0; k <= highest; k += 2.0 ) //Even checks can be skipped
    {
        double divd = ( (double) check) / k;
        int    divi = ( (double) check) / k;

        if( divd == divi )
            return false;
    }
    return true;
}

/**
 * Given two numbers, first and second, return the value of the one
 * that is closest to zero without actually being zero.
 **/
int Rando::nearestToZero(int a, int b)
{
    return 0;
}
