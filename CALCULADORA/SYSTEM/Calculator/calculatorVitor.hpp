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

enum Operation
{
    ADDITION,
    SUBTRACTION,
    MULTIPLICATION,
    DIVISION,
    EQUAL,
    NOOP
};

enum Control
{
    OFF,
    ON_CLEAR_ERROR,
    MEMORY_READ_CLEAR,
    MEMORY_SUBTRACTION,
    MEMORY_ADDICTION
};

class Display
{
public:
    virtual void addDigit(Digit, bool withDot = false) = 0;
    virtual void setDecimalSeparator() = 0;
    virtual void setSignal(Signal) = 0;
    virtual void clear() = 0;
};

class Cpu
{
public:
    virtual void receiveDigit(Digit) = 0;
    virtual void receiveOperation(Operation) = 0;
    virtual void receiveControl(Control) = 0;
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

class Controle
{
private:
    /* data */
public:
    Controle(/* args */);
    ~Controle();
};