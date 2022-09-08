#include "iostream"

class calculator
{
private:
    /* data */
public:
    calculator(/* args */);

    virtual void setDisplay();
    virtual void setKeyboard();
    virtual void setCpu();

    ~calculator();
};