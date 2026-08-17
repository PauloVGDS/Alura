#include <iostream>
#include <string>
#include "Conta.h"
#include "Titular.h"
#include "Cpf.h"
#include "Funcionario.h"
#include "ContaPoupanca.h"
#include "ContaCorrente.h"

using namespace std;

void exibeSaldo(const Conta& conta) {
    cout << "Saldo da Conta: " << conta.recuperaSaldo() << endl;
}

void RealizaSaque(Conta& conta) {
    conta.sacar(200);
}

void RealizaDeposito(Conta& conta) {
    conta.depositar(200);
}

void fazLogin(Autenticavel& alguem, std::string senha) {
    if (alguem.autentica(senha)) {
        std::cout << "Login realizado!" << std::endl;
        return;
    }
    std::cout << "Senha Incorreta!" << std::endl;

}

int main()
{


    ContaPoupanca umaConta("123456", Titular("Paulo Vinicius", Cpf("123.456.789-10"), "umaSenha"));
    ContaCorrente otaConta("654321", Titular("Vinicius Paulo", Cpf("987.654.321-10"), "otaSenha"));

    umaConta.depositar(2000.0f);
    otaConta.depositar(2000.0f);

    RealizaSaque(umaConta);
    RealizaSaque(otaConta);
    cout << "Saldo 1: " << umaConta.recuperaSaldo() << endl;
    cout << "Saldo 2: " << otaConta.recuperaSaldo() << endl;
    cout << endl; cout << endl;

    umaConta.transferePara(otaConta, 500);
    cout << "Saldo 1: " << umaConta.recuperaSaldo() << endl;
    cout << "Saldo 2: " << otaConta.recuperaSaldo() << endl;

    cout << "Quantidade de Contas: " << Conta::numeroDeContas << endl;

    

    
    
    return 0;
}
