#pragma once
#include <string>

class ContaCredito {
private:
	std::string idEquipamento;
	int creditos;
	bool bloqueado;
public:
	ContaCredito(const std::string& id, int cred)
		: idEquipamento(id),
		creditos(cred < 0 ? 0 : cred),
		bloqueado(creditos == 0) {
	}

	void consumirCreditos();
	void adicionarCreditos(int quantidade);
	void exibirStatus() const;
};