#include "displayVitor.hpp"

#include <stdio.h>

void DisplayVitor::refresh()
{
    console.set_color(Color::BG_Black);
    console.set_color(Color::FG_Magenta);
    console.clear_screen();

    if (this->decimalSeparatorCount > 0)
    {
        this->displayRefreshCount = this->digitsCount + 1;
    }
    else
    {
        this->displayRefreshCount = this->digitsCount;
    }

    if (signal == NEGATIVE)
    {
        this->showDigitShape("........", "........", ".VVVVVV.", "........", "........", 0);
    }
    else
    {
        this->showDigitShape("........", "........", "........", "........", "........", 0);
    }

    int i = 1;
    int j = this->decimal_position;

    for (int x = 1; x <= this->displayRefreshCount; x++)
    {

        if (x == this->decimal_position)
        {
            this->showDigitShape("........", "........", "........", ".VV.....", ".VV.....", x);
            continue;
        }

        switch (this->digits[i - 1])
        {
        case ZERO:
            if (this->decimal_position != -1)
            {
                return;
            }
            this->showDigitShape("..VVVV..", ".VV..VV.", ".VV..VV.", ".VV..VV.", "..VVVV..", x);
            i++;
            break;
        case ONE:
            this->showDigitShape("...VV...", "..VVV...", "...VV...", "...VV...", ".VVVVVV.", x);
            i++;
            break;
        case TWO:
            this->showDigitShape("..VVVV..", ".....VV.", "..VVVV..", ".VV.....", ".VVVVVV.", x);
            i++;
            break;
        case THREE:
            this->showDigitShape(".VVVVVV.", "....VV..", "...VVV..", ".....VV.", ".VVVVV..", x);
            i++;
            break;
        case FOUR:
            this->showDigitShape(".VV..VV.", ".VV..VV.", ".VVVVVV.", ".....VV.", ".....VV.", x);
            i++;
            break;
        case FIVE:
            this->showDigitShape(".VVVVVV.", ".VV.....", "..VVVV..", ".....VV.", ".VVVVV..", x);
            i++;
            break;
        case SIX:
            this->showDigitShape("...VV...", "..VV....", ".VVVVV..", ".VV..VV.", "..VVVV..", x);
            i++;
            break;
        case SEVEN:
            this->showDigitShape(".VVVVVV.", "....VV..", "...VV...", "..VV....", ".VV.....", x);
            i++;
            break;
        case EIGHT:
            this->showDigitShape("..VVVV..", ".VV..VV.", "..VVVV..", ".VV..VV.", "..VVVV..", x);
            i++;
            break;
        case NINE:
            this->showDigitShape("..VVVV..", ".VV..VV.", "..VVVV..", "...VV...", "..VV....", x);
            i++;
            break;
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
    this->decimal_position = -1;
    this->clear();
}

void DisplayVitor::addDigit(Digit digit, bool withDot)
{
    if (this->digitsCount < MAX_DIGITS)
    {
        digits[this->digitsCount++] = digit;

        if (withDot == true && this->decimal_position == -1)
        {
            this->decimal_position = digitsCount;
        }
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
    this->intBlock = false;
    this->digitsCount = 0;
    this->decimal_position = -1;
    this->dotCount = 0;
    this->displayRefreshCount = 0;
    this->refresh();
}