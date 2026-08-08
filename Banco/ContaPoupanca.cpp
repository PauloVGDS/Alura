#include "ContaPoupanca.h"

ContaPoupanca::ContaPoupanca(std::string numero, Titular titular):
    Conta(numero, titular) {
    std::cout << "Construtor Conta Poupança!" << std::endl;
}

ContaPoupanca::~ContaPoupanca() {
    std::cout << "Destrutor Conta Poupança!" << std::endl;
}

float ContaPoupanca::taxaDeSaque() const {
    std::cout << "Método Sacar da Conta Poupança!\n";
    return 0.03f;
}

