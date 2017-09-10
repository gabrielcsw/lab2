#include <iostream>
using std::cout;
using std::endl;

#include "jogo.h"

#include "funcs_print.h"

void print_inicial (){
    cout<< "Bem vindo ao jogo!"<<endl;
}


void print_pontuacao (Jogo &jogo){
    cout<<"Pontuação:"<<endl;
    cout << jogo;
}

void print_vencedor (Jogo &jogo){
    cout<<"Vencedor do jogo:"
    jogo.Mostravencedor ();
}