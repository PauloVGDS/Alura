#include <iostream>
#include "ContaCredito.h"

using namespace std;

int main() {
	cout << "Iniciando!" << endl;
	ContaCredito conta1("EDA775", 5);
	conta1.exibirStatus();

	conta1.consumirCreditos();
	conta1.consumirCreditos();
	conta1.consumirCreditos();
	conta1.consumirCreditos();
	conta1.consumirCreditos();
	conta1.consumirCreditos();
	conta1.consumirCreditos();
	conta1.exibirStatus();

	conta1.adicionarCreditos(0);
	conta1.exibirStatus();

	conta1.adicionarCreditos(5);
	conta1.adicionarCreditos(-50);
	conta1.exibirStatus();

	conta1.adicionarCreditos(50);
	conta1.exibirStatus();



	return 0;
}