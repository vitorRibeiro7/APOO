#include <iostream>
#include "CpuVitor.hpp"

void CpuVitor::receiveDigit(Digit digit)
{
    // Guardo o dígito no operanto correspondente
    if (this->operation == NOOP)
    {
        this->digitsOperand1[this->digitsOperand1Count++] = digit;
    }
    else
    {
        this->digitsOperand2[this->digitsOperand2Count++] = digit;
    }

    // Envio o dígito para o Display
    this->display->addDigit(digit);
}

void CpuVitor::receiveOperation(Operation op)
{
    // Guardo a operação, mas antes verificar se já existe uma definida e já exisite um operand2
    if ((this->operation != NOOP) && (this->digitsOperand1Count > 0))
    {
        this->operate(operation);
    }

    this->operation = op;
}

void CpuVitor::receiveControl(Control control)
{
    switch (control)
    {
    case ON_CLEAR_ERROR:
        this->display->clear();
        break;
    case EQUAL:
        break;
    }
}

void CpuVitor::setDisplay(Display &display)
{
    this->display = &display;
}

void CpuVitor::operate(Operation op)
{
    int *opp = (int *)calloc(MAX_DIGITS, sizeof(int));
    int i = 0;

    for (i = 0; i < MAX_DIGITS; i++)
    {
        Digit digit = intToDigit(opp[i]);
        this->digitsOperand1[i] = digit;
    }
    free(opp);
}

Digit CpuVitor::intToDigit(int num)
{

    switch (num)
    {
    case 0:
        return ZERO;
        break;
    case 1:
        return ONE;
        break;
    case 2:
        return TWO;
        break;
    case 3:
        return THREE;
        break;
    case 4:
        return FOUR;
        break;
    case 5:
        return FIVE;
        break;
    case 6:
        return SIX;
        break;
    case 7:
        return SEVEN;
        break;
    case 8:
        return EIGHT;
        break;
    case 9:
        return NINE;
        break;
    default:
        break;
    }

    return ZERO;
}

void oparate(Operation op)
{

    switch (op)
    {
    case EQUAL:
        break;
    case ADDITION:
        break;
    case SUBTRACTION:
        break;
    case MULTIPLICATION:
        break;
    case DIVISION:
        break;
    default:
        break;
    }
}

int digitToInt(Digit *digits)
{

    int amount = 0;

    for (int i = MAX_DIGITS - 1; i > 0; i++)
    {

        int temp = 0;
        int pin = 1;

        switch (digits[i])
        {
        case ZERO:
            temp = 0;
            break;
        case ONE:
            temp = 1;
            break;
        case TWO:
            temp = 2;
            break;
        case THREE:
            temp = 3;
            break;
        case FOUR:
            temp = 4;
            break;
        case FIVE:
            temp = 5;
            break;
        case SIX:
            temp = 6;
            break;
        case SEVEN:
            temp = 7;
            break;
        case EIGHT:
            temp = 8;
            break;
        case NINE:
            temp = 9;
            break;
        default:
            break;
        }

        temp = temp * pin;
        pin = pin * 10;
        amount += temp;
    }

    return amount;
}