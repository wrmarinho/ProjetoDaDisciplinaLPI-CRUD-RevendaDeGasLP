#pragma once
#include <iostream>

using namespace std;

class Pessoa {
protected:
    string nome;
public:
    Pessoa(string _nome) : nome(_nome) {}
    virtual ~Pessoa() {}
    virtual void exibir() const {
        cout << "\tNome: " << nome;
    }
    string getNome() const { 
    return nome;
    }
};