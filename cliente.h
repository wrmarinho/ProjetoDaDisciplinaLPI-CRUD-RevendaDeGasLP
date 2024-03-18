<<<<<<< Updated upstream
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
=======
#include "pessoa.h"

class Cliente : public Pessoa {
private:
    vector<Pessoa*> clientes;
    string endereco;
public:
    Cliente(string _nome, string _endereco) : Pessoa(_nome), endereco(_endereco) {}
    ~Cliente(){}
    
    void exibir() const override {
        Pessoa::exibir();
        cout << ", Endereco: " << endereco << endl;
    }
};
>>>>>>> Stashed changes
