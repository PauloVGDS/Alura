#pragma once
#include <string>
#include "Cpf.h"

class Pessoa
{
protected:
	std::string nome;
	Cpf cpfTitular;
	void verificaTamanhoNome();

public:
	Pessoa(std::string nome, Cpf cpfTitular);
	std::string recuperaNome();
};

