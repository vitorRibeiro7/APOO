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

    void operate(Operation op);
    Digit intToDigit(int num);
    void intToChar(char *memo, int num);
    int digitsToInt(Digit *digits);
    int digitsToInt2(Digit *digits);
    char digitsToChar(Digit);

    void resetDigits(Digit *digits);
    void insertDigitsOnDisplay(Digit *digits);

    int memo;
    int memo1;
    int memo2;

public:
    CpuVitor();
    void receiveDigit(Digit);
    void receiveOperation(Operation);
    void receiveControl(Control);
    void setDisplay(Display &);
};