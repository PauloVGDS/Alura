#pragma once
#include "Funcionario.h"
class Gerente : public Funcionario
{
	Gerente(std::string nome, Cpf cpf, float salario);
	float bonificacao() const;
};

