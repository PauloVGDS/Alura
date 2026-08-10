#include <iostream>
#include "Titular.h"

Titular::Titular(std::string nome, Cpf cpf, std::string senha):
	Pessoa(nome, cpf), Autenticavel(senha) {
}