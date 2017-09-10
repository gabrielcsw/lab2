#ifndef JOGO_H

#define JOGO_H

#include <ostream>
using std::ostream;

#include "player.h"

//criação de classe para caracterizar/inserir jogadores à partida
class Jogo {
    private:
        player *players;
        player vencedor;
        int dado1, dado2;
        int num_players;
        int objetivo;
    public:
        Jogo ();
        int getObjetivo ();
        void setObjetivo (int o);
        void Alocaplayers (int n);
        void setplayers (string n);
        void Verificaplayers (int i);
        bool Acaba ();
        void Rodada (int i);
        bool perdeu (int i);
        friend ostream& operator << (ostream &os, Jogo &j);
        void Mostravencedor ();
        void playerParou (int i);
        void ResetParou ();
        void MaisProximo ();
        ~Jogo ();
};

#endif