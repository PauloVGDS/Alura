#pragma once
#include <string>
#include "Titular.h"

class Conta {

private:
    std::string numero;
    Titular titular;

protected:
    float saldo;

public:
    Conta(std::string numero, Titular titular);
    virtual ~Conta();

    static int numeroDeContas;

    virtual void sacar(float valorASacar);
    virtual void depositar(float valorADepositar);
    virtual float taxaDeSaque() const;
    // Getters
    float recuperaSaldo() const;
    std::string recuperaNumero();

    // Setters
    void defineNumero(std::string numero);
  
};

