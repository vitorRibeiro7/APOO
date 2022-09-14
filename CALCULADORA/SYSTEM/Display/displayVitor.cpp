#include "DisplayVitor.hpp"

#include <stdio.h>

void DisplayVitor::refresh()
{
    console.set_color(Color::BG_Red);
    console.set_color(Color::FG_White);
    console.clear_screen();

    if (signal == NEGATIVE)
    {
        this->showDigitShape("........", "........", ".000000.", "........", "........", 0);
    }
    else
    {
        this->showDigitShape("...00...", "...00...", ".000000.", "...00...", "...00...", 0);
    }

    for (int i = 1; i <= this->digitsCount; i++)
    {
        switch (this->digits[i - 1])
        {
        case ZERO:
            this->showDigitShape("..0000..", ".00..00.", ".00..00.", ".00..00.", "..0000..", i);
            break;
        case ONE:
            this->showDigitShape("...00...", "..000...", "...00...", "...00...", ".000000.", i);
            break;
        case TWO:
            this->showDigitShape("..0000..", ".....00.", "..0000..", ".00.....", ".000000.", i);
            break;
        case THREE:
            this->showDigitShape(".000000.", "....00..", "...000..", ".....00.", ".0000#..", i);
            break;
        case FOUR:
            this->showDigitShape(".00..00.", ".00..00.", ".000000.", ".....00.", ".....00.", i);
            break;
        case FIVE:
            this->showDigitShape(".000000.", ".00.....", "..0000..", ".....00.", ".0000#..", i);
            break;
        case SIX:
            this->showDigitShape("...00...", "..00....", ".0000#..", ".00..00.", "..0000..", i);
            break;
        case SEVEN:
            this->showDigitShape(".000000.", "....00..", "...00...", "..00....", ".00.....", i);
            break;
        case EIGHT:
            this->showDigitShape("..0000..", ".00..00.", "..0000..", ".00..00.", "..0000..", i);
            break;
        case NINE:
            this->showDigitShape("..0000..", ".00..00.", "..0000..", "...00...", "..00....", i);
            break;
        default:
            this->showDigitShape("..0000..", ".00..00.", "....00..", "...00...", "...00...", i);
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

void DisplayVitor::addDigit(Digit digit)
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
}
