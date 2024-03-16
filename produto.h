#pragma once
#include <iostream>

class Produto {
protected:
    std::string nome;
    int quantidade;
    float preco;
public:
    Produto(std::string, int, float);
    virtual ~Produto();
    virtual float calcularValorTotal() const;
    virtual void exibir() const;
    std::string getNome() const;
    int getQuantidade() const;
    void setQuantidade(int);
};