#include "gerenciadoFuncionario.h"

GerenciadorFuncionario::GerenciadorFuncionario(){
    carregarDados();
}

GerenciadorFuncionario::~GerenciadorFuncionario(){
    salvarDados();
    limparDados();
}

void GerenciadorFuncionario::inserir(Funcionario* func){
    funcionarios.push_back(func);
}

void GerenciadorFuncionario::listarTodos() const{
    for(const auto& func : funcionarios){
        func->exibir();
    }
}

int GerenciadorFuncionario::pesquisar(std::string nome) const {
    for(size_t i=0; i<funcionarios.size(); ++i){
        if(funcionarios[i]->getNome() == nome){
            return i;
        }
    }

    return -1;
}

Funcionario* GerenciadorFuncionario::obterFuncionario(int indice) const{
    if(indice >= 0 && indice < funcionarios.size()){
        return funcionarios[indice];
    }
    return nullptr;
}

void GerenciadorFuncionario::remover(int indice){
    if(indice >= 0 && indice < funcionarios.size()){
        delete funcionarios[indice];
        funcionarios.erase(funcionarios.begin() + indice);
    }
}

void GerenciadorFuncionario::carregarDados(){
    ifstream arquivoEntrada(arquivo);
    if(arquivoEntrada.is_open()){
        string nome;
        string cargo;
        int id;
        float salario;
        while(arquivoEntrada >> nome >> cargo >> id >> salario){
            inserir(new Funcionario(nome, cargo, id, salario));
        }
        arquivoEntrada.close();
    }
}

void GerenciadorFuncionario::salvarDados() const{
    ofstream arquivoSaida (arquivo);
    if(arquivoSaida.is_open()){
        for(const auto& func : funcionarios) {
            arquivoSaida << func->getNome() << " " << func->getCargo() << func->getId() << func->getSalario() << std::endl;
        }
        arquivoSaida.close();
    }
}

void GerenciadorFuncionario::limparDados(){
    for(auto& func : funcionarios){
        delete func;
    }
    funcionarios.clear();
}