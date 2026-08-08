#include "Funcionario.h"

Funcionario::Funcionario(std::string nome, Cpf cpf, float salario) :
	Pessoa(nome, cpf), salario(salario) {
}

std::string Funcionario::recuperaNome() {
	return nome;
}