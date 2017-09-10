#ifndef FUNCIONARIO_H
#define FUNCIONARIO_H

#include <string>
using std::string;

#include <ostream>
using std::ostream;

/* criando classe funcionario contendo todos os dados*/
class Funcionario{
    private:
        string nome;
        float salario;
        int dia;
        int mes;
        int ano;
    public:
        Funcionario ();
        Funcionario (string n, float s, int d, int m, int a);
        string getNome ();
        void setNome (string n);
        float getSalario ();
        void setSalario (float s);
        int getDia ();
        void setDia (int d);
        int getMes ();
        void setMes (int m);
        int getAno ();
        void setAno (int a);
        friend ostream& operator << (ostream &os, Funcionario &f);
        bool operator == (Funcionario f);
        bool Experiencia (int d, int m, int a);
};

#endif
