#include <iostream>
using std::cout;
using std::cin;
using std::endl;

#include "jogo.h"

#include "func_rodada.h"


void rodadas (Jogo &jogo, int num_players){
    bool fim = false;
    
    int parar = 0;

    int num_rodada = 1;

    while (fim == false){
        jogo.ResetParou ();

        cout << endl;
        cout << "Rodada " << num_rodada << endl;

        for (int i = 0; i < num_players; i++){
            if (jogo.perdeu (i) != true){
                int op;

                cout << endl;
                cout << "player " << i+1 << " deseja: " << endl;
                cout << "1) Jogar" << endl;
                cout << "2) Parar" << endl << endl;
                cout << "--> ";
                cin >> op;

                if(op == 2){
                    jogo.playerParou (i);

                    parar ++;
                }else{
                    jogo.Rodada (i);

                    jogo.Verificaplayers (i);

                    fim = jogo.Acaba ();
                }
            }
        }

        if (parar == num_players){
            jogo.MaisProximo ();

            break;
        }
        
        parar = 0;

        num_rodada++;
    }
}