#pragma once
#include "../Calculator/calculatorVitor.hpp"

class KeyboardVitor : public Keyboard
{
private:
    Cpu *cpu;

public:
    void receiveDigit(Digit);
    void receiveOperation(Operation);
    void receiveControl(Control);
    void addKey(Key) = 0;
    Key findKey(char);
    void setCpu(Cpu &);
};