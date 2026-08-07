#pragma once
#include <string>
#include <iostream>
#include "Conta.h"

class ContaPoupanca : public Conta
{
public:
    ContaPoupanca(std::string numero, Titular titular);
    ~ContaPoupanca();
    void depositar(float valorADepositar);
    float taxaDeSaque() const override;
};

