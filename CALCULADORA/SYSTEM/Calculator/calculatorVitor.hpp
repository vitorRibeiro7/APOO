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

class Display
{
public:
    virtual void addDigit(Digit);
    virtual void setSignal(Signal);
    virtual void clear();
};

class Cpu
{
public:
    virtual void receiveDigit(int);
    virtual void setDisplay(Display);
};

class Key;
class Keyboard
{
public:
    virtual void receiveDigit(int);
    virtual Key findKey(char);
    virtual void setCpu(Cpu);
};

class Key
{
public:
    virtual void press();
    virtual void setKeyboard(Keyboard);
};
