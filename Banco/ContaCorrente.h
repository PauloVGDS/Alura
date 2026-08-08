#pragma once
#include <string>
#include <iostream>
#include "Conta.h"

class ContaCorrente : public Conta
{
public:
	ContaCorrente(std::string numero, Titular titular);
	~ContaCorrente();
	float taxaDeSaque() const override;

};

