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

    floatToChar(this->memo);
    
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
    return num;
}