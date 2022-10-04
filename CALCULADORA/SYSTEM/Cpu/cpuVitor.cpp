#include <iostream>
#include <cstdio>
#include <stdlib.h>
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

    if (op == EQUAL)
    {
        this->display->clear();
        showDigit(this->digitsOperand1, &this->digitsOperand1Count, &this->dotControlFirstOp);
        return;
    }

    // Guardo a operação, mas antes verificar se já existe uma definida e já exisite um operand2
    if (op == EQUAL && this->digitsOperand2Count == 0)
    {
        operate();
        return;
    }

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
                this->dotControlFirstOp = this->digitsOperand1Count;
                this->dotOne = true;
            }
        }
        else
        {
            if (this->dotSec == false)
            {
                this->dotControlSecondOp = this->digitsOperand2Count;
                this->dotSec = true;
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

    // this->memo1 = convertDigitsToFloat(this->digitsOperand1, this->digitsOperand1Count);
    // this->memo2 = convertDigitsToFloat(this->digitsOperand2, this->digitsOperand2Count);

    digitsToChar(this->memo1Char, this->digitsOperand1, this->digitsOperand1Count, this->dotOne, this->dotControlFirstOp);
    digitsToChar(this->memo2Char, this->digitsOperand2, this->digitsOperand2Count, this->dotSec, this->dotControlSecondOp);

    this->memo1 = charToFloat(this->memo1Char);
    this->memo2 = charToFloat(this->memo2Char);

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

    floatToChar(this->memo, this->memochar);

    this->memoCount = countChar(this->memochar);
    convertResultToDigit(this->memo, this->memoCount);

    this->display->clear();
    // std::cout << this->digitsOperand1;
    // std::cout << this->digitsOperand1Count;
    // std::cout << this->dotControlFirstOp;
    showDigit(this->digitsOperand1, &this->digitsOperand1Count, &this->dotControlFirstOp);
}

float CpuVitor::charToFloat(char *str)
{
    char *vIn = str;
    float vOut = (float)strtod(vIn, NULL);

    return vOut;
}

void CpuVitor::digitsToChar(char *vet, Digit *digit, int size, bool dot, int pos)
{

    if (dot == true)
    {
        size = size + 1;
    }

    int j = 0;

    for (int i = 0; i < size; i++)
    {

        if (dot == true && i == pos)
        {
            vet[i] = '.';
            continue;
        }

        switch (digit[j++])
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

void CpuVitor::floatToChar(float num, char *str)
{
    std::sprintf(str, "%.1f", num);
}

void CpuVitor::convertResultToDigit(float num, int size)
{

    if (num < 0)
    {
        this->display ? this->display->setSignal(NEGATIVE) : void();
    }

    char result[100];

    this->floatToChar(num, result);

    std::cout << result;

    this->digitsOperand1Count = 0;
    this->digitsOperand2Count = 0;
    this->operation = NOOP;

    for (int i = 0; i < size; i++)
    {

        switch (result[i])
        {
        case '0':
            // this->receiveDigit(ZERO);
            // if (this->memochar[i + 1] == '.')
            // {
            //     this->decimal_separator = true;
            // }
            this->digitsOperand1[i] == ZERO;

            break;
        case '1':
            // this->receiveDigit(ONE);
            // if (this->memochar[i + 1] == '.')
            // {
            //     this->decimal_separator = true;
            // }
            this->digitsOperand1[i] == ONE;

            break;
        case '2':
            // this->receiveDigit(TWO);
            // if (this->memochar[i + 1] == '.')
            // {
            //     this->decimal_separator = true;
            // }
            this->digitsOperand1[i] == TWO;

            break;
        case '3':
            // this->receiveDigit(THREE);
            // if (this->memochar[i + 1] == '.')
            // {
            //     this->decimal_separator = true;
            // }
            this->digitsOperand1[i] == THREE;

            break;
        case '4':
            // this->receiveDigit(FOUR);
            // if (this->memochar[i + 1] == '.')
            // {
            //     this->decimal_separator = true;
            // }
            this->digitsOperand1[i] == FOUR;

            break;
        case '5':
            // this->receiveDigit(FIVE);
            // if (this->memochar[i + 1] == '.')
            // {
            //     this->decimal_separator = true;
            // }
            this->digitsOperand1[i] == FIVE;

            break;
        case '6':
            // this->receiveDigit(SIX);
            // if (this->memochar[i + 1] == '.')
            // {
            //     this->decimal_separator = true;
            // }
            this->digitsOperand1[i] == SIX;

            break;
        case '7':
            // this->receiveDigit(SEVEN);
            // if (this->memochar[i + 1] == '.')
            // {
            //     this->decimal_separator = true;
            // }
            this->digitsOperand1[i] == SEVEN;

            break;
        case '8':
            // this->receiveDigit(EIGHT);
            // if (this->memochar[i + 1] == '.')
            // {
            //     this->decimal_separator = true;
            // }
            this->digitsOperand1[i] == EIGHT;

            break;
        case '9':
            // this->receiveDigit(NINE);
            // if (this->memochar[i + 1] == '.')
            // {
            //     this->decimal_separator = true;
            // }
            this->digitsOperand1[i] == NINE;

            break;

        case '.':
            this->dotControlFirstOp == i - 1;
            break;
        }

        this->digitsOperand1Count++;
    }

    this->digitsOperand1Count -= 1;
}

void CpuVitor::showDigit(Digit *memo, int *size, int *dotPos)
{

    for (int i = 0; i < *size; i++)
    {
        if (i == *dotPos)
        {
            this->display->addDigit(memo[i], true);
        }
        else
        {
            this->display->addDigit(memo[i]);
        }
    }

    std::cout << '\n';
    std::cout << *size;
    std::cout << '\n';
    std::cout << *dotPos;
    std::cout << '\n';
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
