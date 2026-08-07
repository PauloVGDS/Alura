#include "Conta.h"
#include <iostream>

int Conta::numeroDeContas = 0;

Conta::Conta(std::string num, Titular titular): 
    numero(num), titular(titular), saldo(0) {
    std::cout << "Construtor Conta Corrente!" << std::endl;
    numeroDeContas++;
}

Conta::~Conta() {
    std::cout << "Destrutor Conta Corrente!" << std::endl;
    numeroDeContas--;
}

float Conta::taxaDeSaque() const {
    return 0.05;
}

void Conta::sacar(float valorASacar) {
    if (valorASacar < 0) {
        std::cout << "Não pode sacar valor negativo!\n";
        return;
    }


    float tarifaDeSaque = valorASacar * taxaDeSaque();
    valorASacar += tarifaDeSaque;

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
    std::cout << "Deposito Corrente\n";
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



