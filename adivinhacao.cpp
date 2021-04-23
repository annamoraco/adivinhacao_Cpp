#include <iostream>
using namespace std;

int main(){

    int chute;
    const int NUMEROSECRETO = 42;
    bool acertou = false;
    int tentativas = 0;

    cout << "***************************************" << endl;
    cout << "** Bem vindo ao jogo da adivinhacao! **" << endl;
    cout << "***************************************" << endl << endl; 

    while(!acertou){

        tentativas++;

        cout << "Tentativa " << tentativas << endl << endl;

        cout << "Digite um numero: " ;
        cin  >> chute ;

        acertou = chute == NUMEROSECRETO;
        bool maior = chute > NUMEROSECRETO;

        if (acertou){
            cout << "Parabens! Voce acertou o numero secreto!" << endl << endl;
        } else if (maior){
            cout << "O numero secreto eh menor." << endl << endl;
        } else {
            cout << "O numero secreto eh maior." << endl << endl;
        }
    }
    cout << "FIM DE JOGO" << endl << endl;
}