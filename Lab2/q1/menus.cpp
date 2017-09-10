#include <iostream>
using std::endl;
using std::cout;
using std::cin;

#include "menus.h"

int menu_principal (int menu){
    cout<< "                  Menu Principal                   " << endl;
    cout<< endl;
    cout<<"1) Criar empresa" << endl;
    cout<<"2) Adicionar funcionários a empresa" << endl;
    cout<<"3) Listar dados e funcionários da empresa" << endl;
    cout<<"4) Aumento para funcionários" << endl;
    cout<<"5) Listar funcionários em experiência" << endl;
    cout<<"0) Sair" << endl;

    cout << "Digite a opção desejada:"
    cin >> menu;

    return menu;
}
