#include "pessoa.h"

class Cliente : public Pessoa {
private:
    string endereco;
public:
    Cliente(string _nome, string _endereco) : Pessoa(_nome), endereco(_endereco) {}
    ~Cliente(){}
    
    void exibir() const override {
        Pessoa::exibir();
        cout << ", Endereco: " << endereco << endl;
    }
};
