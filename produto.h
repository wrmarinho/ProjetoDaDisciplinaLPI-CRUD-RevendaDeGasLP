#pragma once
#include <iostream>

using namespace std;

class Produto {
protected:
    string nome;
    int quantidade;
    float preco;
public:
    Produto(string, int, float);
    virtual ~Produto();
    virtual float calcularValorTotal() const;
    virtual void exibir() const;
    string getNome() const;
    int getQuantidade() const;
    void setQuantidade(int);
};