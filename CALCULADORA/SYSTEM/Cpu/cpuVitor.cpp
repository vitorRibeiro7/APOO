#include <iostream>
#include <cstdio>
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

    this->digitsOperand1Count == 0 && this->operation == NOOP ? this->display->clear() : void();

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
    this->display->addDigit(digit, this->decimal_separator);

    this->decimal_separator == true ? this->decimal_separator = false : this->decimal_separator = true;
}

void CpuVitor::receiveOperation(Operation op)
{

    // if (op == SUBTRACTION && this->operation == NOOP)
    // {
    //     this->display ? this->display->setSignal(NEGATIVE) : void();
    // }

    // if (op == SUBTRACTION && this->operation != NOOP)
    // {
    //     this->display ? this->display->setSignal(NEGATIVE) : void();
    //     this->operation = NOOP;
    // }

    // Guardo a operação, mas antes verificar se já existe uma definida e já exisite um operand2
    if ((this->operation != NOOP) && (this->digitsOperand2Count > 0))
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
    this->memoCount = countChar(this->memochar);
    convertResultToDigit(this->memo, this->memoCount);
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
        // case DECIMAL_SEPARATOR:
        // FAZER O NUMERO TER O PONTO
        // break;
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
    std::sprintf(this->memochar, "%.0f", num);
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

    std::sprintf(result, "%.0f", num);

    this->digitsOperand1Count = 0;
    this->digitsOperand2Count = 0;
    this->operation = NOOP;

    for (int i = 0; i < size; i++)
    {
        switch (result[i])
        {
        case '0':
            this->receiveDigit(ZERO);
            break;
        case '1':
            this->receiveDigit(ONE);
            break;
        case '2':
            this->receiveDigit(TWO);
            break;
        case '3':
            this->receiveDigit(THREE);
            break;
        case '4':
            this->receiveDigit(FOUR);
            break;
        case '5':
            this->receiveDigit(FIVE);
            break;
        case '6':
            this->receiveDigit(SIX);
            break;
        case '7':
            this->receiveDigit(SEVEN);
            break;
        case '8':
            this->receiveDigit(EIGHT);
            break;
        case '9':
            this->receiveDigit(NINE);
            break;
        case '.':
            this->decimal_separator = true;
            break;
        }
    }
}

int CpuVitor::countChar(char *str)
{
    int count = 0;
    int i = 0;

    while (str[i] != '\0')
    {
        count++;
        i++;
    }

    return count;
}
