#include "iostream"
#include "calculatorVitor.hpp"

class Keyboard
{
private:
    /* data */
public:
    Keyboard(/* args */);

    virtual key findKey(char);
    virtual void recieveDigit(int);
    virtual void setCpu(cpu);

    ~Keyboard();
};
