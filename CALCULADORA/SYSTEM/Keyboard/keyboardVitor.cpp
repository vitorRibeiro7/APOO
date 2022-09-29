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
void KeyboardVitor::addKey(Key)
{
}

Key KeyboardVitor::findKey(char)
{
}
void KeyboardVitor::setCpu(Cpu &cpu)
{
    this->cpu = &cpu;
}