#pragma once
#include "iostream"
#include "calculatorVitor.hpp"

class DisplayVitor
{
private:
    /* data */
public:
    DisplayVitor(/* args */);

    virtual void addDigit(Digit);
    virtual void setSignal(Signal);
    virtual void clear();

    ~DisplayVitor();
};