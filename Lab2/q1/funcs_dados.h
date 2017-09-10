#ifndef FUNCS_DADOS_H
#define FUNCS_DADOS_H

#include "empresa.h"

int busca_empresa (Empresa *emp, int num_empresa);
Empresa* nova_empresa (Empresa *emp, int *num_empresa);
void cadastra_empresa (Empresa *emp, int num_empresa);
void add_funcionario (Empresa *emp, int num_empresa, struct tm *data);

#endif
