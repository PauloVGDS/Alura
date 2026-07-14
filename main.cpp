#include <iostream>

using namespace std;
const int NUMERO_SECRETO = 42;


int main()
{
    
    cout << "************************************" << endl;
    cout << "* Bem-Vindo ao jogo da adivinhação *\n" << endl;
    cout << "************************************\n" << endl;
    
    // cout << "O número e: " << NUMERO_SECRETO << endl << endl;

    int chute;
    int tentativas = 0;
    bool ganhou = false;
    double pontos = 100.0; 

    while (!ganhou) {
        cout << "Digite um número:"; cin >> chute;
        cout << "Seu chute:" << chute << endl;
    
        pontos = pontos - abs(chute - NUMERO_SECRETO) / 2.0;

        bool igual = (chute == NUMERO_SECRETO);
        bool maior = (chute > NUMERO_SECRETO);
        if (igual) {
            cout << "Acertoy!" << endl;
            ganhou = true;
        } else if (maior) {
            cout << "O número secreto é menor que o seu chute." << endl;
        } else {
            cout << "O número secreto é maior que o seu chute." << endl;
        }
        tentativas++;
        
    }
    cout << "Fim de jogo!" << endl;

    cout << "Você acertou em " << tentativas << endl;
    cout.precision(2);
    cout << fixed;
    cout << "Pontuação: " << pontos << endl;
}
