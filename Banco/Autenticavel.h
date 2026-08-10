#pragma once
#include <string>


class Autenticavel {
	std::string senha;

public:
	Autenticavel(std::string senha);
	bool autentica(std::string) const;
};

