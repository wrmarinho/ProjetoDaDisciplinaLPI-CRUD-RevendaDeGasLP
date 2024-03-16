#include <iostream>
#include <vector>
#include <fstream>
using namespace std;
#include "produto.h"

class GerenciadorProduto {
private:
    vector<Produto*> produtos;
    string arquivo = "estoque.txt";
public:
    GerenciadorProduto();
    ~GerenciadorProduto();

    void inserir(Produto*);
    void listarTodos() const ;

    int pesquisar(std::string) const ;

    Produto* obterProduto(int indice) const ;

    void remover(int) ;

    void exibirRelatorio() const;
    void carregarDados() ;

    void salvarDados() const;
    void limparDados();
    void venderProduto(int , int );

};