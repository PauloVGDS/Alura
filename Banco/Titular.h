#pragma once
#include <string>
#include "Cpf.h"

class Titular {
private:
	std::string nome;
	Cpf cpfTitular;
	void verificaTamanhoNome();

public:
	Titular(std::string nome, Cpf cpf);
	std::string recuperaNome() const;
};

