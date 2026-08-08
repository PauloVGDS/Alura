#pragma once
#include <string>
#include "Titular.h"
#include "Pessoa.h"

class Funcionario: public Pessoa
{
private:
	float salario;

public:
	Funcionario(std::string nome, Cpf cpf, float salario);
	std::string recuperaNome() const;
	float recuperaSalario() const;
	virtual float bonificacao() const = 0;
};

