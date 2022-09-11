// #pragma once
#include "SYSTEM/Calculator/calculatorVitor.hpp"
#include "SYSTEM/Display/displayVitor.hpp"

int main()
{
  Display *d1 = new DisplayVitor();

  d1->setSignal(NEGATIVE);
  d1->addDigit(ZERO);
  d1->addDigit(ZERO);
  d1->addDigit(ZERO);
  d1->addDigit(ONE);
  d1->addDigit(TWO);
  d1->addDigit(THREE);
  d1->addDigit(FOUR);
  d1->addDigit(FIVE);
  d1->addDigit(ZERO);
  d1->addDigit(ONE);
  //   d1.clear();

  /*
  Calculator c1;

  c1.getKeyboard().findKey('1').press();
  c1.getKeyboard().findKey('+').press();
  c1.getKeyboard().findKey('1').press();
  c1.getKeyboard().findKey('=').press();
*/
}