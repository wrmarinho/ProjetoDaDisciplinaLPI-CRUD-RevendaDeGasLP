#include "pessoa.h"

class Cliente : public Pessoa {
private:
    string endereco;
public:
    Cliente(string _nome, int _idade, string _endereco) : Pessoa(_nome, _idade), endereco(_endereco) {cout << "Construido";}
    ~Cliente(){cout << "Destruido";}
    
    void exibir() const override {
        Pessoa::exibir();
        cout << ", Endereco: " << endereco << endl;
    }
};
