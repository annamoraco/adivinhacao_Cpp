#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
using namespace std;

void cabecalho(){
    cout << endl << "***************************************" << endl;
    cout << "** Bem vindo ao jogo da adivinhacao! **" << endl;
    cout << "***************************************" << endl << endl; 
}

int seleciona_dificuldade(){
    cout << "Escolha o nivel de dificuldade: " << endl ;
    cout << "Facil (F) Medio (M) Dificil (D)" << endl << endl;
    
    char dificuldade;
    cin >> dificuldade;

    int numerotentativas;

    if (toupper(dificuldade) == 'F') numerotentativas = 30;
    else if (toupper(dificuldade) == 'M' ) numerotentativas = 20;
    else numerotentativas = 10;
    return numerotentativas;
}

int recebe_validachute(int tentativas, int numerotentativas){
    bool chutevalido = false;
    int chute;
    while(!chutevalido){        
        cout << "Tentativa " << tentativas << " de " << numerotentativas << endl << endl;

        cout << "Digite um numero positivo: " ;
        cin  >> chute ;
        if (chute > 0 ) chutevalido = true;
    };
    return chute;
}

bool verifica_chute(int chute, int NUMEROSECRETO, int* tentativas, int numerotentativas){
        bool acertou = chute == NUMEROSECRETO;
        bool maior = chute > NUMEROSECRETO;

        if (acertou){
            cout << "Parabens! Voce acertou o numero secreto!" << endl << endl;
            *tentativas = numerotentativas;
            return true;
        } else if (maior){
            cout << "O numero secreto eh menor." << endl << endl;
        } else {
            cout << "O numero secreto eh maior." << endl << endl;
        }
        return false;
}

void ganhou(double pontos){
        cout.precision(1);
        cout << fixed;
        cout << "Parabens, voce ganhou!" << endl ;
        cout << "Pontuacao obtida: " << pontos << endl << endl;
}

int main(){

    int chute;
    srand(time(NULL));
    const int NUMEROSECRETO = rand()%100;
    bool acertou = false;
    double pontos = 1000.0;

    cabecalho();

    int numerotentativas = seleciona_dificuldade();

    for (int tentativas = 1; tentativas <= numerotentativas; tentativas++){

        int chute = recebe_validachute(tentativas, numerotentativas);

        acertou = verifica_chute(chute, NUMEROSECRETO, &tentativas, numerotentativas);

        pontos = pontos - abs(NUMEROSECRETO-chute)/2.0;
    }
    cout << "FIM DE JOGO" << endl << endl;
    
    if (acertou){
        ganhou(pontos);
    } else {
        cout << "Voce perdeu. Tente novamente." << endl;
    }
}