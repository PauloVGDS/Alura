#include "ContaPoupanca.h"

ContaPoupanca::ContaPoupanca(std::string numero, Titular titular):
    Conta(numero, titular) {
    std::cout << "Construtor Conta Poupança!" << std::endl;
}

ContaPoupanca::~ContaPoupanca() {
    std::cout << "Destrutor Conta Poupança!" << std::endl;
}

float ContaPoupanca::taxaDeSaque() const {
    return 0.03;
}

void ContaPoupanca::depositar(float valorADepositar) {
    if (valorADepositar < 0) {
        std::cout << "Não pode depositar valor negativo!\n";
        return;
    }
    std::cout << "Deposito Poupança\n";
    saldo += valorADepositar;
}
