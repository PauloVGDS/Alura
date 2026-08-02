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
    Titular titular("Paulo Vinicius", Cpf("123.456.789-10"));

    Conta umaConta("123456", titular);

    umaConta.depositar(2000);

    umaConta.depositar(1000);

    cout << umaConta.recuperaSaldo() << endl;

    umaConta.sacar(1000);

    cout << umaConta.recuperaSaldo() << endl;
    cout << "Numero: " << umaConta.recuperaNumero() << endl;

    cout << "Quantidade de Contas: " << Conta::numeroDeContas << endl;
    return 0;
}
