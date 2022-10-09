#include <iostream>
#include <cstdio>
#include <stdlib.h>
#include "cpuVitor.hpp"

CpuVitor::CpuVitor()
{
    this->digitsOperand1Count = 0;
    this->digitsOperand2Count = 0;

    this->dotControlFirstOp = -1;
    this->dotControlSecondOp = -1;

    this->memo = 0;
    this->memo1 = 0;
    this->memo2 = 0;

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

        this->operation = NOOP;
        this->display ? this->display->clear() : void();
        this->display ? this->display->addDigit(ZERO) : void();

        this->decimal_separator = false;

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
                this->dotControlFirstOp = this->digitsOperand1Count - 1;
                this->dotOne = true;
            }
        }
        else
        {
            if (this->dotSec == false)
            {
                this->dotControlSecondOp = this->digitsOperand2Count - 1;
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
    digitsToChar(this->memo1Char, this->digitsOperand1, this->digitsOperand1Count, this->dotOne, this->dotControlFirstOp);
    digitsToChar(this->memo2Char, this->digitsOperand2, this->digitsOperand2Count, this->dotSec, this->dotControlSecondOp);

    this->memo1 = charToFloat(this->memo1Char);
    this->memo2 = charToFloat(this->memo2Char);

    std::cout << '\n';
    std::cout << this->memo1;
    std::cout << '\n';
    std::cout << '\n';
    std::cout << this->memo2;
    std::cout << '\n';

    switch (this->operation)
    {
    case EQUAL:
        break;
    case ADDITION:
        this->memo = this->memo1 + this->memo2;
        std::cout << '+';
        break;
    case SUBTRACTION:
        this->memo = this->memo1 - this->memo2;
        std::cout << '-';
        break;
    case MULTIPLICATION:
        this->memo = this->memo1 * this->memo2;
        std::cout << 'x';
        break;
    case DIVISION:
        this->memo = this->memo1 / this->memo2;
        std::cout << '/';
        break;
    default:
        break;
    }

    floatToChar(this->memo, this->memochar);
    this->memoCount = countChar(this->memochar);
    convertResultToDigit(this->memo, this->memoCount);

    debug(this->digitsOperand1);

    this->display->clear();
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
        if (dot == true && i == pos + 1)
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
    for (int i = 0; i < size; i++)
    {
        printf("[%i]%c\n", i, vet[i]);
        printf("\n");
    }
}

void CpuVitor::floatToChar(float num, char *str)
{
    if (this->dotControlFirstOp == -1 && this->dotControlSecondOp == -1)
    {
        std::sprintf(str, "%.0f", num);
    }
    else
    {
        std::sprintf(str, "%.3f", num);
    }
}

void CpuVitor::convertResultToDigit(float num, int size)
{

    if (num < 0)
    {
        this->display ? this->display->setSignal(NEGATIVE) : void();
    }

    char result[100];

    this->floatToChar(num, result);

    std::cout << '\n';
    std::cout << result;
    std::cout << '\n';

    this->digitsOperand1Count = 0;
    this->digitsOperand2Count = 0;
    this->operation = NOOP;

    for (int i = 0; i < size; i++)
    {

        switch (result[i])
        {
        case '0':
            this->digitsOperand1[this->digitsOperand1Count++] = ZERO;
            break;
        case '1':
            this->digitsOperand1[this->digitsOperand1Count++] = ONE;
            break;
        case '2':
            this->digitsOperand1[this->digitsOperand1Count++] = TWO;
            break;
        case '3':
            this->digitsOperand1[this->digitsOperand1Count++] = THREE;
            break;
        case '4':
            this->digitsOperand1[this->digitsOperand1Count++] = FOUR;
            break;
        case '5':
            this->digitsOperand1[this->digitsOperand1Count++] = FIVE;
            break;
        case '6':
            this->digitsOperand1[this->digitsOperand1Count++] = SIX;
            break;
        case '7':
            this->digitsOperand1[this->digitsOperand1Count++] = SEVEN;
            break;
        case '8':
            this->digitsOperand1[this->digitsOperand1Count++] = EIGHT;
            break;
        case '9':
            this->digitsOperand1[this->digitsOperand1Count++] = NINE;
            break;
        case '.':
            this->dotControlFirstOp = i;
            break;
        }

        printf("--\n\n");
        printf("%c\n", result[i]);
        printf("--\n\n");
    }
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
}

void CpuVitor::debug(Digit *digit)
{

    for (int i = 0; i < this->digitsOperand1Count; i++)
    {
        switch (digit[i])
        {
        case ZERO:
            printf("0");
            break;
        case ONE:
            printf("1");
            break;
        case TWO:
            printf("2");
            break;
        case THREE:
            printf("3");
            break;
        case FOUR:
            printf("4");
            break;
        case FIVE:
            printf("5");
            break;
        case SIX:
            printf("6");
            break;
        case SEVEN:
            printf("7");
            break;
        case EIGHT:
            printf("8");
            break;
        case NINE:
            printf("9");
            break;
        default:
            printf("?");
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
