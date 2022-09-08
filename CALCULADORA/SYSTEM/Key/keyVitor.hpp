#include "iostream"
#include "calculatorVitor.hpp"


class Key
{
private:
public:
    Key();

    virtual void press();
    virtual void setKeyboard(keyboard);

    ~Key();
};