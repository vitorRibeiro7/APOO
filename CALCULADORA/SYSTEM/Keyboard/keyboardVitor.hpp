#pragma once
#include <iostream>
#include "../Calculator/calculatorVitor.hpp"

#define MAX_KEYS 23

class KeyboardVitor : public Keyboard
{
private:
    Cpu *cpu;
    Key *keys[MAX_KEYS];
    unsigned char keysCount = 0;

public:
    void receiveDigit(Digit);
    void receiveOperation(Operation);
    void receiveControl(Control);
    void addKey(Key &);
    Key &findKey(char);
    void setCpu(Cpu &);
};