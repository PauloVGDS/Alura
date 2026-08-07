#include <iostream>
#include "Pessoa.h"

Pessoa::Pessoa(std::string nome, Cpf cpfTitula):
	nome(nome), cpfTitular(cpfTitula){
    verificaTamanhoNome();
}

void Pessoa::verificaTamanhoNome() {
    if (nome.size() < 5) {
        std::cout << "Nome muito curto!" << std::endl;
        exit(1);
    }
}