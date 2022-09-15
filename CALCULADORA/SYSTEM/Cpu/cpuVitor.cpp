#include <iostream>
#include "CpuVitor.hpp"

void CpuVitor::receiveDigit(Digit digit)
{
    // Guardo o dígito no operanto correspondente

    // Envio o dígito para o Display
    this->display->addDigit(digit);
}

void CpuVitor::receiveOperation(Operation)
{
    // Guardo a operação, mas antes verificar se já existe uma definida e já exisite um operand2
}

void CpuVitor::receiveControl(Control control)
{
    switch (control)
    {
    case ON_CLEAR_ERROR:
        this->display->clear();
        break;
    }
}

void CpuVitor::setDisplay(Display &display)
{
    this->display = &display;
}