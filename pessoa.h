#pragma once
#include <iostream>

using namespace std;

class Pessoa {
protected:
    string nome;
    int idade;
public:
    Pessoa(string _nome, int _idade) : nome(_nome), idade(_idade) {cout << "Construido";}
    virtual ~Pessoa() { cout << "Destruido";}
    virtual void exibir() const {
        cout << "Nome: " << nome << ", Idade: " << idade;
    }
};