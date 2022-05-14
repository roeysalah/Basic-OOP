
#ifndef STRING_HPP
#define STRING_HPP

class String {
private:
    //attribute
    char str[10];
    //helper method
    int  lenOfString(char array[]);

public:
    String();                       //Default constructor
    String(char array[10]);         //constructor
    ~String();                      //Destructor

    //methods
    void updateValue(char array[]);
    bool setCharAt(char c,int index);
    bool setCharsByUser();          // later to come back
    char getCharAt(int index);
    void printValue();
    void printValue(bool parameter);






};




#endif // STRING_HPP

