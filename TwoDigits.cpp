#include <iostream>
#include "TwoDigits.h"


using namespace std;

TwoDigits::TwoDigits(){tens=0;units=0;} //Default constructor initate with zero value


/*A constructor that receives int as a parameter and creates the object that
corresponds to the unity digit and tens digit of the number obtained
*/
TwoDigits::TwoDigits(int num){tens=num/10;units=num%10;}


/*A constructor that accepts two char-type arguments. The first argument will
determine the tens digit the and the other the unity digit
*/
TwoDigits::TwoDigits(char t,char u){tens=t-48;units=u-48;}

//Destructor
TwoDigits::~TwoDigits(){
    cout<<"Free the resources of the object"<<endl;
}


/*A method that returns the value of the number as int*/
int TwoDigits:: value(){
    int number;
    number=(int)(tens)*10 + (int)(units);
    return number;
}

/*A method that updates the value of the number*/
void TwoDigits::update(int num){
    tens=num/10;     //based on ascii code
    units=num%10;    //based on ascii code
}


/*This method prints the number value.
 * If the user selects 0 as the tens digit, print out The unity digit only.*/
void TwoDigits::printValue(){

    if (tens==0)           //If a single-digit number,base on ascii code (48 ='0')
        cout<<(int)units<<endl;
    else
        cout<<(int)tens<<(int)units<<endl;
}




