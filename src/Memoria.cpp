#include "Memoria.hpp"
#include <iostream>
#include <string>
#include <algorithm>
#include <time.h>

using namespace std;

Memoria::Memoria()
{
    this->rows = 4;
    this->columns = 4;
    inicializaTabuleiroSimbolos();
}

void Memoria::inicializaTabuleiroSimbolos()
{

    aux = new char *[rows]; // Criar um tabuleiro auxiliar
    for (int i = 0; i < rows; i++)
    {
        aux[i] = new char[columns];
    }

    // Array de string com todos os possiveis simbolos no tabuleiro duplicados (pares):
    string simbolos = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

    // vamos iniciar o gerador de números aleatórios
    srand(time(NULL));
    // vamos embaralhar as palavras da string
    random_shuffle(simbolos.begin(), simbolos.end());

    int k = 0;
    for (int i = 0; i < rows; ++i) // Preencher o tabuleiro com os símbolos
    {
        for (int j = 0; j < columns; ++j)
        {
            aux[i][j] = simbolos[k];
            k++;
        }
    }

    // Iniciar a pontuação zerada
    pontosJogador1 = 0;
    pontosJogador2 = 0;
}

bool Memoria::ehJogadaValida(int x, int y, int x2, int y2, char jogadorDaVez)
{
    // confere se as posições estão dentro do escopo do tabuleiro, se são posições diferentes e se estão disponíveis
    if (x < 0 || x >= rows || y < 0 || y >= columns ||
        x2 < 0 || x2 >= rows || y2 < 0 || y2 >= columns ||
        (p[x][y] != ' ') || (p[x2][y2] != ' ') ||
        (x == x2 && y == y2))
    {
        return false;
    }
    else
        return true;
}

void Memoria::validaJogada(int x, int y, int x2, int y2, char jogadorDaVez)
{
    if (!ehJogadaValida(x, y, x2, y2, jogadorDaVez))
    {
        cout << "ERRO: jogada inválida" << endl;
        return;
    }
    // Atribui ao tabuleiro real os simbolos que estão na posição (x,y) e (x1,y1) do tabuleiro auxiliar
    p[x][y] = aux[x][y];
    p[x2][y2] = aux[x2][y2];
}

bool Memoria::formamPares(int x, int y, int x2, int y2, char jogadorDaVez)
{
    // Condicional para verificar se as duas posições possuem símbolos iguais (são par um do outro)
    if (p[x][y] == p[x2][y2])
        return true;
    else
        return false;
}

void Memoria::validaPares(int x, int y, int x2, int y2, char jogadorDaVez)
{
    if (!formamPares(x, y, x2, y2, jogadorDaVez))
    { // Se o jogador não encontrou os simbolos iguais, limpa o tabuleiro e ninguem pontua
        cout << "Par não encontrado!" << endl;
        p[x][y] = ' ';
        p[x2][y2] = ' ';
        return;
    }
    // Se encontrou, os simbolos se mantêm no tabuleiro real e o jogador da vez pontua
    cout << "Par " << p[x][y] << "-" << p[x2][y2] << " encontrado!" << endl;
    if (jogadorDaVez == '1')
        pontosJogador1++;
    else if (jogadorDaVez == '2')
        pontosJogador2++;
}

int Memoria::confereGanhador()
{

    if (pontosJogador1 > pontosJogador2)
    {
        return 1; // jogador 1 ganhou
    }
    else if (pontosJogador2 > pontosJogador1)
    {
        return 2; // jogador 2 ganhou
    }
    else if (pontosJogador1 == pontosJogador2)
    {
        return 3; // empate
    }

    return 0;
}

bool Memoria::verificarFimDeJogo()
{
    // Verifica se todas as posições já foram escolhidas (não tem nenhuma vazia)
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            if (p[i][j] == ' ')
            {
                return false;
            }
        }
    }
    return true;
}