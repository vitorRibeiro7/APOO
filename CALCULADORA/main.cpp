// #pragma once
#include <iostream>
#include "SYSTEM/Calculator/calculatorVitor.hpp"
#include "SYSTEM/Cpu/cpuVitor.hpp"
#include "SYSTEM/Display/displayVitor.hpp"
#include "SYSTEM/Keyboard/keyboardVitor.hpp"
#include "SYSTEM/Key/keyVitor.hpp"

void testDisplay(DisplayVitor &display)
{
  display.setSignal(NEGATIVE);
  display.addDigit(ZERO);
  display.clear();
  display.addDigit(ZERO);
  display.addDigit(ZERO);
  display.addDigit(ONE);
  display.addDigit(TWO, true);
  display.addDigit(THREE);
  display.addDigit(FOUR);
  display.addDigit(FIVE);
  display.addDigit(ZERO);
}

void testCpu(CpuVitor &cpu)
{
  cpu.receiveControl(ON_CLEAR_ERROR);
  cpu.receiveDigit(ONE);
  cpu.receiveControl(DECIMAL_SEPARATOR);
  cpu.receiveDigit(ONE);
  cpu.receiveOperation(ADDITION);
  cpu.receiveDigit(ONE);
  cpu.receiveControl(DECIMAL_SEPARATOR);
  cpu.receiveDigit(ONE);
  // cpu.receiveOperation(ADDITION);
  // cpu.receiveDigit(ONE);
  // cpu.receiveControl(DECIMAL_SEPARATOR);
  // cpu.receiveDigit(ONE);
  // cpu.receiveOperation(ADDITION);
  // cpu.receiveDigit(ONE);
  // cpu.receiveControl(DECIMAL_SEPARATOR);
  // cpu.receiveDigit(ONE);
  // cpu.receiveOperation(ADDITION);
  // cpu.receiveDigit(ONE);
  // cpu.receiveControl(DECIMAL_SEPARATOR);
  // cpu.receiveDigit(ONE);
  cpu.receiveControl(EQUAL);
}

void testKeyboard(Keyboard &keyboard)
{
  try
  {
    // keyboard.findKey('1').press();
    // keyboard.findKey('0').press();
    // keyboard.findKey('0').press();
    // keyboard.findKey('0').press();
    // keyboard.findKey('0').press();
    // keyboard.findKey('0').press();
    // keyboard.findKey('x').press();
    // keyboard.findKey('1').press();
    // keyboard.findKey('.').press();
    // keyboard.findKey('5').press();
    // keyboard.findKey('=').press();

    // keyboard.findKey('3').press();
    // keyboard.findKey('0').press();
    // keyboard.findKey('+').press();
    // keyboard.findKey('1').press();
    // keyboard.findKey('0').press();
    // keyboard.findKey('=').press();
    // keyboard.findKey('=').press();
    // keyboard.findKey('+').press();
    // keyboard.findKey('3').press();
    // keyboard.findKey('0').press();
    // keyboard.findKey('=').press();
    // keyboard.findKey('m').press();

    // keyboard.findKey('2').press();
    // keyboard.findKey('.').press();
    // keyboard.findKey('4').press();
    // keyboard.findKey('-').press();
    // keyboard.findKey('1').press();
    // keyboard.findKey('.').press();
    // keyboard.findKey('2').press();
    // keyboard.findKey('=').press();

    // keyboard.findKey('4').press();
    // keyboard.findKey('9').press();
    // keyboard.findKey('3').press();
    // keyboard.findKey('8').press();
    // keyboard.findKey('2').press();
    // keyboard.findKey('.').press();
    // keyboard.findKey('7').press();
    // keyboard.findKey('1').press();
    // keyboard.findKey('+').press();
    // keyboard.findKey('1').press();

    keyboard.findKey('2').press();
    keyboard.findKey('.').press();
    keyboard.findKey('2').press();
    keyboard.findKey('+').press();
    keyboard.findKey('2').press();
    keyboard.findKey('=').press();
    keyboard.findKey('A').press();
    keyboard.findKey('D').press();
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

  KeyVitor keyZero('0', ZERO);
  KeyVitor keyOne('1', ONE);
  KeyVitor keyTwo('2', TWO);
  KeyVitor keyThree('3', THREE);
  KeyVitor keyFour('4', FOUR);
  KeyVitor keyFive('5', FIVE);
  KeyVitor keySix('6', SIX);
  KeyVitor keySeven('7', SEVEN);
  KeyVitor keyEight('8', EIGHT);
  KeyVitor keyNine('9', NINE);

  KeyVitor keyDot('.', DECIMAL_SEPARATOR);

  KeyVitor keyAddition('+', ADDITION);
  KeyVitor keySubtraction('-', SUBTRACTION);
  KeyVitor keyMultiplication('x', MULTIPLICATION);
  KeyVitor keyDivision('/', DIVISION);
  KeyVitor keySquare('V', SQUARE_ROOT);
  KeyVitor keyEqual('=', EQUAL);

  KeyVitor keyMadd('A', MEMORY_ADDICTION);
  KeyVitor keyMsub('S', MEMORY_SUBTRACTION);
  KeyVitor keyMshow('D', MEMORY_READ_CLEAR);

  /* Fase de construção/ligação */
  c1.setDisplay(d1);
  kb1.setCpu(c1);

  kb1.addKey(keyZero);
  kb1.addKey(keyOne);
  kb1.addKey(keyTwo);
  kb1.addKey(keyThree);
  kb1.addKey(keyFour);
  kb1.addKey(keyFive);
  kb1.addKey(keySix);
  kb1.addKey(keySeven);
  kb1.addKey(keyEight);
  kb1.addKey(keyNine);

  kb1.addKey(keyDot);

  kb1.addKey(keyAddition);
  kb1.addKey(keySubtraction);
  kb1.addKey(keyMultiplication);
  kb1.addKey(keyDivision);
  kb1.addKey(keySquare);
  kb1.addKey(keyEqual);

  kb1.addKey(keyMsub);
  kb1.addKey(keyMadd);
  kb1.addKey(keyMshow);

  /* Fase de testes */
  // testDisplay(d1);
  // testCpu(c1);
  testKeyboard(kb1);
}