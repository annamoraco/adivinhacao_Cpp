#include <iostream>
using namespace std;

int main(){

    int chute;
    const int NUMEROSECRETO = 42;
    bool acertou = false;
    int tentativas = 0;

    double pontos = 1000.0;

    cout << endl << "***************************************" << endl;
    cout << "** Bem vindo ao jogo da adivinhacao! **" << endl;
    cout << "***************************************" << endl << endl; 

    while(!acertou){

        tentativas++;

        bool chutevalido = false;

        while(!chutevalido){
            cout << "Tentativa " << tentativas << endl << endl;

            cout << "Digite um numero positivo: " ;
            cin  >> chute ;
            if (chute > 0 ) chutevalido = true;
        };

        acertou = chute == NUMEROSECRETO;
        bool maior = chute > NUMEROSECRETO;

        if (acertou){
            cout << "Parabens! Voce acertou o numero secreto!" << endl << endl;
        } else if (maior){
            cout << "O numero secreto eh menor." << endl << endl;
        } else {
            cout << "O numero secreto eh maior." << endl << endl;
        }
        pontos = pontos - abs(NUMEROSECRETO-chute)/2.0;
    }
    cout << "FIM DE JOGO" << endl << endl;
    
    cout.precision(1);
    cout << fixed;
    cout << "Pontuacao obtida: " << pontos << endl << endl;
}