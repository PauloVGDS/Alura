#pragma once
#include <string>
#include "Cpf.h"
#include "Pessoa.h"

class Titular: public Pessoa {
public:
	Titular(std::string nome, Cpf cpf);
};

