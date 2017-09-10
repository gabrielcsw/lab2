#include "player.h"

#include <cstring>
using std::string;

#include <ostream>
using std::ostream;

#include <iostream>
using std::endl;

player::player () {
    nome = " ";
    total = 0;
    parar = false;
    perdeu = false;
}

string player::getNome () {
    return nome;
}

void player::setNome (string n) {
    nome = n;
}

int player::getTotal () {
    return total;
}

void player::setTotal (int t) {
    total += t;
}

bool player::getParar () {
    return parar;
}

void player::setParar (bool p) {
    parar = p;
}

bool player::getperdeu () {
    return perdeu;
}

void player::setperdeu (bool e) {
    perdeu = e;
}

ostream& operator << (ostream &os, player &j) {

    os << "player: " << j.nome << endl;
    os << "Pontos: " << j.total << endl << endl;
    
    return os;
}

player& player::operator = (player const &j){
     nome = j.nome;
     total = j.total;
     parar = j.parar;
     perdeu = j.perdeu;

     return *this;
 }