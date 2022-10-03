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
    int resultCount = 0;
    Operation operation = NOOP;

    // FUNÇÕES AUXILIARES
    void operate();
    float convertDigitsToFloat(Digit *digits, int size);
    void floatToChar(float operation);
    float charToFloat(char *operation);
    void convertResultToDigit(float num, int size);
    int countChar(char *str);
    void digitsToChar(Digit *digits, char *vet, int size, bool dot, int pos);
    float charToFloat(char str);

    // MEMORIA
    int memoCount;
    float memo;
    float memo1;
    float memo2;
    char memo1Char[MAX_DIGITS];
    char memo2Char[MAX_DIGITS];
    float memory;

    char memochar[MAX_DIGITS];

    Signal signal;

    bool dotOne = false;
    bool dotSec = false;
    int dotControlFirstOp = 0;
    int dotControlSecondOp = 0;

    // BOOL
    bool decimal_separator = false;

public:
    CpuVitor();
    void receiveDigit(Digit);
    void receiveOperation(Operation);
    void receiveControl(Control);
    void setDisplay(Display &);
};