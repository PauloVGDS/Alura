#pragma once
#include <string>
#include "Cpf.h"
#include "Pessoa.h"
#include "Autenticavel.h"

class Titular: public Pessoa, public Autenticavel {
public:
	Titular(std::string nome, Cpf cpf, std::string senha);
};

