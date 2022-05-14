#include <iostream>
#include "String.h"
using namespace std;


//Default constructor initate array with zeros
String::String(){char str [10] =" ";}

/*A constructors that receives a char array and updates the class' static array.*/
String::String(char array[10]){
    int counter=0,i=0;
    while(array[i]!='\0'){          //Count the number of characters in the array
        counter++;
        i++;
    }
    for(i=0;i<counter;i++){         //Any array smaller than 10 characters will be copied
        str[i]=array[i];
    }
    for(i=counter;i<10;i++)
        str[i]='0';
    if(counter>=9){                 //If the array is longer than 10 characters
        str[9]='\0';                //We will copy the first 9 characters and in the tenth character we will write the null character.
    }
    else
        str[counter]='\0';          //At the end we will add the null character
}


//Destructor
String::~String(){
    cout<<"Free the resources of the object"<<endl;
}


/*Helper function To Count the number of characters in the array*/
int String::lenOfString(char array[]){
    int counter=0,i=0;
    while(array[i]!='\0'){
        counter++;
        i++;
    }
    return counter;
}

/*A method that updates the character array.*/
void String::updateValue(char array[]){
    int counter,i;
    counter=lenOfString(array);
    for(i=0;i<counter;i++){
        str[i]=array[i];
    }
    for(i=counter;i<10;i++)
        str[i]='0';
    if(counter>=9){                    //If the array is longer than 10 characters
        str[9]='\0';                   //We will copy the first 9 characters and in the tenth character we will write the null character.
    }
    else
        str[counter]='\0';            //At the end we will add the null character
}


/* Method that changes the value of a single character in an array. The first argument is
character and the other is index in which the character will be replaced.*/
bool  String::setCharAt(char c,int index){
    if (str[index]=='\0'){        //If we want to replace a character that is in a place where there is a NULL value
        str[index]=c;
        str[index+1]='\0';         //We would like to promote the NULL value in one
        return true;
    }
    else if(index>=9)              //If the index is greater than the null index then no replacement will be made.
    {
        return false;
    }
    else
    {
        str[index]=c;
        cout<<"Replace successfull"<<endl;
        return true;
    }
}

/*A method that updates the character array based on user input. In this method the user will type in all the values
 that need to be updated in the array, one after the other.*/
bool String::setCharsByUser(){
    char c,answer,temp[10];
    int i;
    bool keepChanging=true;

    for(i=0;str[i]!='\0';i++){         //Prepare for a situation where the index may be greater than the null index then no replacement will be performed
        temp[i]=str[i];
    }

    while(keepChanging) {
        cout << "Are you interested in updating a character in a string? Type y if so, otherwise type n" << endl;
        cin >> answer;
        if (answer == 'n' || answer == 'N') {     //if the user choose to not update a char in the string
            keepChanging = false;
            break;
        }
        cout << "Type in which index you want to change the character" << endl;
        cin >> i;
        if (i > 8 || i < 0)  // check if the index is valid
        {
            cout << "Invalid input" << endl;
            for(i=0;str[i]!='\0';i++){       //Return the string to be what it was in the beginning
                str[i]=temp[i];
            }
            cout<<"Failed To Update"<<endl;
            return false;
        }
        else
        {
            cout << "Type a character you want instead of the character in the string in the index you selected" << endl;
            cin >> c;
            if (str[i]=='\0') {      //If we want to replace a character that is in a place where there is a NULL value
                str[i] = c;
                str[i + 1] = '\0';     //We would like to promote the NULL value in one
            } else
                str[i] = c;
        }

    }
    cout<<"Update successfull"<<endl;
    return true;
}




/*A method that gets an index argument and returns the value of the character in this index.*/
char String::getCharAt(int index){
    int counter,i;
    counter=lenOfString(str);
    if(index>=counter)       //If the index is invalid or does not exist in the array
    {
        cout<<"Error"<<endl;
        return '-';
    }
    else
    {
        return str[index];
    }

}

/*This method prints the array value*/
void String::printValue(){
    for(int i=0;str[i]!='\0';i++){
        cout<<str[i];
    }
    cout<<endl;
}

/*Boolean parameter dependent printing.*/
void String::printValue(bool parameter){
    if(parameter)               //If the parameter is true, the array will be printed as an lowercase
    {
        for (int i = 0; str[i] != '\0'; i++) {
            cout << (char)toupper(str[i]);
        }
        cout<<endl;
    }
    else                        //If the parameter is flase, the array will be printed as an uppercase
    {
        for(int i=0;str[i]!='\0';i++){
            cout << (char)tolower(str[i]);
        }
        cout<<endl;
    }
}
