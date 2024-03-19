#include <iostream>
#include <vector>
#include <fstream>
#include "funcionario.h"

using namespace std;

class GerenciadorFuncionario {
private:
    vector<Funcionario*>funcionarios;
    string arquivo = "funcionarios.txt";
public:
    GerenciadorFuncionario();
    ~GerenciadorFuncionario();
    void inserir(Funcionario*);
    void listarTodos() const;
    int pesquisar(std::string) const;
    Funcionario* obterFuncionario(int indice) const;
    void remover(int);
    void carregarDados();
    void salvarDados() const;
    void limparDados();
};