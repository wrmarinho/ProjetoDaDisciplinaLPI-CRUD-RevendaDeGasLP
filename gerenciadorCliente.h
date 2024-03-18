#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
#include "cliente.h"

class GerenciadorCliente {
private:
    vector<Cliente*> clientes;
    string arquivo = "clientes.txt";
public:
    GerenciadorCliente();
    ~GerenciadorCliente();
    void inserir(Cliente*);
    void listarTodos() const ;
    int pesquisar(std::string) const;
    Cliente* obterCliente(int indice) const;
    void remover(int) ;
    void exibirRelatorio() const;
    void carregarDados();
    void salvarDados() const;
    void limparDados();
    void venderProduto(int , int );

};