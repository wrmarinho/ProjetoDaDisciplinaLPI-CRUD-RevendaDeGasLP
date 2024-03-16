#pragma once
#include <iostream>
using namespace std;

class Produto {
protected:
    string nome;
    int quantidade;
    float precoUnitario;
public:
    Produto(string, int, float);
    virtual void exibirInformacoes();
    virtual float calcularTotal();
    string getNome();
    int getQuantidade();
    float getPrecoUnitario();
    void setQuantidade(int);
};