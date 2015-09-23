/**
 * Unit Tests for Rando Test
 **/

#include <gtest/gtest.h>
#include "rando.h"

/*  
    FUNCTIONS WE NEED TO TEST:

    bool shouldWorry(bool,bool,bool);
    bool isDivisbleBy(int,int);
    bool isPrime(int);
    int nearestToZero(int,int);
    */

class RandoTest : public ::testing::Test
{
    protected:
        RandoTest(){} //constructor runs before each test
        virtual ~RandoTest(){} //destructor cleans up after tests
        virtual void SetUp(){} //sets up before each test (after constructor)
        virtual void TearDown(){} //clean up after each test, (before destructor) 
};

TEST(RandoTest, allChildrenSmile)
{
    Rando rando;
    ASSERT_TRUE( rando.shouldWorry(true,true,true) );
}

TEST(RandoTest, isDivisibleBy)
{
    Rando rando;
    
    ASSERT_FALSE( rando.isDivisibleBy( 0, 0 ) );

    for( int a = -3; a < 4; a++ )
    {
        if ( a == 0 )  // Skip zero, already checked.
        {
            a++;
        }
        ASSERT_TRUE(  rando.isDivisibleBy( 0, a ) );
        ASSERT_FALSE( rando.isDivisibleBy( a, 0 ) );
    }
    for( int a = 1; a < 5; a++ )
    {
        ASSERT_TRUE( rando.isDivisibleBy( 5 * a, 5 ) );
    }
    for( int a = 3; a < 8; a++ )
    {
        ASSERT_FALSE( rando.isDivisibleBy( 2, a ) );
    }
}

TEST(RandoTest, isPrime)
{
    Rando rando;
    for( int n = 100; n >= -1; n--)
    {
        switch( n )
        {
            default: // negative or composite numbers are default.
                ASSERT_FALSE( rando.isPrime( n ) );
                break;
                // cases are all prime numbers between 2 and 100. (Should be 25).
            case 2:  // Fallthroughts...
            case 3:
            case 5:
            case 7:
            case 11:
            case 13:
            case 17:
            case 19:
            case 23:
            case 29:
            case 31:
            case 37:
            case 41:
            case 43:
            case 47:
            case 53:
            case 59:
            case 61:
            case 67:
            case 71:
            case 73:
            case 79:
            case 83:
            case 89:
            case 97:
                // x == true used for clarity in gtest output.
                ASSERT_TRUE( rando.isPrime( n ) ); 
        }
    }
}

TEST(RandoTest, nearestToZero)
{
    Rando rando;
    for( int a = 2; a < 5; a++ )
    {
        ASSERT_TRUE( rando.nearestToZero( a, 1 ) == 1 );
    }
    for( int a = 2; a < 5; a++ )
    {
        ASSERT_TRUE( rando.nearestToZero( a, -1 ) == -1 );
    }
    for( int a = 1; a < 5; a++ )
    {
        ASSERT_TRUE( rando.nearestToZero( a, 30 ) == a );
    } 
    for( int a = 1; a < 5; a++ )
    {
        ASSERT_TRUE( rando.nearestToZero( a, -30 ) == a );
    }
    for( int a = 2; a < 5; a++ )
    {
        ASSERT_TRUE( rando.nearestToZero( 1, a ) == 1 );
    }
    for( int a = 2; a < 5; a++ )
    {
        ASSERT_TRUE( rando.nearestToZero( -1, a ) == -1 );
    }
    for( int a = 2; a < 5; a++ )
    {
        ASSERT_TRUE( rando.nearestToZero( 30, a ) == a );
    } 
    for( int a = 1; a < 5; a++ )
    {
        ASSERT_TRUE( rando.nearestToZero( -30, a ) == a );
    }
    for( int a = 1, b = -1; a > -5; a--, b++ )
    {
        ASSERT_TRUE( rando.nearestToZero( a, b ) == a );
        ASSERT_TRUE( rando.nearestToZero( b, a ) == b );
    }

    ASSERT_TRUE( rando.nearestToZero( 0, 0 ) == 0 );

    for( int a = 1; a < 5; a++ )
    {
        ASSERT_TRUE( rando.nearestToZero( 0, a ) != 0 );
        ASSERT_TRUE( rando.nearestToZero( a, 0 ) != 0 );
    }
}
