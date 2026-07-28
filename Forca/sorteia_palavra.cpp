#include <vector>
#include <ctime>
#include "le_arquivo.hpp"

std::string sorteia_palavra() {
    std::vector<std::string> palavras = le_arquivo();

    srand(time(NULL));
    int indice_sorteado = rand() % palavras.size();

    std::string palavra_secreta = palavras[indice_sorteado];
    return palavra_secreta;
}