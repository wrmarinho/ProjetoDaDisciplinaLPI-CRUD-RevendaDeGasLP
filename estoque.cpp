#include "estoque.h"

EstoqueManager::EstoqueManager() {
    carregarDoArquivo();
}

EstoqueManager::~EstoqueManager() {
    salvarNoArquivo();
    for (Produto* produto : estoque) {
        delete produto;
    }
}

void EstoqueManager::inserir(Produto* produto) {
    estoque.push_back(produto);
}

void EstoqueManager::listarTodos() {
    for (Produto* produto : estoque) {
        produto->exibirInformacoes();
        cout << endl;
    }
}

Produto* EstoqueManager::pesquisar(string nome) {
    for (Produto* produto : estoque) {
        if (produto->getNome() == nome) {
            return produto;
        }
    }
    return nullptr;
}

void EstoqueManager::vender(string nome, int quantidade) {
    Produto* produto = pesquisar(nome);
    if (produto != nullptr && produto->getQuantidade() >= quantidade) {
        produto->setQuantidade(produto->getQuantidade() - quantidade);
        cout << "\n\tVenda realizada com sucesso!" << endl;
    } else {
        cout << "\tProduto não encontrado ou quantidade insuficiente!" << endl;
    }
}

void EstoqueManager::remover(string nome) {
    for (auto it = estoque.begin(); it != estoque.end(); ++it) {
        if ((*it)->getNome() == nome) {
            delete *it;
            estoque.erase(it);
                cout << "\tProduto removido com sucesso!" << endl;
                return;
            }
        }
        cout << "\tProduto não encontrado!" << endl;
    }

void EstoqueManager::exibirRelatorio() {
    int totalProdutos = estoque.size();
    float valorTotal = 0.0;
    for (Produto* produto : estoque) {
        valorTotal += produto->calcularTotal();
    }
    cout << "\tRelatório de Estoque:\n\n";
    cout << "\tTotal de produtos cadastrados: " << totalProdutos << endl;
    cout << "\tValor total em estoque: R$ " << valorTotal << endl;
}