#include <iostream>
#include "Fraction.h"
using namespace std;



Fraction::Fraction(){numerator=0;denominator=1;}   //Default constructor initate with zero value

/*A constructor that accepts two int-type arguments. The first argument will
determine the numerator and the other the denominator.
*/

Fraction::Fraction(int n,int d){
    if(d==0){numerator=0;denominator=1;}
    else {numerator=n;denominator=d;}
}

//Destructor
Fraction::~Fraction(){
    cout<<"Free the resources of the object"<<endl;
}

//A method that returns the number value as a float.
float Fraction:: value(){return (float)numerator/(float)denominator;}

//A method that updates the value of the numerator.
void  Fraction:: updateNumerator(int n){numerator=n;}

//A method that updates the value of the denominator.
void  Fraction:: updateDenominator(int d){
    if(d==0){numerator=0;denominator=1;}    //If the denominator is equal to zero, i.e. an invalid value
    else{denominator=d;}
}


//This method prints the number value.
void  Fraction:: printValue(){
    cout<<numerator<<"/"<<denominator;
}



