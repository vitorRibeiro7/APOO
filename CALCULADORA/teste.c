#include <stdio.h>

float teste(char *v, int size);

int main()
{

    char test[] = {'1', '2', '3', '4'};

    float a;
    a = teste(test, 4);

    printf("%.2f", a);

    return 0;
}

float teste(char *v, int size)
{

    float amount = 0;
    int pin = 1;
    int temp = 0;

    for (int i = size - 1; i >= 0; i--)
    {

        temp = 0;

        switch (v[i])
        {
        case '0':
            temp = 0;
            break;
        case '1':
            temp = 1;
            break;
        case '2':
            temp = 2;
            break;
        case '3':
            temp = 3;
            break;
        case '4':
            temp = 4;
            break;
        case '5':
            temp = 5;
            break;
        case '6':
            temp = 6;
            break;
        case '7':
            temp = 7;
            break;
        case '8':
            temp = 8;
            break;
        case '9':
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