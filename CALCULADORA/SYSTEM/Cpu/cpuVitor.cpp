#include <iostream>
#include "cpuVitor.hpp"

CpuVitor::CpuVitor()
{
    char digitsOperand1Count = 0;
    char digitsOperand2Count = 0;
    Operation operation = NOOP;

    int memo = 0;
    int memo1 = 0;
    int memo2 = 0;

    bool decimal_separator = false;
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

    if (op == SUBTRACTION && this->operation == NOOP)
    {
        this->display ? this->display->setSignal(NEGATIVE) : void();
    }

    if (op == SUBTRACTION && this->operation != NOOP)
    {
        this->display ? this->display->setSignal(NEGATIVE) : void();
        this->operation = NOOP;
    }

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

    floatToChar(this->memo);
    convertResultToDigit(this->memo, MAX_DIGITS);
}

float CpuVitor::convertDigitsToFloat(Digit *digits, int size)
{

    float amount = 0;
    int pin = 1;
    int temp = 0;

    for (int i = size - 1; i >= 0; i--)
    {

        temp = 0;

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
        pin *= 10;
        amount += temp;
    }

    return amount;
}

char CpuVitor::floatToChar(float num)
{
    std::sprintf(this->memochar, "%.3f", num);
}

float CpuVitor::charToFloat(char *operation)
{
    float num;
    num = atof(operation);
    if (this->signal == NEGATIVE)
    {
        num = num * -1;
        this->signal = POSITIVE;
    }
    return num;
}

void CpuVitor::convertResultToDigit(float num, int size)
{
    this->floatToChar(num);

    if (num < 0)
    {
        this->display ? this->display->setSignal(NEGATIVE) : void();
    }
    char result[100];
    std::sprintf(result, "%g", num);

    for (int i = 0; i < size; i++)
    {
        switch (result[i])
        {
        case '0':
            this->display ? this->display->addDigit(ZERO) : void();
            break;
        case '1':
            this->display ? this->display->addDigit(ONE) : void();
            break;
        case '2':
            this->display ? this->display->addDigit(TWO) : void();
            break;
        case '3':
            this->display ? this->display->addDigit(THREE) : void();
            break;
        case '4':
            this->display ? this->display->addDigit(FOUR) : void();
            break;
        case '5':
            this->display ? this->display->addDigit(FIVE) : void();
            break;
        case '6':
            this->display ? this->display->addDigit(SIX) : void();
            break;
        case '7':
            this->display ? this->display->addDigit(SEVEN) : void();
            break;
        case '8':
            this->display ? this->display->addDigit(EIGHT) : void();
            break;
        case '9':
            this->display ? this->display->addDigit(NINE) : void();
            break;
        case '.':
            this->decimal_separator = false;
            this->display ? this->display->setDecimalSeparator() : void();
            break;
        }
    }
}