#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include "produto.h"
#include "estoque.h"

using namespace std;

int main() {
    EstoqueManager estoqueManager;

    int opcao;
    do {
        cout << "\n\t-----Sistema de Cadastro e Venda de Produtos-----\n\n";
        cout << "\t1. Inserir" << endl;
        cout << "\t2. Listar todos" << endl;
        cout << "\t3. Pesquisar produto" << endl;
        cout << "\t4. Venda" << endl;
        cout << "\t5. Remover" << endl;
        cout << "\t6. Exibir Relatório" << endl;
        cout << "\t7. Sair" << endl;
        cout << "\n\tEscolha uma opção: ";
        cin >> opcao;
        system("cls||cls");

        switch (opcao) {
            case 1: {
                string nome;
                int quantidade;
                float precoUnitario;
                cout << "\n\t-----Sistema de Cadastro e Venda de Produtos-----\n\n";
                cout << "\tDigite o nome do produto: ";
                cin >> nome;
                cout << "\tDigite a quantidade do produto: ";
                cin >> quantidade;
                cout << "\tDigite o preço unitário do produto: ";
                cin >> precoUnitario;
                Produto* produto = new Produto(nome, quantidade, precoUnitario);
                estoqueManager.inserir(produto);
                cout << "\n\tProduto inserido com sucesso!" << endl;
                cout << "\n\tDigite enter para voltar ao menu.";
                char menu;
                scanf("%*c");
                scanf("%c", &menu);
                if(menu == '\n'){
                    system("cls");
                }
                break;
            }
            case 2:
                cout << "\n\t-----Sistema de Cadastro e Venda de Produtos-----\n\n";
                estoqueManager.listarTodos();
                cout << "\n\tDigite enter para voltar ao menu.";
                char menu;
                scanf("%*c");
                scanf("%c", &menu);
                if(menu == '\n'){
                    system("cls");
                }
                break;
            case 3: {
                string nome;
                cout << "\n\t-----Sistema de Cadastro e Venda de Produtos-----\n\n";
                cout << "\tDigite o nome do produto: ";
                cin >> nome;
                system("cls||cls");
                cout << "\n\t-----Sistema de Cadastro e Venda de Produtos-----\n\n";    
                Produto* produto = estoqueManager.pesquisar(nome);
                if (produto != nullptr) {
                    produto->exibirInformacoes();
                    cout << "\n\tDigite enter para voltar ao menu.";
                    char menu;
                    scanf("%*c");
                    scanf("%c", &menu);
                    if(menu == '\n'){
                        system("cls");
                }
                } else {
                    cout << "\tProduto não encontrado!" << endl;
                }
                break;
            }
            case 4: {
                string nome;
                int quantidade;
                cout << "\n\t-----Sistema de Cadastro e Venda de Produtos-----\n\n";
                cout << "\tDigite o nome do produto: ";
                cin >> nome;
                cout << "\tDigite a quantidade a ser vendida: ";
                cin >> quantidade;
                estoqueManager.vender(nome, quantidade);
                cout << "\n\tDigite enter para voltar ao menu.";
                char menu;
                scanf("%*c");
                scanf("%c", &menu);
                if(menu == '\n'){
                    system("cls");
                }
                break;
            }
            case 5: {
                string nome;
                cout << "\n\t-----Sistema de Cadastro e Venda de Produtos-----\n\n";
                cout << "\tDigite o nome do produto a ser removido: ";
                cin >> nome;
                estoqueManager.remover(nome);
                cout << "\n\tDigite enter para voltar ao menu.";
                char menu;
                scanf("%*c");
                scanf("%c", &menu);
                if(menu == '\n'){
                    system("cls");
                }
                break;
            }
            case 6: {
                cout << "\n\t-----Sistema de Cadastro e Venda de Produtos-----\n\n";
                estoqueManager.exibirRelatorio();
                cout << "\n\tDigite enter para voltar ao menu.";
                char menu;
                scanf("%*c");
                scanf("%c", &menu);
                if(menu == '\n'){
                    system("cls");
                }
                break;
            }
            case 7:
                cout << "\tSaindo do programa..." << endl;
                break;
            default:
                cout << "\tOpção inválida!" << endl;
            
        }
    } while (opcao != 7);

    return 0;
}