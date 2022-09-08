#include "iostream"

class display
{
private:
    /* data */
public:
    display(/* args */);

    virtual void addDigit(Digit);
    virtual void setSignal(Signal);
    virtual void clear();

    ~display();
};
