#include <iostream>
#include <stdexcept>
#include "doctest.h"
#include "sources/MagicalContainer.hpp"
using namespace std;
using namespace ariel;

TEST_CASE("Adding numbers to magical container and checking sizes.")
{
    MagicalContainer cont;
    CHECK(cont.size()==0);
    cont.addElement(8);
    CHECK(cont.size()==1);
    cont.addElement(7);
    cont.addElement(2);
    cont.addElement(97);
    CHECK(cont.size()==4);
}
TEST_CASE("Adding numbers to prime magical container and checking sizes.")
{
    MagicalContainer cont;
    cont.addElement(8);
    cont.addElement(7);
    cont.addElement(2);
    cont.addElement(97);
    cont.addElement(49);
    MagicalContainer::PrimeIterator primeIt(cont);
    CHECK(cont.size()==5);
    int expectedVal[] = {7,2,97};
    int i =0;
    for (int *it = primeIt.begin(); it != primeIt.end(); it++)
    {
        CHECK((*it) == expectedVal[i++]);
    }
}
TEST_CASE("Adding numbers to SideCross magical container and checking sizes.")
{
    MagicalContainer cont;
    cont.addElement(8);
    cont.addElement(7);
    cont.addElement(2);
    cont.addElement(97);
    cont.addElement(49);
    MagicalContainer::SideCrossIterator sideIt(cont);
    CHECK(cont.size()==5);
    int expectedVal[] = {8,49,7,97,2};
    int i =0;
    for (int *it = sideIt.begin(); it != sideIt.end(); it++)
    {
        CHECK((*it) == expectedVal[i++]);
    }
}
TEST_CASE("Adding numbers to Ascending magical container and checking sizes.")
{
    MagicalContainer cont;
    cont.addElement(8);
    cont.addElement(7);
    cont.addElement(2);
    cont.addElement(97);
    cont.addElement(49);
    MagicalContainer::AscendingIterator asceIt(cont);
    CHECK(cont.size()==5);
    int expectedVal[] = {2,7,8,49,97};
    int i =0;
    for (int *it = asceIt.begin(); it != asceIt.end(); it++)
    {
        CHECK((*it) == expectedVal[i++]);
    }
}
TEST_CASE("Adding numbers to Ascending magical and prime container.")
{
    MagicalContainer cont;
    cont.addElement(8);
    cont.addElement(7);
    cont.addElement(2);
    cont.addElement(97);
    cont.addElement(49);
    MagicalContainer::AscendingIterator asceIt(cont);
    CHECK(cont.size()==5);
    int expectedValasce[] = {2,7,8,49,97};
    int expectedValprime[] = {2,7,97};
    int i =0;
    for (int *it = asceIt.begin(); it != asceIt.end(); it++)
    {
        CHECK((*it) == expectedValasce[i++]);
    }
    i=0;
    MagicalContainer::PrimeIterator primeIt(cont);
    for (int *it = primeIt.begin(); it != primeIt.end(); it++)
    {
        CHECK((*it) == expectedValprime[i++]);
    }
}
// TEST_CASE("Checking operators AscendingIterator.")
// {
//     MagicalContainer cont;
//     cont.addElement(8);
//     cont.addElement(7);
//     cont.addElement(2);
//     cont.addElement(97);
//     cont.addElement(49);
//     AscendingIterator asceIt(cont);
//     CHECK(asceIt.begin);
//     CHECK(97>2);
//     CHECK(8>2);
//     CHECK_FALSE(2>8);
// }
// TEST_CASE("Checking operators PrimeIterator.")
// {
//     MagicalContainer cont;
//     cont.addElement(8);
//     cont.addElement(7);
//     cont.addElement(2);
//     cont.addElement(97);
//     cont.addElement(49);
//     PrimeIterator primeIt(cont);
//     CHECK(2>7);
// }
// TEST_CASE("Checking operators PrimeIterator.")
// {
//     MagicalContainer cont;
//     cont.addElement(8);
//     cont.addElement(7);
//     cont.addElement(2);
//     cont.addElement(97);
//     cont.addElement(49);
//     SideCrossIterator sideCrIt(cont);
//     CHECK();
// }