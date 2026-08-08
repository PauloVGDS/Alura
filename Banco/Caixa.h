#pragma once
#include "Funcionario.h"

class Caixa : public Funcionario
{
	Caixa(std::string nome, Cpf cpf, float salario);
	float bonificacao() const;
};

