#include "produto.h"

Produto::Produto(std::string _nome, int _quantidade, float _preco) : nome(_nome), quantidade(_quantidade), preco(_preco) {}

Produto::~Produto() {};
    
float Produto::calcularValorTotal() const { return quantidade * preco; }
    
void Produto::exibir() const {
    std::cout << "\tNome: " << nome << ", Quantidade: " << quantidade << ", Preco: " << preco << std::endl;
}
std::string Produto::getNome() const { return nome; }
int Produto::getQuantidade() const { return quantidade; }
void Produto::setQuantidade(int qtd) { quantidade = qtd; }