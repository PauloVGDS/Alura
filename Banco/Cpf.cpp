#include "Cpf.h"
#include <string>

Cpf::Cpf(std::string num): numero(num) {
	verificaCpf();
}

void Cpf::verificaCpf() {
	return;
}

std::string Cpf::recuperaCpf() {
	return numero;
}