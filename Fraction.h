
#include <iostream>
#ifndef FRACTION_HPP
#define FRACTION_HPP
using namespace std;
class Fraction {
private:
    //attributes
    int numerator;
    int denominator;

public:
    Fraction();                 //Default constructor
    Fraction(int n,int d);     //constructor
    ~Fraction();               //Destructor

    //methods
    float value ();
    void  updateNumerator(int n);
    void updateDenominator(int d);
    void printValue();
};

#endif // FRACTION_HPP
