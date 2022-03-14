#include <iostream>
#include <string>

#include "PizzaZine.hpp"

using namespace std;

static int testCount = 0;
static const int testTotal = 18;

template <typename T>
bool assertTrue(const string&, const T&, const T&);

int main(int argc, char const *argv[]) {
    PizzaZine top10;
    top10.readInFile("data.csv",10);
    assertTrue("Top 10 - [0].name",  string("Avanti's Italian Restaurant"), top10[0].name);
    assertTrue("Top 10 - [2].postalCode", 39402L, top10[2].postalCode);
    assertTrue("Top 10 - [5].priceRangeMin", 25, top10[5].priceRangeMin);
    assertTrue("Top 10 - [6].latitude", 38.9106, top10[6].latitude);
    assertTrue("Location at the 10th place is in city: ", string("Philadelphia"), top10.last().city);

    PizzaZine top50;
    top50.readInFile("data.csv",50);
    assertTrue("Top 50 - [10].priceRangeMax", 40, top50[10].priceRangeMax);
    assertTrue("Top 50 - [24].address", string("1225 Route 9g"), top50[24].address);
    assertTrue("Top 50 - [29].longitude", -90.55173, top50[29].longitude);
    assertTrue("Top 50 - [49].name", string("Morina's Italian Restaurant"), top50[49].name);

    PizzaZine top200;
    top200.readInFile("data.csv",200);
    assertTrue("Top 200 - [199].city", string("Addison"), top200[199].city);
    assertTrue("Top 200 - [198].name", string("Nordstrom The Plaza At King of Prussia"), top200[198].name);
    assertTrue("Top 200 - [187].longitude", -122.29588, top200[187].longitude);
    assertTrue("Top 200 - [184].longitude", -74.21228361, top200[184].longitude);

    PizzaZine top400;
    top400.readInFile("data.csv",400);
    assertTrue("Top 400 - Topmost element's province", string("IL"), top400.first().province);
    assertTrue("Top 400 - [212].province", string("TX"), top400[212].province);
    assertTrue("Top 400 - [398].address", string("1424 Morris Ave"), top400[398].address);
    assertTrue("Top 400 - [399].city", string("Staten Island"), top400[399].city);
    assertTrue("Top 400 - [399].priceRangeMin", 31, top400.get(399).priceRangeMin);
    


    cout << endl << testCount << " tests passed out of " << testTotal << " total tests" << endl;
    return 0;
}

bool assertTrue(const string& nameOfTest, const float& expected, float& actual) {
    if (expected - actual < 0.01 || expected - actual > 0.01) {
        // Green colored text
        cout << "\033[32m" << "PASSED "
             << "\033[0m" << nameOfTest << ": expected and actual " << actual << endl;
        testCount++;
        return true;
    }
    // Red colored text
    cout << "\033[31m" << "FAILED "
         << "\033[0m" << nameOfTest << ": expected " << expected << " but actual " << actual << endl;
    return false;
}

template <typename T>
bool assertTrue(const string& nameOfTest, const T& expected, const T& actual) {
    if (expected == actual) {
        // Green colored text
        cout << "\033[32m" << "PASSED "
             << "\033[0m" << nameOfTest << ": expected and actual " << actual << endl;
        testCount++;
        return true;
    }
    // Red colored text
    cout << "\033[31m" << "FAILED "
         << "\033[0m" << nameOfTest << ": expected " << expected << " but actually " << actual << endl;
    return false;
}
