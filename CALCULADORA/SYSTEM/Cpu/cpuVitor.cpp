#include <iostream>
#include <cstdio>
#include "cpuVitor.hpp"

CpuVitor::CpuVitor()
{
    this->digitsOperand1Count = 0;
    this->digitsOperand2Count = 0;

    this->dotControlFirstOp = 0;
    this->dotControlSecondOp = 0;

    this->memo = 0;
    this->memo1 = 0;
    this->memo2 = 0;
    this->memory = 0;

    this->decimal_separator = false;
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
}

void CpuVitor::receiveOperation(Operation op)
{
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
        this->memo = 0;
        this->memo1 = 0;
        this->memo2 = 0;
        this->memory = 0;

        this->operation == NOOP;
        this->display ? this->display->clear() : void();
        this->display ? this->display->addDigit(ZERO) : void();

        this->decimal_separator == false;

        this->digitsOperand1Count = 0;
        this->digitsOperand2Count = 0;
        this->resultCount = 0;

        break;
    case EQUAL:
        this->operate();
        break;
    case OFF:
        break;
    case MEMORY_READ_CLEAR:
        this->memo = 0;
        this->memo1 = 0;
        this->memo2 = 0;
        this->memory = 0;
        break;
    case MEMORY_SUBTRACTION:
        break;
    case MEMORY_ADDICTION:
        break;
    case DECIMAL_SEPARATOR:
        if (this->operation == NOOP)
        {
            if (this->dotOne == false)
            {
                this->dotOne = true;
                this->dotControlFirstOp = this->digitsOperand1Count;
            }
        }
        else
        {
            if (this->dotSec == false)
            {
                this->dotSec = true;
                this->dotControlSecondOp = this->digitsOperand2Count;
            }
        }
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

float CpuVitor::charToFloat(char str)
{
    char vIn = str;
    float vOut = (float)vIn;

    return vOut;
}

void CpuVitor::digitsToChar(Digit *digit, char *vet, int size, bool dot, int pos)
{

    if (dot == true)
    {
        size = size + 1;
    }

    for (int i = 0; i < size; i++)
    {

        if (dot == true && i == pos)
        {
            vet[i] = '.';
            i++;
        }

        switch (digit[i])
        {
        case ZERO:
            vet[i] = '0';
            break;
        case ONE:
            vet[i] = '1';
            break;
        case TWO:
            vet[i] = '2';
            break;
        case THREE:
            vet[i] = '3';
            break;
        case FOUR:
            vet[i] = '4';
            break;
        case FIVE:
            vet[i] = '5';
            break;
        case SIX:
            vet[i] = '6';
            break;
        case SEVEN:
            vet[i] = '7';
            break;
        case EIGHT:
            vet[i] = '8';
            break;
        case NINE:
            vet[i] = '9';
            break;
        default:
            vet[i] = '?';
            break;
        }
    }
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

void CpuVitor::floatToChar(float num)
{
    std::sprintf(this->memochar, "%.1f", num);
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

    std::sprintf(result, "%.2f", num);

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
