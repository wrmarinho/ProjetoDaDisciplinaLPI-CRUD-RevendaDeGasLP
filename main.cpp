#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <Windows.h>
#include "produto.h"
#include "gerenciadorProduto.h"
#include "gerenciadorCliente.h"
#include "pessoa.h"
#include "cliente.h"
#include "funcionario.h"

using namespace std;

void LimparVolta(){
    cout << "\n\tDigite enter para voltar ao menu.";
    char menu;
    scanf("%*c");
    scanf("%c", &menu);
    if(menu == '\n'){
    system("cls");
    }
}

int main(){
    
    SetConsoleOutputCP(CP_UTF8);
    
    GerenciadorProduto gerenciador;

    int opcao;

    do {
        cout << "\n\t-----Sistema de Cadastro e Venda de Produtos-----\n\n";
        cout << "\t0. Sair\n";
        cout << "\t1. Inserir\n";
        cout << "\t2. Listar todos\n";
        cout << "\t3. Pesquisar produto\n";
        cout << "\t4. Venda\n";
        cout << "\t5. Remover\n";
        cout << "\t6. Exibir Relatorio\n";
        cout << "\t7. Cadastrar cliente\n";
        cout << "\t8. Cadastrar funcionário\n";
        cout << "\n\tEscolha uma opcao: ";
        cin >> opcao;
        system("cls");

        switch (opcao) {
            case 0:
                return 0;
            case 1: {
                string nome;
                int quantidade;
                float preco;
                cout << "\n\t-----Sistema de Cadastro e Venda de Produtos-----\n\n";
                cout << "\tDigite o nome do produto: ";
                cin >> nome;
                cout << "\tDigite a quantidade: ";
                cin >> quantidade;
                cout << "\tDigite o preco: ";
                cin >> preco;
                gerenciador.inserir(new Produto(nome, quantidade, preco));
                cout << "\n\tProduto inserido com sucesso!" << endl;
                LimparVolta();
                break;
            }
            case 2: {
                cout << "\n\t-----Sistema de Cadastro e Venda de Produtos-----\n\n";
                gerenciador.listarTodos();
                LimparVolta();
                break;
            }
            case 3: {
                cout << "\n\t-----Sistema de Cadastro e Venda de Produtos-----\n\n";
                string nome;
                cout << "\tDigite o nome do produto: ";
                cin >> nome;
                int indice = gerenciador.pesquisar(nome);
                if (indice != -1) {
                    gerenciador.obterProduto(indice)->exibir();
                } else {
                    cout << "\tProduto nao encontrado." << endl;
                }
                LimparVolta();
                break;
            }
            case 4: {
                cout << "\n\t-----Sistema de Cadastro e Venda de Produtos-----\n\n";
                string nome;
                cout << "\tDigite o nome do produto a ser vendido: ";
                cin >> nome;
                int indice = gerenciador.pesquisar(nome);
                if (indice != -1) {
                    int quantidadeVendida;
                    cout << "\tDigite a quantidade a ser vendida: ";
                    cin >> quantidadeVendida;
                    gerenciador.venderProduto(indice, quantidadeVendida);
                } else {
                    cout << "\tProduto nao encontrado." << endl;
                }
                LimparVolta();
                break;
            }
            case 5: {
                cout << "\n\t-----Sistema de Cadastro e Venda de Produtos-----\n\n";
                string nome;
                cout << "\tDigite o nome do produto a ser removido: ";
                cin >> nome;
                int indice = gerenciador.pesquisar(nome);
                if (indice != -1) {
                    gerenciador.remover(indice);
                    cout << "\tProduto removido com sucesso." << endl;
                } else {
                    cout << "\tProduto nao encontrado." << endl;
                }
                LimparVolta();
                break;
            }
            case 6: {
                cout << "\n\t-----Sistema de Cadastro e Venda de Produtos-----\n\n";
                gerenciador.exibirRelatorio();
                LimparVolta();
                break;
            }

            case 7: {
                cout << "\n\t-----Sistema de Cadastro e Venda de Produtos-----\n\n";
                cout << "\n\t-----Cadastrar cliente-----\n\n";
                string nome;
                string endereco;
                cout << "\tDigite o nome do cliente: ";
                cin >> nome;
                cout << "\tDigite o endereço do cliente: ";
                cin >> endereco;
                Pessoa* cliente = new Cliente(nome, endereco);
                //cliente->exibir();
                //delete cliente;
                LimparVolta();
                break;
            }

            case 8: {
                cout << "\n\t-----Sistema de Cadastro e Venda de Produtos-----\n\n";
                cout << "\timplantar";
                LimparVolta();
                break;
            }
            default: {
                cout << "\n\t-----Sistema de Cadastro e Venda de Produtos-----\n\n";
                cout << "\tOpcao invalida." << endl;
                LimparVolta();
            }
        }
            
    } while (opcao != 0);

    return 0;
}