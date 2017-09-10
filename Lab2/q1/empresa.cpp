#include "funcionario.h"

#include <iostream>
using std::cout;
using std::endl;

#include <ostream>
using std::ostream;

#include <fstream>
using std::ofstream;

#include <string>
using std::string;

#include "empresa.h"

Empresa::Empresa () {
    nome = " ";
    cnpj = 0;
    empregados = NULL;
    num_empregados = 0;
}

string Empresa::getNomeEmpresa () {
    return nome;
}

void Empresa::setNomeEmpresa (string n){
    nome = n;
}

long int Empresa::getCnpj () {
    return cnpj;
}

void Empresa::setCnpj (long int c) {
    cnpj = c;
}

int Empresa::getNumEmpregados () {
    return num_empregados;
}

void Empresa::setNovoFuncionario (int n) {

    if (num_empregados > 0){
        Funcionario *empregados_temp = new Funcionario [num_empregados];

        for (int jj = 0; jj < num_empregados; jj++){
            empregados_temp [jj].setNome (empregados[jj].getNome ());
            empregados_temp [jj].setSalario (empregados[jj].getSalario ());
            empregados_temp [jj].setDia (empregados[jj].getDia ());
            empregados_temp [jj].setMes (empregados[jj].getMes ());
            empregados_temp [jj].setAno (empregados[jj].getAno ());
        }

        delete [] empregados;

        empregados = new Funcionario [n];

        for (int jj = 0; jj < num_empregados; jj++){
            empregados [jj].setNome (empregados_temp[jj].getNome ());
            empregados [jj].setSalario (empregados_temp[jj].getSalario ());
            empregados [jj].setDia (empregados_temp[jj].getDia ());
            empregados [jj].setMes (empregados_temp[jj].getMes ());
            empregados [jj].setAno (empregados_temp[jj].getAno ());
        }

        delete [] empregados_temp;
    }else{
        delete [] empregados;

        empregados = new Funcionario [n];
    }

    num_empregados = n;
}

void Empresa::setEmpregados (string n, float s, int d, int m, int a) {

    if (ExisteFuncionario (n, s, d, m, a) == true){
        cout << "Funcionario já cadastrado !!!" << endl;

        return;
    }else{
        int aux = num_empregados + 1;
        int temp = num_empregados;

        Empresa::setNovoFuncionario (aux);

        empregados[temp].setNome (n);
        empregados[temp].setSalario (s);
        empregados[temp].setDia (d);
        empregados[temp].setMes (m);
        empregados[temp].setAno (a);
    }
}

ostream& operator << (ostream &os, Empresa &e) {

    os << "Dados da Empresa: " << endl;
    os << "Nome: " << e.nome << endl;
    os << "CNPJ: " << e.cnpj << endl << endl;

    os << "Lista de funcionários:" << endl << endl;

    for (int ii = 0; ii < e.num_empregados; ii++){
        os << e.empregados[ii];
    }

    return os;
}

void Empresa::setAumento (int p){

    double aux = (double) p / (double) 100;

    for (int ii = 0; ii < num_empregados; ii++){
        float temp = empregados[ii].getSalario ();
        float novo_salario = (temp * aux) + temp;

        empregados[ii].setSalario (novo_salario);
    }
}

void Empresa::FuncionarioExperiencia (int d, int m, int a) {

    int cont = 0;

    for (int ii = 0; ii < num_empregados; ii++)
    {
        if (empregados[ii].Experiencia (d, m, a) == true)
            cout << empregados[ii];
        else
            cont += 1;
    }

    if (cont == num_empregados)
        cout << "Nenhum funcionario em tempo de experiencia !!!" << endl;
}

bool Empresa::ExisteFuncionario (string n, float s, int d, int m, int a) {

    Funcionario temp (n, s, d, m, a);

    for (int jj = 0; jj < num_empregados; jj++){
        if (temp == empregados[jj])
            return true;
    }
    return false;
}

Empresa& Empresa::operator = (Empresa const &e) {

    nome = e.nome;
    cnpj = e.cnpj;

    for (int ii = 0; ii < e.num_empregados; ii++)
    {
        Empresa::setEmpregados (e.empregados[ii].getNome (), e.empregados[ii].getSalario (), e.empregados[ii].getDia (), e.empregados[ii].getMes (), e.empregados[ii].getAno ());
    }

    return *this;
}

Empresa::~Empresa () {
    if (num_empregados > 0)
        delete [] empregados;
}
