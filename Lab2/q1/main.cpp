#include <iostream>
using std::cout;
using std::endl;
using std::cin;

#include <ctime>

#include "empresa.h"
#include "menus.h"
#include "funcs_dados.h"

int main (){
    Empresa *emp = NULL;
    int num_empresa = 0;

    time_t timer;
    struct tm *data;

    time(&timer);
    data = localtime( &timer ); //recebendo a hora atual;

    int menu = -1;

    while (menu != 0) {
        menu = menu_principal (menu);

        switch(menu){
            case 1:{
            emp = nova_empresa (emp, &num_empresa);
            cadastra_empresa (emp, num_empresa);
        }
            case 2:{
            add_funcionario (emp, num_empresa, data);
        }
            case 3:{
            int numemp = busca_empresa (emp, num_empresa);
            if (numemp != -1){
                cout << endl;
                if (emp[numemp].getNumEmpregados () == 0)
                    cout << "Não existem funcionarios cadastrados nesta empresa !!!" << endl << endl;
                else {
                    cout << emp[numemp];
                }
            }
        }
            case 4:{
            int numemp = busca_empresa (emp, num_empresa);

            if (numemp != -1){
                float porcentagem;

                cout << "Deseja fazer um aumento de quanto por cento para os funcionários: ";
                cin >> porcentagem;

                emp[numemp].setAumento (porcentagem);

                cout << "Aumento realizado !!!" << endl;
            }
        }
            case 5:{
            int dia, mes, ano;

            dia = data->tm_mday;
            mes = data->tm_mon + 1;
            ano = data->tm_year + 1900;

            int numemp = busca_empresa (emp, num_empresa);

            if (numemp != -1)
            {
                emp[numemp].FuncionarioExperiencia (dia, mes, ano);
            }
        }
    }
    return 0;
}
