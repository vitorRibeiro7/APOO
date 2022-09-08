#include "iostream"

class keyboard
{
private:
    /* data */
public:
    keyboard(/* args */);

    virtual key findKey(char);
    virtual void recieveDigit(int);
    virtual void setCpu(cpu);

    ~keyboard();
};
