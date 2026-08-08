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

void ContaPoupanca::transferePara(Conta& destino, float valor) {
     sacar(valor);
     destino.depositar(valor);
     std::cout << "Transferência realizada!\n";
}

