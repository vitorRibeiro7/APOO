#include "iostream"

class key
{
private:
public:
    key();

    virtual void press();
    virtual void setKeyboard(keyboard);

    ~key();
};