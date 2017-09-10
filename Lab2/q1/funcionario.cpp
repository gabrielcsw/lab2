#include <iostream>
using std::endl;
using std::cout;

#include <ostream>
using std::ostream;

#include "funcionario.h"

Funcionario::Funcionario(){
    nome = " ";
    salario = 0;
    dia = 0;
    mes = 0;
    ano = 0;
}

Funcionario::Funcionario(string n, float s, int d, int m, int a){
    nome = n;
    salario = s;
    dia = d;
    mes = m;
    ano = a;
}

string Funcionario::getNome(){
    return nome;
}

void Funcionario::setNome(string n){
    nome = n;
}

float Funcionario::getSalario(){
    return salario;
}

void Funcionario::setSalario(float s){
    salario = s;
}

int Funcionario::getDia(){
    return dia;
}

void Funcionario::setDia(int d){
    dia = d;
}

int Funcionario::getMes(){
    return mes;
}

void Funcionario::setMes(int m){
    mes = m;
}

int Funcionario::getAno(){
    return ano;
}

void Funcionario::setAno(int a){
    ano = a;
}

ostream &operator<<(ostream &os, Funcionario &f){
    os << "Nome: " << f.nome << endl;
    os << "Salario: R$ " << f.salario << endl;
    os << "Data de admissao: " << f.dia << "/" << f.mes << "/" << f.ano << endl << endl;

    return os;
}

bool Funcionario::Experiencia(int d, int m, int a){

    int dias_mes[12] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

    int aux = dia + (mes * dias_mes[mes - 1]) + (ano * 365);
    int aux2 = d + (m * dias_mes[m - 1]) + (a * 365);

    if (aux2 - aux < 90)
        return true;

    return false;
}

bool Funcionario::operator==(Funcionario const f){
    if (nome == f.nome && salario == f.salario && dia == f.dia && mes == f.mes && ano == f.ano)
        return true;
    return false;
}
