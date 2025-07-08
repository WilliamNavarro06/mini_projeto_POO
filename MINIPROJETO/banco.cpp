#include <iostream>
#include "contaBanco.h"

using namespace std;

ContaBanco conta;

int main(){
    conta.setDono("Joao");
    conta.abrir_conta("Cp"); //Conta corrente
    conta.depositar(100);
    conta.estadoAtual();
}

