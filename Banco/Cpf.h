#pragma once
#include <string>


class Cpf {
private:
	std::string numero;
public:
	explicit Cpf(std::string num);
	void verificaCpf();
	std::string recuperaCpf();
};


