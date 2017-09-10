#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <string>
using std::string;

#include <fstream>
using std::ifstream;

#include <cstdlib>
using std::atoi;
using std::atof;

#include <ctime>

#include "empresa.h"
#include "menus.h"
#include "funcs_dados.h"

int busca_empresa (Empresa *emp, int num_empresa) {
    int numemp;
    long int cnpjemp;

    cout<<"Digite o CNPJ da empresa: ";
    cin>>cnpjemp;

    int i;
    for(i = 0; i < num_empresa; i++){
        if(emp[i].getCnpj () == cnpjemp){
            numemp = i;
            break;
        }
    }
    if(i == num_empresa){
        cout << "Empresa não cadastrada !!!" << endl;
        return -1;
    }
    return numemp;
}

Empresa* nova_empresa(Empresa *emp, int *num_empresa){
    int temp = *num_empresa;
    *num_empresa += 1;

    if(temp > 0){
        Empresa *emp_temp = new Empresa [temp];

        for(int jj = 0; jj < temp; jj++){
            emp_temp [jj] = emp [jj];
        }
        delete [] emp;
        emp = new Empresa [*num_empresa];

        for (int jj = 0; jj < temp; jj++){
            emp [jj] = emp_temp [jj];
        }

        delete [] emp_temp;
    }else{
        delete [] emp;

        emp = new Empresa [*num_empresa];
    }
    return emp;
}

void cadastra_empresa (Empresa *emp, int num_empresa){
    int temp = num_empresa - 1;

    string nome;
    cout << "Digite o nome para a empresa: ";
    getline(cin, nome);

    cout << "Digite o CNPJ: ";
    long int cnpj;
    cin >> cnpj;

    emp[temp].setNomeEmpresa (nome);
    emp[temp].setCnpj (cnpj);

    cout<< "Empresa '" << emp[temp].getNomeEmpresa () << "' criada com sucesso !!!" << endl;
}

void add_funcionario (Empresa *emp, int num_empresa, struct tm *data){
    string nome_f;
    float salario;
    int dia, mes, ano;
    int qntd_add;

    int numemp = busca_empresa (emp, num_empresa);

    if(numemp == -1){
        return;
    }
            cout << "Quantos funcionarios deseja cadastrar: ";
            cin >> qntd_add;

            for (int ii = 0; ii < qntd_add; ii++) {
                cout << endl;
                cout << "Nome do Funcionario: ";
                getline(cin, nome_f);

                cout << "Salario: ";
                cin >> salario;

                dia = data->tm_mday;
                mes = data->tm_mon + 1;
                ano = data->tm_year + 1900;

                emp[numemp].setEmpregados (nome_f, salario, dia, mes, ano);
            }
            cout << "Funcionários cadastrados com sucesso !!!" << endl;
}
