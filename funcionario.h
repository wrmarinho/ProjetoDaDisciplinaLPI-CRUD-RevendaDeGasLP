#include "pessoa.h"

class Funcionario : public Pessoa {
private:
    string cargo;
    float salario;
public:
    Funcionario(string _nome, string _cargo, float _salario) : Pessoa(_nome), cargo(_cargo), salario(_salario) {}
    void exibir() const override {
        Pessoa::exibir();
        cout << ", Cargo: " << cargo << ", Salario: " << salario << std::endl;
    }
};