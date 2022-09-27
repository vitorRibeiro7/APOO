#include <iostream>
#include "../Calculator/calculatorVitor.hpp"

#define MAX_DIGITS 8
class CpuVitor : public Cpu
{
private:
    Display *display;
    Digit digitsOperand1[MAX_DIGITS];
    Digit digitsOperand2[MAX_DIGITS];
    char digitsOperand1Count = 0;
    char digitsOperand2Count = 0;
    Operation operation = NOOP;

    void operate();
    Digit intToDigit(int num);
    void intToChar(char *memo, int num);
    float convertDigitsToFloat(Digit *digits, char size);
    Digit convertFloatToDigits(int num);
    char digitsToChar(Digit);

    void resetDigits(Digit *digits);
    void insertDigitsOnDisplay(Digit *digits);

    float memo;
    float memo1;
    float memo2;

public:
    CpuVitor();
    void receiveDigit(Digit);
    void receiveOperation(Operation);
    void receiveControl(Control);
    void setDisplay(Display &);
};