#include "iostream"
#include "./displayVitor.hpp"
#include "./calculatorVitor.hpp"
#include "./cpuVitor.hpp"
#include "./keyVitor.hpp"
#include "./keyboardVitor.hpp"

enum Digit
{
    ZERO,
    ONE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE
};

enum Signal
{
    POSITIVE,
    NEGATIVE
};

class Calculator
{
private:
    /* data */
public:
    Calculator(/* args */);

    virtual void setDisplay();
    virtual void setKeyboard();
    virtual void setCpu();

    ~Calculator();
};