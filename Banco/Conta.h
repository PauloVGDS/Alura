#pragma once
#include <string>
#include "Titular.h"

class Conta {

private:
    std::string numero;
    Titular titular;
    float saldo;

    void verificaTamanhoNome();

public:
    Conta(std::string numero, Titular titular);
    ~Conta();

    static int numeroDeContas;

    void sacar(float valorASacar);
    void depositar(float valorADepositar);

    // Getters
    float recuperaSaldo() const;
    std::string recuperaNumero();

    // Setters
    void defineNumero(std::string numero);
  
};

