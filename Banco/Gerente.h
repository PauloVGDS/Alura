#pragma once
#include "Funcionario.h"
#include  "Autenticavel.h"

class Gerente : public Funcionario, public Autenticavel
{
	Gerente(std::string nome, Cpf cpf, float salario, std::string senha);
	float bonificacao() const;
};

