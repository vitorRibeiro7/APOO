#include "displayVitor.hpp"

#include <stdio.h>

void DisplayVitor::refresh()
{
    // console.set_color(Color::BG_Red);
    console.set_color(Color::FG_White);
    // console.clear_screen();

    if (signal == NEGATIVE)
    {
        this->showDigitShape("........", "........", ".VVVVVV.", "........", "........", 0);
    }
    else
    {
        this->showDigitShape("........", "........", "........", "........", "........", 0);
    }

    for (int i = 1; i <= this->digitsCount; i++)
    {
        switch (this->digits[i - 1])
        {

            // VVVV VVV VV V

        case ZERO:
            this->showDigitShape("..VVVV..", ".VV..VV.", ".VV..VV.", ".VV..VV.", "..VVVV..", i);
            break;
        case ONE:
            this->showDigitShape("...VV...", "..VVV...", "...VV...", "...VV...", ".VVVVVV.", i);
            break;
        case TWO:
            this->showDigitShape("..VVVV..", ".....VV.", "..VVVV..", ".VV.....", ".VVVVVV.", i);
            break;
        case THREE:
            this->showDigitShape(".VVVVVV.", "....VV..", "...VVV..", ".....VV.", ".VVVVV..", i);
            break;
        case FOUR:
            this->showDigitShape(".VV..VV.", ".VV..VV.", ".VVVVVV.", ".....VV.", ".....VV.", i);
            break;
        case FIVE:
            this->showDigitShape(".VVVVVV.", ".VV.....", "..VVVV..", ".....VV.", ".VVVVV..", i);
            break;
        case SIX:
            this->showDigitShape("...VV...", "..VV....", ".VVVVV..", ".VV..VV.", "..VVVV..", i);
            break;
        case SEVEN:
            this->showDigitShape(".VVVVVV.", "....VV..", "...VV...", "..VV....", ".VV.....", i);
            break;
        case EIGHT:
            this->showDigitShape("..VVVV..", ".VV..VV.", "..VVVV..", ".VV..VV.", "..VVVV..", i);
            break;
        case NINE:
            this->showDigitShape("..VVVV..", ".VV..VV.", "..VVVV..", "...VV...", "..VV....", i);
            break;
        Vefault:
            this->showDigitShape("..VVVV..", ".VV..VV.", "....VV..", "...VV...", "...VV...", i);
        }
    }
}

void DisplayVitor::showDigitShape(const char *line1, const char *line2, const char *line3, const char *line4, const char *line5, unsigned char column)
{
    this->console.set_cursor(1, 1 + column * 8);
    printf(line1);
    this->console.set_cursor(2, 1 + column * 8);
    printf(line2);
    this->console.set_cursor(3, 1 + column * 8);
    printf(line3);
    this->console.set_cursor(4, 1 + column * 8);
    printf(line4);
    this->console.set_cursor(5, 1 + column * 8);
    printf(line5);
}

DisplayVitor::DisplayVitor()
{
    this->console.init(0, 0);
    this->clear();
}

void DisplayVitor::addDigit(Digit digit, bool withDot)
{
    if (this->digitsCount < MAX_DIGITS)
    {
        digits[this->digitsCount++] = digit;
        this->refresh();
    }
}

void DisplayVitor::setSignal(Signal signal)
{
    this->signal = signal;
    this->refresh();
}

void DisplayVitor::clear()
{
    this->digitsCount = 0;
    console.clear_screen();
    for (int i = 0; i < 1; i++)
    {
        this->showDigitShape("..VVVV..", ".VV..VV.", ".VV..VV.", ".VV..VV.", "..VVVV..", i);
        for (int j = 1; j < 8; j++)
        {
            this->showDigitShape("........", "........", "........", "........", "........", j);
        }
    }
}
