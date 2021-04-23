#include <iostream>
using namespace std;

int main(){

    int chute;
    const int NUMEROSECRETO = 42;
    bool acertou = false;

    double pontos = 1000.0;

    cout << endl << "***************************************" << endl;
    cout << "** Bem vindo ao jogo da adivinhacao! **" << endl;
    cout << "***************************************" << endl << endl; 

    cout << "Escolha o nivel de dificuldade: " << endl ;
    cout << "Facil (F) Medio (M) Dificil (D)" << endl << endl;
    
    char dificuldade;
    cin >> dificuldade;

    int numerotentativas;

    if (dificuldade == 'F') numerotentativas = 30;
    else if (dificuldade == 'M' ) numerotentativas = 20;
    else numerotentativas = 10;

    for (int tentativas = 1; tentativas <= numerotentativas; tentativas++){

        bool chutevalido = false;

        while(!chutevalido){
            cout << "Tentativa " << tentativas << " de " << numerotentativas << endl << endl;

            cout << "Digite um numero positivo: " ;
            cin  >> chute ;
            if (chute > 0 ) chutevalido = true;
        };

        acertou = chute == NUMEROSECRETO;
        bool maior = chute > NUMEROSECRETO;

        if (acertou){
            cout << "Parabens! Voce acertou o numero secreto!" << endl << endl;
            break;
        } else if (maior){
            cout << "O numero secreto eh menor." << endl << endl;
        } else {
            cout << "O numero secreto eh maior." << endl << endl;
        }
        pontos = pontos - abs(NUMEROSECRETO-chute)/2.0;
    }
    cout << "FIM DE JOGO" << endl << endl;
    
    if (acertou){
        cout.precision(1);
        cout << fixed;
        cout << "Parabens, voce ganhou!" << endl ;
        cout << "Pontuacao obtida: " << pontos << endl << endl;
    } else {
        cout << "Voce perdeu. Tente novamente." << endl;
    }
}