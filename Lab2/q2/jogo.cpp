#include <iostream>
using std::endl;
using std::cout;

#include <ostream>
using std::ostream;

#include <ctime>
using std::time;

#include <cstdlib>
using std::srand;

#include "jogo.h"

#define MAX_DADO 6

Jogo::Jogo () {
    players = NULL;
    dado1 = 0;
    dado2 = 0;
    num_players = 0;
    objetivo = 0;
}

int Jogo::getObjetivo () {
    return objetivo;
}

void Jogo::setObjetivo (int o) {
    objetivo = o;
}

void Jogo::Alocaplayers (int n) {

    delete [] players;

    players = new player [n];
}

void Jogo::setplayers (string n) {
    players[num_players].setNome (n);

    num_players += 1;
}

ostream& operator << (ostream &os, Jogo &j) {
    
    os << endl;
    os << "******************************************************" << endl;
    os << "              Objetivo do jogo: " << j.objetivo << endl << endl;; 

    for (int i = 0; i < j.num_players; i++)
    {
        os << j.players[i];
    }

    os << "******************************************************" << endl << endl;
    return os;
}

void Jogo::Verificaplayers (int i) {

    if (players[i].getTotal () > objetivo)
    {
        players[i].setperdeu (true);

        cout << endl;
        cout << "player " << i+1 << ": " << players[i].getNome () << endl;
        cout << "perdeu POR ULTRAPASSAR A PONTUAÇÃO OBJETIVO!!!" << endl;
    }
}

bool Jogo::Acaba () {
    
    int cont = 0;

    for (int i = 0; i < num_players; i++){
        if (player[i].getTotal () == objetivo){
            vencedor = players[i];
            return true;
        }   
        if (player[i].getperdeu () == true){
            cont++;
        }
    }

    if (cont >= num_players-1){
        for (int i = 0; i < num_players; i++){
            if (players[i].getperdeu () == false){
                vencedor = players[i];
            }

        return true;
        }
    }

    return false;
}

void Jogo::Rodada (int i){

    srand(time(NULL));

    dado1 = rand() % MAX_DADO + 1;
    dado2 = rand() % MAX_DADO + 1;

    cout << endl;
    cout << "Valor dado 1: " << dado1 << endl;
    cout << "Valor dado 2: " << dado2 << endl;

    int aux = dado1 + dado2;

    players[i].setTotal (aux);
}

bool Jogo::perdeu (int i) {
    return players[i].getperdeu ();
}

void Jogo::playerParou (int i) {
    players[i].setParar (true);
}

void Jogo::ResetParou () {
    for (int i = 0; i < num_players; i++)
        players[i].setParar (false);
}

void Jogo::MaisProximo () {

    vencedor = players[0];

    for (int i = 0; i < num_players; i++){
        if (vencedor.getTotal () < players[i].getTotal () &&  players[i].getTotal () < objetivo){
            vencedor = players[i];
        }
    }    
}

void Jogo::Mostravencedor () {
    cout << vencedor;
}

Jogo::~Jogo () {
    if (num_players > 0){
        delete [] players;
    }
}