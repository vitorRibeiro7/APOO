#pragma once

enum Digit
{
    ZERO,
    ONE,
    TWO,
    THREE,
    FOUR,
    FIVE,
    SIX,
    SEVEN,
    EIGHT,
    NINE
};

enum Signal
{
    POSITIVE,
    NEGATIVE
};

enum Operator
{
    MULTIPLICATION,
    ADDICTION,
    DIVISION,
    SUBTRACTION
};

class Display
{
public:
    virtual void addDigit(Digit) = 0;
    virtual void setSignal(Signal) = 0;
    virtual void clear() = 0;
};

class Cpu
{
public:
    virtual void receiveDigit(int) = 0;
    virtual void setDisplay(Display &) = 0;
};

class Key;
class Keyboard
{
public:
    virtual void receiveDigit(int) = 0;
    virtual Key findKey(char) = 0;
    virtual void setCpu(Cpu &) = 0;
};

class Key
{
public:
    virtual void press();
    virtual void setKeyboard(Keyboard &);
};
