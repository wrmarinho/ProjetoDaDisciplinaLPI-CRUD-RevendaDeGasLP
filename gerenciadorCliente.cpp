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

Produto* GerenciadorProduto::obterProduto(int indice) const {
    if (indice >= 0 && indice < produtos.size()) {
        return produtos[indice];
    }
    return nullptr;
}

void GerenciadorProduto::remover(int indice) {
    if (indice >= 0 && indice < produtos.size()) {
        delete produtos[indice];
        produtos.erase(produtos.begin() + indice);
    }
}

void GerenciadorProduto::exibirRelatorio() const {
    cout << "\tRelatorio de Estoque:" << std::endl;
    cout << "\tQuantidade de Produtos: " << produtos.size() << std::endl;
    float valorTotal = 0.0;
    for (const auto& produto : produtos) {
        valorTotal += produto->calcularValorTotal();
    }
    cout << "\tValor Total do Estoque: " << valorTotal << std::endl;
}

void GerenciadorProduto::carregarDados() {
    ifstream arquivoEntrada(arquivo);
    if (arquivoEntrada.is_open()) {
        string nome;
        int quantidade;
        float preco;
        while (arquivoEntrada >> nome >> quantidade >> preco) {
            inserir(new Produto(nome, quantidade, preco));
        }
        arquivoEntrada.close();
    }
}

void GerenciadorProduto::salvarDados() const {
    ofstream arquivoSaida(arquivo);
    if (arquivoSaida.is_open()) {
        for (const auto& produto : produtos) {
            arquivoSaida << produto->getNome() << " " << produto->getQuantidade() << " " << produto->calcularValorTotal() << std::endl;
        }
        arquivoSaida.close();
    }
}

void GerenciadorProduto::limparDados() {
    for (auto& produto : produtos) {
        delete produto;
    }
    produtos.clear();
}

void GerenciadorProduto::venderProduto(int indice, int quantidadeVendida) {
    Produto* produto = obterProduto(indice);
    if (produto != nullptr) {
        if (produto->getQuantidade() >= quantidadeVendida) {
            produto->setQuantidade(produto->getQuantidade() - quantidadeVendida);
            cout << "Venda realizada com sucesso." << std::endl;
        } else {
            cout << "Quantidade insuficiente em estoque para a venda." << std::endl;
        }
    } else {
        cout << "Produto nao encontrado." << std::endl;
    }
}