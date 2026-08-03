#include "ContaCredito.h"
#include <iostream>

void ContaCredito::consumirCreditos() {
	creditos--;
	if (creditos > 0) {
		bloqueado = false;
		return;
	}
	bloqueado = true;
	creditos = 0;
}

void ContaCredito::adicionarCreditos(int qnt) {
	if (qnt > 0) {
		creditos += qnt;
		if (bloqueado) {
			bloqueado = false;
		}
	}
}

void ContaCredito::exibirStatus() const {
	cout << "ID: " << idEquipamento << std::endl;
	std::cout << "Quantidade de Créditos: " << creditos << std::endl;
	std::cout << "Status de Bloqueio: " << (bloqueado ? "Bloqueado" : "Desbloqueado") << std::endl;
}