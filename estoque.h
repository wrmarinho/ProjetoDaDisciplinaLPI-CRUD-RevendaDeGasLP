#include <vector>
#include <fstream>
#include "produto.h"

class EstoqueManager {
    private:
        vector<Produto*> estoque;
    
        void salvarNoArquivo() {
            ofstream arquivo("estoque.txt");
            if (arquivo.is_open()) {
                for (Produto* produto : estoque) {
                    arquivo << produto->getNome() << ";" << produto->getQuantidade() << ";" << produto->getPrecoUnitario() << endl;
                }
                arquivo.close();
            } else {
                cerr << "Erro ao salvar o arquivo." << endl;
            }
        }
    
        void carregarDoArquivo() {
            ifstream arquivo("estoque.txt");
            if (arquivo.is_open()) {
                string nome;
                int quantidade;
                float precoUnitario;
                while (arquivo >> nome >> quantidade >> precoUnitario) {
                    estoque.push_back(new Produto(nome, quantidade, precoUnitario));
                }
                arquivo.close();
            }
        }

public:
    EstoqueManager();
    ~EstoqueManager();
    void inserir(Produto*);
    void listarTodos();
    Produto* pesquisar(string);
    void vender(string, int);
    void remover(string nome);
    void exibirRelatorio();
};