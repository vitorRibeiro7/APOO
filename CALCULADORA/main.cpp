// #pragma once
#include <iostream>
#include "SYSTEM/Calculator/calculatorVitor.hpp"
#include "SYSTEM/Cpu/cpuVitor.hpp"
#include "SYSTEM/Display/displayVitor.hpp"

void testDisplay(DisplayVitor &display)
{
  std::cout << "Testing DISPLAY...\n";
  display.setSignal(NEGATIVE);
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
  display.addDigit(ONE);
}

void testCpu(CpuVitor &cpu)
{
  std::cout << "Testing CPU...\n";
  cpu.receiveControl(ON_CLEAR_ERROR);
  cpu.receiveDigit(ONE);
  cpu.receiveDigit(TWO);
  cpu.receiveDigit(THREE);
  cpu.receiveOperation(ADDITION);
  cpu.receiveDigit(FOUR);
  cpu.receiveDigit(FIVE);
  cpu.receiveDigit(SIX);
  cpu.receiveOperation(EQUAL);
}

int main()
{
  /* Fase de criação */
  /* Instancie suas implementações aqui */
  DisplayVitor d1;
  CpuVitor c1;

  /* Fase de construção/ligação */
  c1.setDisplay(d1);

  /* Fase de testes */
  testDisplay(d1);
  testCpu(c1);
}