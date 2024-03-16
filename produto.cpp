#include "produto.h"

Produto::Produto(string _nome, int _quantidade, float _precoUnitario)
        : nome(_nome), quantidade(_quantidade), precoUnitario(_precoUnitario) {}

void Produto::exibirInformacoes() {
    cout << "\tNome: " << nome << endl;
    cout << "\tQuantidade: " << quantidade << endl;
    cout << "\tPreço Unitário: " << precoUnitario << endl;
}

float Produto::calcularTotal() {
    return quantidade * precoUnitario;
}

string Produto::getNome() {
    return nome;
}

int Produto::getQuantidade() {
    return quantidade;
}

float Produto::getPrecoUnitario() {
    return precoUnitario;
}

void Produto::setQuantidade(int _quantidade) {
    quantidade = _quantidade;
}