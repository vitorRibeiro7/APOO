#include "../Calculator/calculatorVitor.hpp"

class KeyVitor : public Key
{
private:
    Keyboard *keyboard;
    char symbol;
    Digit digit;
    Operation operation;
    Control control;
    bool isDigit = false;
    bool isOperation = false;
    bool isControl = false;

public:
    KeyVitor(char, Digit);
    KeyVitor(char, Operation);
    KeyVitor(char, Control);
    void press();
    void setKeyboard(Keyboard &);
    char getSymbol();
};