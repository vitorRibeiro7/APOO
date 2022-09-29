#include "keyVitor.hpp"

KeyVitor::KeyVitor(char symbol, Digit digit)
{
    this->isDigit = true;
    this->symbol = symbol;
    this->digit = digit;
}
KeyVitor::KeyVitor(char symbol, Operation operation)
{
    this->isOperation = true;
    this->symbol = symbol;
    this->operation = operation;
}
KeyVitor::KeyVitor(char symbol, Control control)
{
    this->isControl = true;
    this->symbol = symbol;
    this->control = control;
}

void KeyVitor::press()
{
    if (this->isDigit)
        this->keyboard->receiveDigit(this->digit);
    if (this->isOperation)
        this->keyboard->receiveOperation(this->operation);
    if (this->isControl)
        this->keyboard->receiveControl(this->control);
}

void KeyVitor::setKeyboard(Keyboard &keyboard) { this->keyboard = &keyboard; }

char KeyVitor::getSymbol() { return this->symbol; }