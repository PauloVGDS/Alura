#include "ContaCorrente.h"

ContaCorrente::ContaCorrente(std::string numero, Titular titular) :
    Conta(numero, titular) {
    std::cout << "Construtor Conta Corrente!" << std::endl;
}

ContaCorrente::~ContaCorrente() {
    std::cout << "Destrutor Conta Corrente!" << std::endl;
}

float ContaCorrente::taxaDeSaque() const {
    std::cout << "Método Sacar da Conta Corrente!\n";
    return 0.05f;
}