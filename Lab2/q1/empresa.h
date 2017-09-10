#ifndef EMPRESA_H
#define EMPRESA_H

#include "funcionario.h"

#include <string>
using std::string;

#include <ostream>
using std::ostream;


class Empresa {
    private:
        string nome;
        long int cnpj;
        Funcionario *empregados;
        int num_empregados;
    public:
        Empresa ();
        string getNomeEmpresa ();
        void setNomeEmpresa (string n);
        long int getCnpj ();
        void setCnpj (long int c);
        int getNumEmpregados ();
        void setNovoFuncionario (int n);
        void setEmpregados (string n, float s, int d, int m, int a);
        friend ostream& operator << (ostream &os, Empresa &e);
        void setAumento (int p);
        void FuncionarioExperiencia (int d, int m, int a);
        bool ExisteFuncionario (string n, float s, int d, int m, int a);
        Empresa& operator = (Empresa const &e);
        ~Empresa ();
};

#endif
