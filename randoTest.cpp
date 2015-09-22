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

TEST(RandoTest, isPrime)
{
    Rando rando;
    for( int n = -1; n < 101; n++)
    {
        switch( n )
        {   // cases are all prime numbers between 2 and 100. (Should be 25).
            case 2:
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
                ASSERT_TRUE( rando.isPrime( n ) );
                break;
            default: // negative or composite numbers are default.
                ASSERT_FALSE( rando.isPrime( n ) );
        }
    }
}
