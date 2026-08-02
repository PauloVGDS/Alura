#include "Titular.h"
#include <iostream>

Titular::Titular(std::string nome, Cpf cpf) :
    nome(nome), cpfTitular(cpf) {
    verificaTamanhoNome();
};

void Titular::verificaTamanhoNome() {
    if (nome.size() < 5) {
        std::cout << "Nome muito curto!" << std::endl;
        exit(1);
    }
}

std::string Titular::recuperaNome() const{
    return nome;
}


