#include <iostream>
#include <string>
#include <map>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <ctime>

using namespace std;
string PALAVRA_SECRETA;

map<char, bool> chutou;
vector<char> chutes_errados;

bool letra_existe(char chute) {
    for (char letra: PALAVRA_SECRETA) {
        if (chute == letra) {
            cout << "Acertou o chute!" << endl;
            return true;
        }
    }
    cout << "Errou o chute!" << endl;
    chutes_errados.push_back(chute);

    return false;
}

bool nao_acertou() {
    for (char letra: PALAVRA_SECRETA) {
        if(!chutou[letra]) return true;
    }
    return false;
    
}

bool nao_enforcou() {
    return chutes_errados.size() < 5;
    
}

void imprime_cabecalho() {
    cout << "*********************" << endl;
    cout << "*** Jogo da Forca *** " << endl;
    cout << "*********************" << endl;
    cout << endl;
}

void imprime_erros() {
    if (chutes_errados.size() != 0) {
        cout << "Chutes errados: ";
        for (char letra: chutes_errados)
        {
            cout << letra << " ";
        }
        cout << endl;
    }
}

void imprime_palavra() {
        for (char letra : PALAVRA_SECRETA) {
        if (chutou[letra]) {
            cout << letra << " ";

        } else {
            cout << "_ ";
        }
    }
    cout << endl;
}

void chuta() {
    char chute;
    cout << "Seu chute:";
    cin >> chute;
    cout << endl;

    chutou[chute] = true;
    letra_existe(chute);
}

vector<string> le_arquivo() {
    ifstream arquivo;
    arquivo.open("palavras.txt");

    if (arquivo.is_open()) {
        int quantidade_palavras;
        arquivo >> quantidade_palavras;
        
        cout << "O arquivo contém " << quantidade_palavras << " palavras." << endl;
    
        vector<string> palavras_arquivo;
    
        for (int i = 0; i < quantidade_palavras; i++) {
            string palavra_lida;
            arquivo >> palavra_lida;
            palavras_arquivo.push_back(palavra_lida);
        }
        
        arquivo.close();
        return palavras_arquivo;
    } else {
        cout << "Arquivo não encontrado!" << endl;
        exit(0);
    }

}

void sorteia_palavra() {
    vector<string> palavras = le_arquivo();
    srand(time(0));
    PALAVRA_SECRETA = palavras[rand() % palavras.size()];
}

void salva_arquivo(vector<string> palavras) {
    ofstream arquivo;
    arquivo.open("palavras.txt");

    if (arquivo.is_open()) {
        arquivo << palavras.size() << endl;

        for (string palavra : palavras)
        {
            arquivo << palavra << endl;
        }
        arquivo.close();
    } else {
        cout << "Falha ao abrir arquivo!" << endl;
        exit(0);
    }
}

void adiciona_palavra() {
    cout << "Digite a nova palavra em letras maiúsculas:" << endl;
    string nova_palavra;
    cin >> nova_palavra;

    vector<string> lista_palavras = le_arquivo();
    lista_palavras.push_back(nova_palavra);

    salva_arquivo(lista_palavras);

}

int main() {
    sorteia_palavra();

    cout << PALAVRA_SECRETA << endl;
    
    imprime_cabecalho();

    while (nao_acertou() && nao_enforcou()) {

        imprime_erros();

        imprime_palavra();

        chuta();
    }

    cout << "Fim de jogo!" << endl;
    cout << "A palavra secreta era: " << PALAVRA_SECRETA << endl;

    if (nao_acertou()) {
        cout << "Tente novamente!" << endl;
        return 1;
    }
    cout << "Parabéns, você ganhou!" << endl;

    cout << "Deseja adicionar uma palavra nova?" << "(S/N) ";
    char resposta;
    cin >> resposta;
    if (resposta == 'S') {
        adiciona_palavra();
    }
    return 0;
}