#include <iostream>
#include "Menu.h"
#include "Fraction.h"
#include "String.h"
#include "TwoDigits.h"
using namespace std;


//This method prints the main menu of the program
void Menu:: mainMenu() {
    int c;
    do {
        cout << ("Choose The option you want:\n"
                 "Enter 1 for the TwoDigit menu\n"
                 "Enter 2 for the Fraction menu\n"
                 "Enter 3 for the String menu\n"
                 "Enter 4 to Quit the program\n");
        cin >> c;
        switch (c) {
            case 1:
                twoDigitsMenu();
                break;
            case 2:
                fractionMenu();
                break;
            case 3:
                stringMenu();
                break;
            case 4:
                cout << "Goodbye" << endl;
                exit(c=4);           //exit the program
            default:
                cout << "Bad choice! Please try again." << endl;
        }
    } while (c != 4);

}
//This method show the menu of TwoDigit and all the options he get
void  Menu::twoDigitsMenu(){
    int c;
    int num;
    char t,u;
    string input;
    do {
        cout<<"Please Enter a tens between 0-9:"<<endl;
        cin>>input;
        t=input[0];
    }while(t < '0' || t > '9'|| input.size()>1);    //check if the user type number between 0-9
    do {
        cout<<"Please Enter a units between 0-9:"<<endl;
        cin>>input;
        u=input[0];
    }while(u < '0' || u > '9'|| input.size()>1);    //check if the user type number between 0-9
    do{
        cout<<"Please Enter a number between 0-99:"<<endl;
        cin>>num;
    }while(num>99||num<0);                         //check if the user type number between 0-99
    {
        //initate two objects of TwoDigits
        TwoDigits Number1(t,u);
        TwoDigits Number2(num);
        do {
            cout << ("Choose The option you want:\n"
                     "Enter 1 for Updating The Number:\n"
                     "Enter 2 To  Sum The Objects \n"
                     "Enter 3 for Printing The objects\n"
                     "Enter 4 to Quit\n");
            cin >> c;
            switch (c) {
                case 1:
                    int new_num;
                    do {
                        cout << "Please Enter The updating number between 0-99:" << endl;
                        cin >> new_num;
                    } while (new_num > 99 || new_num < 0);     //check if the user type number between 0-99
                    Number1.update(new_num);
                    break;
                case 2:
                    cout<<"The sum of "<<Number1.value()<<"+"<<Number2.value()<<" is:"<<Number1.value()+Number2.value()<<endl;
                    break;
                case 3:
                    cout << "First two digit number:";
                    Number1.printValue();
                    cout << "Second two digit number:";
                    Number2.printValue();
                    break;
                case 4:
                    break;
                default:
                    cout << "Bad choice! Please try again." << endl;
            }
        } while (c != 4);
    }mainMenu();       //To return to main menu
}
//This method show the menu of Fraction and all the options he get
void Menu::fractionMenu() {
    int n, d,c;
    cout << "Please enter numerator:";
    cin >> n;
    cout << "Please enter denominator:";
    cin >> d;
    while (!d) {                                           //check if the user type 0 to be the denominator
        cout << "Denominator cant be zero please try again:";
        cin >> d;
    }
    {
        Fraction f(n, d);
        do {
            cout << ("Choose The option you want:\n"
                     "Enter 1 for Updating Numerator\n"
                     "Enter 2 for Updating Denominator\n"
                     "Enter 3 for Printing as Fraction\n"
                     "Enter 4 to Sum the Fractions\n"
                     "Enter 5 to Quit\n");
            cin >> c;
            switch (c) {
                case 1:
                    cout << "Please enter the new Numerator:";
                    cin >> n;
                    f.updateNumerator(n);
                    break;
                case 2:
                    cout << "Please enter the new Denominator:";
                    cin >> d;
                    f.updateDenominator(d);
                    break;
                case 3:
                    f.printValue();
                    cout<<endl;
                    break;
                case 4:
                    double new_num;
                    cout << "Please Enter a number:" << endl;
                    cin >> new_num;
                    cout <<"The sum of ";
                    f.printValue();
                    cout <<" and "<<new_num <<" is: "<< f.value() + new_num << endl;
                    break;
                case 5:
                    break;
                default:
                    cout << "Bad choice! Please try again."<<endl;
            }
        }while (c!=5);
    }mainMenu();     //To return to main menu
}


//This method show the menu of String and all the options he get
void Menu::stringMenu(){
    int i=0,c,index;
    string answer;
    char input[10];
    {
        String new_str;
        do {
            cout << ("Choose The option you want:\n"
                     "Enter 1 for Updating String\n"
                     "Enter 2 for Updating Chars in String\n"
                     "Enter 3 to  Change a char in String\n"
                     "Enter 4 to  Get a char from String\n"
                     "Enter 5 for Printing the String\n"
                     "Enter 6 for Printing the String in Lowercase\n"
                     "Enter 7 for Printing the String in Uppercase\n"
                     "Enter 8 to  Quit\n");
            cin >> c;
            switch (c) {
                case 1:
                    cout<<"Please Enter a string"<<endl;
                    cin>>input;
                    new_str.updateValue(input);
                    break;
                case 2:
                    new_str.setCharsByUser();
                    break;
                case 3:
                    char ch;
                    cout<<"Type an index in the string where you want to change the character:";
                    cin>>i;
                    if(i>8||i<0) {                         //check if the index is invalid
                        cout << "Invalid Input" << endl;
                    }
                    else
                    {
                        cout<<"Type the character you want to replace in the index you selected in the string:";
                        cin>>ch;
                        cout <<new_str.setCharAt(ch,i)<<endl;
                    }
                    break;
                case 4:
                    cout<<"Please Enter The index of the char you want"<<endl;
                    cin>>index;
                    if(index>=9){                             //check if the index is invalid
                        cout<<"The value in index "<< index <<" is: "<<"-"<<endl;
                    }
                    else{
                        cout<<"The value in index "<< index <<" is: "<< new_str.getCharAt(index)<<endl;
                    }
                    break;
                case 5:
                    new_str.printValue();
                    break;
                case 6:
                    new_str.printValue(false);
                    break;
                case 7:
                    new_str.printValue(true);
                    break;
                case 8:
                    break;
                default:
                    cout << "Bad choice! Please try again."<<endl;
            }
        }while (c!=8);
    }mainMenu();     //To return to main menu
}
