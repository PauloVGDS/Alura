#include <iostream>
#include <string>
#include "Conta.h"
#include "Titular.h"
#include "Cpf.h"

using namespace std;

void exibeSaldo(const Conta& conta) {
    cout << "Saldo da Conta: " << conta.recuperaSaldo() << endl;
}


int main()
{

    Conta umaConta("123456", Titular("Paulo Vinicius", Cpf("123.456.789-10")));

    umaConta.depositar(2000);

    cout << umaConta.recuperaSaldo() << endl;

    umaConta.sacar(750);

    cout << umaConta.recuperaSaldo() << endl;
    cout << "Numero: " << umaConta.recuperaNumero() << endl;

    cout << "Quantidade de Contas: " << Conta::numeroDeContas << endl;
    return 0;
}
