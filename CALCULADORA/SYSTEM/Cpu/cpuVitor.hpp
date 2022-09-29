#include <iostream>
#include "../Calculator/calculatorVitor.hpp"

#define MAX_DIGITS 8
class CpuVitor : public Cpu
{
private:
    // VARIAVEIS DE SISTEMA
    Display *display;
    Digit digitsOperand1[MAX_DIGITS];
    Digit digitsOperand2[MAX_DIGITS];
    int digitsOperand1Count = 0;
    int digitsOperand2Count = 0;
    Operation operation = NOOP;

    // FUNÇÕES AUXILIARES
    void operate();
    float convertDigitsToFloat(Digit *digits, int size);
    char floatToChar(float operation);
    float charToFloat(char *operation);

    // MEMORIA
    float memo;
    float memo1;
    float memo2;
    char memochar[MAX_DIGITS];

public:
    CpuVitor();
    void receiveDigit(Digit);
    void receiveOperation(Operation);
    void receiveControl(Control);
    void setDisplay(Display &);
};