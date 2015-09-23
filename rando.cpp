#include "rando.h"
#include<cmath>
//#include <stdlib.h>

using std::sqrt;
using std::ceil;
using std::abs;

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
    //  Since order matters for division, I'll be making an
    // assumption that it is first|second, i.e.:
    // for x = first, there exists a k in Z such that k > 1 and
    // first == k * second.  Also, a bool isn't really sufficient to
    // enumerate the possible results of a test.  0/0 is undefined, so
    // neither true nor false really apply.

    if( second == 0 )
        return false;

    if( first == 0 )
        return true;

    if( first == second )
        return true;

    // Almost identical to checking for primes...
    for ( int k = 2; k <= floor(sqrt(first)); k++ )
    {
        if( first == k * second )
            return true;
    }
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
        //  Using this function here is slower than just calculating the
        // divisibility directly.  But is more demonstrative for this
        // assignment.
        if( isDivisibleBy( num, k ) )
        {
            return false;
        }
    }
    return true;
}

/**
 * Given two numbers, first and second, return the value of the one
 * that is closest to zero without actually being zero.
 **/
int Rando::nearestToZero(int a, int b)
{
    if( abs(a) == abs(b) )
        return a;

    if( a == 0 )
        return b;

    if( b == 0 )
        return a;

    return (abs(a) < abs(b)) ? a : b;
}
