#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;



int main()
{

    srand(time(NULL));
    const int NUMERO_SECRETO = rand() % 100;
    
    cout << "************************************" << endl;
    cout << "* Bem-Vindo ao jogo da adivinhação *\n" << endl;
    cout << "************************************\n" << endl;
    
    // cout << "O número e: " << NUMERO_SECRETO << endl << endl;

    int chute;
    int numero_tentativas;
    char level;
    int tentativas = 0;
    bool ganhou = false;
    double pontos = 100.0; 

    cout << "Fácil (F), Médio (M) ou Difícil (D)" << endl;
    cout << "Escolha o nível de dificuldade:";
    cin >> level;

    if (level == 'F')
    {
        numero_tentativas = 10;
    } else if (level == 'M')
    {
        numero_tentativas = 5;
    } else {
        numero_tentativas = 3;
    }
    
    

    for (tentativas = 0; tentativas < numero_tentativas; tentativas++) {
        cout << "Tentativa número " << tentativas + 1 << endl;
        cout << "Digite um número:"; cin >> chute;
        cout << "Seu chute:" << chute << endl;
    
        pontos = pontos - abs(chute - NUMERO_SECRETO) / 2.0;
    
        bool igual = (chute == NUMERO_SECRETO);
        bool maior = (chute > NUMERO_SECRETO);
        if (igual) {
            cout << "Acertoy!" << endl;
            ganhou = true;
            break;
        } else if (maior) {
            cout << "O número secreto é menor que o seu chute." << endl;
        } else {
            cout << "O número secreto é maior que o seu chute." << endl;
        }
        
    }
    cout << "Fim de jogo!" << endl;
    if (ganhou) {
        cout << "Você acertou em " << tentativas << endl;
        cout.precision(2);
        cout << fixed;
        cout << "Pontuação: " << pontos << endl;
        return 0;
    }
    cout << "Você perdeu!" << endl;
    cout << "O número secreto era: " << NUMERO_SECRETO << endl;
}

