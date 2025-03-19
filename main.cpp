#include <iostream>
#include <fstream>
#include "include/GrafoLista.h"
#include "include/GrafoMatriz.h"
#include <string>

using namespace std;

// Comunicação com terminal
int main(int argc, char *argv[]) {
    // comando inválido fornecido no terminal
    if (argc != 4)
    {
        cout << "Erro na quantidade de argumentos" << "\n";
        return 1;
    }

    string opcao = argv[1];
    //cout << "Valor armazenado em opcao: " << opcao << endl;
    string estrutura = argv[2];
    //cout << "Valor armazenado em estrutura: " << estrutura << endl;
    string arquivoGrafo;

    // Validação dos argumentos
    if (opcao != "-p")
    {
        cout << "Erro: opção inválida" << "\n";
        return 1;
    }

    if (estrutura != "-l" && estrutura != "-m")
    {
        cout << "Erro: Estrutura inválida" << "\n";
        return 1;
    }

    if (opcao == "-p")
    {
        if (argc != 4)
        {
            cout << "Erro: -p requer 4 argumentos" << "\n";
            return 1;
        }
        arquivoGrafo = argv[3];
        if (estrutura == "-m")
        {
            GrafoMatriz g;
            cout << arquivoGrafo << endl << endl;
            g.carrega_grafo(arquivoGrafo);
            cout<<"Problema de subconjunto independente maximo"<<endl;
            cout<< "Grafo carregado como matriz" << endl;
        }
        else
        {
            GrafoLista g;
            cout << arquivoGrafo << endl << endl;
            g.carrega_grafo(arquivoGrafo);
            cout<<"Problema de subconjunto independente maximo"<<endl;
            cout<< "Grafo carregado como lista" << endl;
        }
    }
    else
    {
        cout << "Erro inesperado";
        return 1;
    }

    return 0;
}
