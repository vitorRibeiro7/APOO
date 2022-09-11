#include "DisplayVitor.hpp"

#include <stdio.h>

void DisplayVitor::refresh()
{
    console.set_color(Color::BG_Green);
    console.set_color(Color::FG_White);
    console.clear_screen();

    if (signal == NEGATIVE)
    {
        this->showDigitShape("    ", "    ", "████", "    ", "    ", 0);
    }
    else
    {
        this->showDigitShape("    ", "  █ ", " ███", "  █ ", "    ", 0);
    }

    for (int i = 1; i <= this->digitsCount; i++)
    {
        switch (this->digits[i - 1])
        {
        case ZERO:
            this->console.set_cursor(1, 1 + i * 5);
            printf("0000");
            this->console.set_cursor(2, 1 + i * 5);
            printf("0  0");
            this->console.set_cursor(3, 1 + i * 5);
            printf("0  0");
            this->console.set_cursor(4, 1 + i * 5);
            printf("0  0");
            this->console.set_cursor(5, 1 + i * 5);
            printf("0000");
            break;
        case ONE:
            this->console.set_cursor(1, 1 + i * 5);
            printf("   1");
            this->console.set_cursor(2, 1 + i * 5);
            printf("   1");
            this->console.set_cursor(3, 1 + i * 5);
            printf("   1");
            this->console.set_cursor(4, 1 + i * 5);
            printf("   1");
            this->console.set_cursor(5, 1 + i * 5);
            printf("   1");
            break;
        case TWO:
            this->showDigitShape("2222", "   2", "2222", "2  ", "2222", i);
            break;
        case THREE:
            this->showDigitShape("😀😀", "  😀", "😀😀", "  😀", "😀😀", i);
            break;
        case FOUR:
            this->showDigitShape("█  █", "█  █", "████", "   █", "   █", i);
            break;
        default:
            this->showDigitShape(" ██ ", "█  █", "  █ ", "    ", "  █ ", i);
        }
    }
}

void DisplayVitor::showDigitShape(const char *line1, const char *line2, const char *line3, const char *line4, const char *line5, unsigned char column)
{
    this->console.set_cursor(1, 1 + column * 5);
    printf(line1);
    this->console.set_cursor(2, 1 + column * 5);
    printf(line2);
    this->console.set_cursor(3, 1 + column * 5);
    printf(line3);
    this->console.set_cursor(4, 1 + column * 5);
    printf(line4);
    this->console.set_cursor(5, 1 + column * 5);
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
    this->refresh();
}
