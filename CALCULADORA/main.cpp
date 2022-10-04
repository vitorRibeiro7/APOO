// #pragma once
#include <iostream>
#include "SYSTEM/Calculator/calculatorVitor.hpp"
#include "SYSTEM/Cpu/cpuVitor.hpp"
#include "SYSTEM/Display/displayVitor.hpp"
#include "SYSTEM/Keyboard/keyboardVitor.hpp"
#include "SYSTEM/Key/keyVitor.hpp"

void testDisplay(DisplayVitor &display)
{
  std::cout << "Testing DISPLAY...\n";
  // display.setSignal(NEGATIVE);
  display.addDigit(ZERO);
  display.clear();
  display.addDigit(ZERO);
  display.addDigit(ZERO);
  display.addDigit(ONE);
  display.addDigit(TWO);
  display.addDigit(THREE);
  display.addDigit(FOUR);
  display.addDigit(FIVE);
  display.addDigit(ZERO);
}

void testCpu(CpuVitor &cpu)
{
  std::cout << "Testing CPU...\n";
  cpu.receiveControl(ON_CLEAR_ERROR);
  cpu.receiveDigit(ONE);
  cpu.receiveControl(DECIMAL_SEPARATOR);
  cpu.receiveDigit(ONE);
  cpu.receiveDigit(ONE);
  cpu.receiveOperation(ADDITION);
  cpu.receiveDigit(ONE);
  cpu.receiveControl(DECIMAL_SEPARATOR);
  cpu.receiveDigit(ONE);
  cpu.receiveDigit(ONE);
  // cpu.receiveDigit(ONE);
  cpu.receiveOperation(EQUAL);
}

void testKeyboard(Keyboard &keyboard)
{
  try
  {
    keyboard.findKey('1').press();
    keyboard.findKey('+').press();
    keyboard.findKey('1').press();
    keyboard.findKey('=').press();
  }
  catch (const char *exception)
  {
    std::cerr << exception;
  }
}

int main()
{
  /* Fase de criação */
  /* Instancie suas implementações aqui */
  DisplayVitor d1;
  CpuVitor c1;
  KeyboardVitor kb1;

  KeyVitor keyOne('1', ONE);
  KeyVitor keyTwo('2', TWO);
  KeyVitor keyThree('3', THREE);

  KeyVitor keyAddition('+', ADDITION);
  KeyVitor keyEqual('=', EQUAL);

  /* Fase de construção/ligação */
  c1.setDisplay(d1);
  kb1.setCpu(c1);

  kb1.addKey(keyOne);
  kb1.addKey(keyTwo);
  kb1.addKey(keyThree);

  kb1.addKey(keyAddition);
  kb1.addKey(keyEqual);

  /* Fase de testes */
  // testDisplay(d1);
  testCpu(c1);
  // testKeyboard(kb1);
}