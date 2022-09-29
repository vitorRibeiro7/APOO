#include "keyboardVitor.hpp"

void KeyboardVitor::receiveDigit(Digit digit)
{
    this->cpu->receiveDigit(digit);
}
void KeyboardVitor::receiveOperation(Operation op)
{
    this->cpu->receiveOperation(op);
}
void KeyboardVitor::receiveControl(Control control)
{
    this->cpu->receiveControl(control);
}
void KeyboardVitor::addKey(Key &key)
{
    this->keys[this->keysCount++] = &key;
}

Key KeyboardVitor::findKey(char symbol)
{
    for (int i = 0; i < this->keysCount; i++)
    {
        if (this->keys[i]->getSymbol() == symbol)
        {
            return *this->keys[i];
        }
    }

    throw "KEY_NOT_FOUND";
}
void KeyboardVitor::setCpu(Cpu &cpu)
{
    this->cpu = &cpu;
}