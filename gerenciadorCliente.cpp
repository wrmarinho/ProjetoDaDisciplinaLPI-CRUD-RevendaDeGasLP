#include "gerenciadorCliente.h"

GerenciadorCliente::GerenciadorCliente() {
    carregarDados();
}

GerenciadorCliente::~GerenciadorCliente() {
    salvarDados();
    limparDados();
}

void GerenciadorCliente::inserir(Cliente* cliente) {
    clientes.push_back(cliente);
}

void GerenciadorCliente::listarTodos() const {
    for (const auto& cliente : clientes) {
        cliente->exibir();
    }
}

int GerenciadorCliente::pesquisar(std::string nome) const {
    for (size_t i = 0; i < clientes.size(); ++i) {
        if (clientes[i]->getNome() == nome) {
            return i;
        }
    }
    return -1;
}

Cliente* GerenciadorCliente::obterCliente(int indice) const {
    if (indice >= 0 && indice < clientes.size()) {
        return clientes[indice];
    }
    return nullptr;
}

void GerenciadorCliente::remover(int indice) {
    if (indice >= 0 && indice < clientes.size()) {
        delete clientes[indice];
        clientes.erase(clientes.begin() + indice);
    }
}

/*
void GerenciadorCliente::exibirRelatorio() const {
    cout << "\tRelatorio de Clientes:" << std::endl;
    cout << "\tQuantidade de Clientes: " << clientes.size() << std::endl;
    float valorTotal = 0.0;
    for (const auto& cliente : clientes) {
        valorTotal += cliente->calcularValorTotal();
    }
    cout << "\tValor Total do Estoque: " << valorTotal << std::endl;
}

*/

void GerenciadorCliente::carregarDados() {
    ifstream arquivoEntrada(arquivo);
    if (arquivoEntrada.is_open()) {
        string nome;
        string endereco;
        while (getline(arquivoEntrada, nome)&&(getline(arquivoEntrada, endereco))) {
            inserir(new Cliente(nome, endereco));
        }
        arquivoEntrada.close();
    }
}

void GerenciadorCliente::salvarDados() const {
    ofstream arquivoSaida(arquivo);
    if (arquivoSaida.is_open()) {
        for (const auto& cliente : clientes) {
            arquivoSaida << cliente->getNome() << "\n" << cliente->getEndereco()<< std::endl;
        }
        arquivoSaida.close();
    }
}

void GerenciadorCliente::limparDados() {
    for (auto& cliente : clientes) {
        delete cliente;
    }
    clientes.clear();
}