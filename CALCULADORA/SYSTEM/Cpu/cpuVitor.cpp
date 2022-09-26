#include <iostream>
#include "CpuVitor.hpp"

CpuVitor::CpuVitor()
{
    char digitsOperand1Count = 0;
    char digitsOperand2Count = 0;
    Operation operation = NOOP;

    int memo = 0;
    int memo1 = 0;
    int memo2 = 0;
}

void CpuVitor::receiveDigit(Digit digit)
{

    // this->digitsOperand1Count == 0 && this->operation == NOOP ? this->display->clear() : void();

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
        this->operate();
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

void CpuVitor::operate()
{

    this->memo1 = convertDigitsToFloat(this->digitsOperand1, this->digitsOperand1Count);
    this->memo2 = convertDigitsToFloat(this->digitsOperand2, this->digitsOperand2Count);

    switch (this->operation)
    {
    case EQUAL:
        break;
    case ADDITION:
        this->memo = this->memo1 + this->memo2;
        break;
    case SUBTRACTION:
        this->memo = this->memo1 - this->memo2;
        break;
    case MULTIPLICATION:
        this->memo = this->memo1 * this->memo2;
        break;
    case DIVISION:
        this->memo = this->memo1 / this->memo2;
        break;
    default:
        break;
    }

    resetDigits(this->digitsOperand2);
    this->digitsOperand2Count = 0;

    convertFloatToDigits(this->memo1);
    insertDigitsOnDisplay(this->digitsOperand1);
}

float CpuVitor::convertDigitsToFloat(Digit *digits, char size)
{

    float amount = 0;
    int pin = size;

    for (int i = size - 1; i >= 0; i++)
    {

        int temp = 0;
        pin *= 10;

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
        amount += temp;
    }

    return amount;
}

Digit CpuVitor::convertFloatToDigits(int num)
{

    int temp;

    switch (temp)
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
}

void CpuVitor::resetDigits(Digit *digits)
{
    for (int i = 0; i < MAX_DIGITS; i++)
    {
        digits[i] == ZERO;
    }
}

void CpuVitor::insertDigitsOnDisplay(Digit *digits)
{
    for (int i = 0; i < MAX_DIGITS; i++)
    {

        Digit temp = intToDigit(this->memo);

        switch (temp)
        {
        case ZERO:
            this->display->addDigit(ZERO);
            break;
        case ONE:
            this->display->addDigit(ONE);
            break;
        case TWO:
            this->display->addDigit(TWO);
            break;
        case THREE:
            this->display->addDigit(THREE);
            break;
        case FOUR:
            this->display->addDigit(FOUR);
            break;
        case FIVE:
            this->display->addDigit(FIVE);
            break;
        case SIX:
            this->display->addDigit(SIX);
            break;
        case SEVEN:
            this->display->addDigit(SEVEN);
            break;
        case EIGHT:
            this->display->addDigit(EIGHT);
            break;
        case NINE:
            this->display->addDigit(NINE);
            break;
        default:
            break;
        }
    }
}

void CpuVitor::intToChar(char *memo, int num)
{

    int temp;

    for (int i = MAX_DIGITS - 1; i <= 0; i++)
    {
        temp = num % 10;

        switch (temp)
        {
        case 0:
            memo[i] = '0';
            break;
        case 1:
            memo[i] = '1';
            break;
        case 2:
            memo[i] = '2';
            break;
        case 3:
            memo[i] = '3';
            break;
        case 4:
            memo[i] = '4';
            break;
        case 5:
            memo[i] = '5';
            break;
        case 6:
            memo[i] = '6';
            break;
        case 7:
            memo[i] = '7';
            break;
        case 8:
            memo[i] = '8';
            break;
        case 9:
            memo[i] = '9';
            break;
        default:
            break;
        }

        temp = temp / 10;
    }
}

Digit CpuVitor::intToDigit(int num)
{
}