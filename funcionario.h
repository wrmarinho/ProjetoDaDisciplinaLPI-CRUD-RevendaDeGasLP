#pragma once
#include "pessoa.h"
#include <vector>
#include <iomanip>

class Funcionario : public Pessoa{
private:
    vector<Funcionario*>funcionarios;
    std::string nome;
    std::string cargo;
    int id;
    float salario;

public:
    Funcionario(string _nome, string _cargo, int _id, float _salario) : Pessoa(_nome), cargo (_cargo), id (_id), salario(_salario) {}
    ~Funcionario(){}
    void exibir() const override {
        Pessoa::exibir();
        cout << ", Cargo: " << cargo << ", Identificaçao: " << id << ", Salario: " << std::fixed << std::setprecision(3) << salario << std::endl;
    }

    string getCargo() const{
        return cargo;
    }

    int getId() const{
        return id;
    }

    float getSalario() const{
        return salario;
    };

};