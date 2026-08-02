#include "Conta.h"
#include <iostream>

int Conta::numeroDeContas = 0;

Conta::Conta(std::string num, Titular titular): 
    numero(num), titular(titular), saldo(0) {
    numeroDeContas++;
}

Conta::~Conta() {
    numeroDeContas--;
}

void Conta::sacar(float valorASacar) {
    if (valorASacar < 0) {
        std::cout << "Não pode sacar valor negativo!\n";
        return;
    }
    if (valorASacar > saldo) {
        std::cout << "Saldo insuficiente!\n";
        return;
    }

    saldo -= valorASacar;
}


void Conta::depositar(float valorADepositar) {
    if (valorADepositar < 0) {
        std::cout << "Não pode depositar valor negativo!\n";
        return;
    }
    saldo += valorADepositar;
}

float Conta::recuperaSaldo() const {
    return saldo;
}

std::string Conta::recuperaNumero() {
    return numero;
}

void Conta::defineNumero(std::string num) {
    if (num.empty()) {
        std::cout << "Insira um numero valido!" << std::endl;
        return;
    }
    numero = num;
}



