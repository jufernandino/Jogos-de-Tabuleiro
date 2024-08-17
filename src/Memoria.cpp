#include "Memoria.hpp"
#include <iostream>
#include <string>
#include <algorithm>
#include <time.h>

using namespace std;
/**
 * @brief Construtor da classe Memoria.
 *
 * Inicializa o tabuleiro do jogo Memoria com 4 linhas e 4 colunas.
 * Além disso, inicializa uma matriz auxiliar para guardar os caracteres/simbolos dessa partida
 */
Memoria::Memoria()
{
    this->rows = 4;
    this->columns = 4;
    inicializaTabuleiroSimbolos();
}

void Memoria::inicializaTabuleiroSimbolos()
{

    // aux = new char *[rows]; // Criar um tabuleiro auxiliar
    // for (int i = 0; i < rows; i++)
    // {
    //     aux[i] = new char[columns];
    // }

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

/**
 * @brief Verifica se a jogada é valida de acordo com as regras do jogo da Memória .
 *
 * Verifica se as posições `(x, y)` e `(x2, y2)` estão vazias, dentro das
 * dimensões do tabuleiro e se são coordenadas diferentes entre si.
 * Caso as posições tenham todos os pré-requisitos, a jogada é considerada válida, retornando verdadeiro.
 * Caso contrário, a jogada é considerada inválida e retorna falso.
 *
 * @param x Linha da coordenada1.
 * @param y Coluna da coordenada1.
 * @param x2 Linha da coordenada2.
 * @param y2 Coluna da coordenada2.
 * @param jogadorDaVez caracter que define qual é o jogador.
 *
 * @return Retorna verdadeiro, caso atenda a todas as condições de ser uma jogada válida.
 * @return Retorna falso caso contrário.
 */
bool Memoria::ehJogadaValida(int x, int y, int x2, int y2, char jogadorDaVez)
{
    if (x < 0 || x >= rows || y < 0 || y >= columns ||
        x2 < 0 || x2 >= rows || y2 < 0 || y2 >= columns ||
        (matrix[x][y] != ' ') || (matrix[x2][y2] != ' ') ||
        (x == x2 && y == y2))
    {
        return false;
    }
    else
        return true;
}

/**
 * @brief Responsável por realizar apenas as jogadas consideradas válidas
 *
 * Esta função valida/executa a jogada viável
 *
 * @param x Linha da coordenada1.
 * @param y Coluna da coordenada1.
 * @param x2 Linha da coordenada2.
 * @param y2 Coluna da coordenada2.
 * @param jogadorDaVez caracter que define qual é o jogador.
 */
void Memoria::validaJogada(int x, int y, int x2, int y2, char jogadorDaVez)
{
    if (!ehJogadaValida(x, y, x2, y2, jogadorDaVez))
    {
        cout << "ERRO: jogada inválida" << endl;
        return;
    }
    // Atribui ao tabuleiro real os simbolos que estão na posição (x,y) e (x1,y1) do tabuleiro auxiliar
    matrix[x][y] = aux[x][y];
    matrix[x2][y2] = aux[x2][y2];
}

bool Memoria::formamPares(int x, int y, int x2, int y2, char jogadorDaVez)
{
    // Condicional para verificar se as duas posições possuem símbolos iguais (são par um do outro)
    if (matrix[x][y] == matrix[x2][y2])
        return true;
    else
        return false;
}

void Memoria::validaPares(int x, int y, int x2, int y2, char jogadorDaVez)
{
    if (!formamPares(x, y, x2, y2, jogadorDaVez))
    { // Se o jogador não encontrou os simbolos iguais, limpa o tabuleiro e ninguem pontua
        cout << "Par não encontrado!" << endl;
        matrix[x][y] = ' ';
        matrix[x2][y2] = ' ';
        return;
    }
    // Se encontrou, os simbolos se mantêm no tabuleiro real e o jogador da vez pontua
    cout << "Par " << matrix[x][y] << "-" << matrix[x2][y2] << " encontrado!" << endl;
    if (jogadorDaVez == '1')
        pontosJogador1++;
    else if (jogadorDaVez == '2')
        pontosJogador2++;
}

/**
 * @brief Verifica a condição de vitória em um jogo da Memoria.
 *
 * Esta função confere se há um ganhador no jogo da Memoria,
 * comparando o número de pontos que cada jogador fez ao longo da partida.
 * Caso o jogador 1 tenha mais pontos, a função retorna 1 (vitória do Jogador 1).
 * Caso o jogador 2 tenha mais pontos, a função retorna 2 (vitória do Jogador 2).
 * Caso ambos tenham o mesmo número de pontos, a função retorna 3 (empate).
 * Se o jogo ainda não terminou, retorna 0.
 *
 * @return Retorna 0 caso ainda não tenha acabado o jogo
 * @return Retorna 1 caso o Jogador1 vença
 * @return Retorna 2 caso o Jogador2 vença
 * @return Retorna 3 caso tenha empate
 */
int Memoria::confereGanhador()
{

    if (pontosJogador1 > pontosJogador2)
    {
        return 1; /// jogador 1 ganhou
    }
    else if (pontosJogador2 > pontosJogador1)
    {
        return 2; /// jogador 2 ganhou
    }
    else if (pontosJogador1 == pontosJogador2)
    {
        return 3; /// empate
    }

    return 0;
}

/**
 * @brief  Verifica as condições do jogo da Memoria para decretar o fim de uma partida.
 *
 * Esta função percorre todas as coordenadas do tabuleiro, avaliando se todas as posições
 * já foram escolhidas (não tem nenhuma vazia).
 * Caso exista pelo menos uma coordenada vazias, o jogo ainda não acabou.
 * Caso contrário, é fim de jogo.
 *
 * @return retorna true, se o jogo tiver acabado, e false, caso contrário.
 */
bool Memoria::verificarFimDeJogo()
{
    for (int i = 0; i < rows; ++i)
    {
        for (int j = 0; j < columns; ++j)
        {
            if (matrix[i][j] == ' ')
            {
                return false;
            }
        }
    }
    return true;
}