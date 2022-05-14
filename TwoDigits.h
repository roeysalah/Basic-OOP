
#ifndef TWODIGITS_HPP
#define TWODIGITS_HPP


class TwoDigits {
private:
    //attributes
    char tens;
    char units;
public:
    TwoDigits();               //Default constructor
    TwoDigits(int num);        //constructor
    TwoDigits(char t,char u);  //constructor
    ~TwoDigits();              //Destructor

    //methods
    int value();
    void update(int num);
    void printValue();
};

#endif // TWODIGITS_HPP

