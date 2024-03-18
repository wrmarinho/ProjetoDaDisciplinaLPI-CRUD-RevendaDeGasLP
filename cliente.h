#pragma once
#include "pessoa.h"
#include <vector>

class Cliente : public Pessoa {
private:
    vector<Cliente*>clientes;
    string endereco; 
public:
    Cliente(string _nome, string _endereco) : Pessoa(_nome), endereco(_endereco) {}
    ~Cliente(){}
    void exibir() const override {
        Pessoa::exibir();
        cout << ", Endereco: " << endereco << endl;
    }
};
