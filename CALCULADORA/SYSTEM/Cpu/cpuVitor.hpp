#pragma once
#include "../Calculator/calculatorVitor.hpp"

class CpuVitor : public Cpu
{
private:
public:
    CpuVitor();
    virtual void receiveDigit(int) = 0;
    virtual void receiveOperator(int) = 0;
    virtual void setDisplay(Display &) = 0;
};
