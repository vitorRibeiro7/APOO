#pragma once
#include "../Calculator/calculatorVitor.hpp"
#include "../Console/consoleVitor.hpp"

#define MAX_DIGITS 8

class DisplayVitor : public Display
{
private:
    Console console;
    Digit digits[MAX_DIGITS];
    unsigned char digitsCount = 0;
    Signal signal = POSITIVE;
    void refresh();
    void showDigitShape(const char *line1, const char *line2, const char *line3, const char *line4, const char *line5, unsigned char column);

    unsigned char dotCount = 0;
    int displayRefreshCount = 0;

    bool decimal_separator = false;
    int decimalSeparatorCount = 0;

public:
    DisplayVitor();
    void addDigit(Digit digit, bool withDot = false);
    void setSignal(Signal signal);
    void clear();
};
