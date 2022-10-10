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
    void floatToChar(float operation, char *str);
    void convertResultToDigit(float num, int size);
    int countChar(char *str);
    void digitsToChar(char *vet, Digit *digits, int size, bool dot, int pos);
    float charToFloat(char *str);

    void debug(Digit *);

    void showDigit(Digit *, int *, int *);

    // MEMORIA
    int memoCount;
    float memo;
    float memo1;
    float memo2;
    char memo1Char[MAX_DIGITS];
    char memo2Char[MAX_DIGITS];
    char memochar[MAX_DIGITS];

    Signal signal;

    // Operation memOp = NOOP;
    // int controlOp = 0;
    // float saveLastNum = 0;
    // Digit digitsMemory[MAX_DIGITS];
    // int digitsMemoryCount = 0;
    // bool dotMemory = false;
    // int dotControlMemory = -1;

    bool dotOne = false;
    bool dotSec = false;
    int dotControlFirstOp = -1;
    int dotControlSecondOp = -1;

    // BOOL
    bool decimal_separator = false;

public:
    CpuVitor();
    void receiveDigit(Digit);
    void receiveOperation(Operation);
    void receiveControl(Control);
    void setDisplay(Display &);
};