#include <iostream>

using std::cout;
using std::cin;
using std::endl;

#include <string>

using std::string;

#include "jogo.h"
#include "funcs_print.h"
#include "func_rodada.h"

int main (){
    int obj;
    cout<<"Informe o valor do objetivo do jogo!"<<endl;
    cin>>obj;

    print_inicial ();

    Jogo jogo;

    jogo.setObjetivo(obj);

    int num_players;

    do{
        cout << "Informe a quantidade de players: " << endl;
        cin >> num_players;
        if (num_players < 2){
            cout << endl << "A partida deve ter no minimo dois players !"<< endl;
        }
    }while (num_players < 2);

    jogo.Alocaplayers (num_players);

    string nome_player;

    cout << endl;

    for (int i = 1; i <= num_players; i++){
        cout << "Digite o nome do player " << i << ": ";
        getline (cin, nome_player);
        jogo.setplayers (nome_player);
    }

    rodadas (jogo, num_players);

    print_pontuacao (jogo);

    print_vencedor (jogo);

    return 0;
}
