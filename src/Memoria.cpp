#include "Memoria.hpp"
#include <iostream>
#include <string>
#include <algorithm>
#include <time.h>

using namespace std;
/**
 * @brief Construtor:
 *
 * Inicializa um objeto Memoria com as configurações padrões
 * do tabuleiro, especificando o tamanho como 4 linhas e 4 colunas.
 * Além disso, inicializa uma matriz auxiliar para os caracteres/símbolos da partida.
 */
Memoria::Memoria()
{
    this->rows = 4;
    this->columns = 4;
    inicializaTabuleiroSimbolos();
}

/**
 * @brief Incializa uma matriz auxiliar para armazenar os símbolos/letras:
 *
 * Esta função cria uma string com todos os possíveis símbolos duplicados (em pares):
 * {A, A, B, B, C, C, D, D, E, E, F, F, G, G, H, H,}. Depois os caracteres na string são embaralhados
 * de modo aleatório, de tal forma que, a cada jogo, os símbolos vão estar em posições diferentes.
 * Em seguida os 8 pares de simbolos/letras são armazenados em uma matriz auxiliar.
 * Por último, a pontuação inicial dos jogadores é iniciada de modo zerado.
 */
void Memoria::inicializaTabuleiroSimbolos()
{
    string simbolos = {'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H'};

    // iniciar o gerador de números aleatórios
    srand(time(NULL));
    // embaralhar as palavras da string
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

    pontosJogador1 = 0;
    pontosJogador2 = 0;
}

/**
 * @brief Verifica se a jogada é valida de acordo com as regras do jogo da Memória:
 *
 * Esta função booleana agrupa todas as condições para determinar se uma jogada é válida ou não.
 * Primeiro, verifica se as posições `(x, y)` e `(x2, y2)`, passadas por parâmetro, estão vazias,
 * dentro das dimensões do tabuleiro e se são coordenadas diferentes entre si.
 * Caso as posições tenham todos os pré-requisitos, a jogada é considerada válida, retornando verdadeiro.
 * Caso contrário, a jogada é considerada inválida, retornando falso.
 *
 * @param x linha da coordenada 1.
 * @param y coluna da coordenada 1.
 * @param x2 linha da coordenada 2.
 * @param y2 coluna da coordenada 2.
 * @param jogadorDaVez caracter que define qual é o jogador.
 *
 * @return Verdadeiro, caso atenda a todas as condições de ser uma jogada válida.
 * @return Falso, caso não atenda a pelo menos uma das condições.
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
 * @brief Realiza/executa apenas as jogadas consideradas válidas:
 *
 * Caso as posições `(x, y)` e `(x2, y2)`, passadas por parâmetro, não sejam válidas, a função avisa o jogador e não executa a ação.
 * Caso sejam válidas, os símbolos que estão na posição (x,y) e (x2,y2) do tabuleiro auxiliar são atribuidos ao tabuleiro real.
 *
 * @param x linha da coordenada 1.
 * @param y coluna da coordenada 1.
 * @param x2 linha da coordenada 2.
 * @param y2 coluna da coordenada 2.
 * @param jogadorDaVez caracter que define qual é o jogador.
 */
void Memoria::validaJogada(int x, int y, int x2, int y2, char jogadorDaVez)
{
    if (!ehJogadaValida(x, y, x2, y2, jogadorDaVez))
    {
        cout << "ERRO: jogada inválida" << endl;
        return;
    }
    matrix[x][y] = aux[x][y];
    matrix[x2][y2] = aux[x2][y2];
}

/**
 * @brief Verifica se duas coordenadas passadas por parâmetro formam um par:
 *
 * Esta função booleanda avalia se as duas posições possuem símbolos iguais (são par um do outro)
 * Caso sejam, a função retorna verdadeiro. Caso contrário, retorna falso.
 *
 * @param x linha da coordenada 1.
 * @param y coluna da coordenada 1.
 * @param x2 linha da coordenada 2.
 * @param y2 coluna da coordenada 2.
 * @param jogadorDaVez caracter que define qual é o jogador.
 *
 * @return Verdadeiro, se formarem um par.
 * @return Falso, se não formarem um par.
 */
bool Memoria::formamPares(int x, int y, int x2, int y2, char jogadorDaVez)
{
    if (matrix[x][y] == matrix[x2][y2])
        return true;
    else
        return false;
}

/**
 * @brief Ações no tabuleiro são realizadas, de acordo com o resultado se os pares foram encontrados ou não:
 *
 * Primeiramente, esta função avalia se duas coordenadas formaram pares.
 * Em caso positivo, os símbolos se mantêm no tabuleiro real e o jogador da vez pontua.
 * Em caso negativo, se o jogador não encontrou símbolos iguais, limpa o tabuleiro e ninguem pontua.
 *
 * @param x linha da coordenada 1.
 * @param y coluna da coordenada 1.
 * @param x2 linha da coordenada 2.
 * @param y2 coluna da coordenada 2.
 * @param jogadorDaVez caracter que define qual é o jogador.
 */
void Memoria::validaPares(int x, int y, int x2, int y2, char jogadorDaVez)
{
    if (!formamPares(x, y, x2, y2, jogadorDaVez))
    {
        cout << "Par não encontrado!" << endl;
        matrix[x][y] = ' ';
        matrix[x2][y2] = ' ';
        return;
    }

    cout << "Par " << matrix[x][y] << "-" << matrix[x2][y2] << " encontrado!" << endl;
    if (jogadorDaVez == '1')
        pontosJogador1++;
    else if (jogadorDaVez == '2')
        pontosJogador2++;
}

/**
 * @brief Condição de vitória em um jogo da Memória:
 *
 * Compara o número de pontos que cada jogador fez ao longo da partida.
 * Caso o jogador 1 tenha mais pontos, a função retorna 1 (vitória do Jogador 1).
 * Caso o jogador 2 tenha mais pontos, a função retorna 2 (vitória do Jogador 2).
 * Caso ambos tenham o mesmo número de pontos, a função retorna 3 (empate).
 * Se o jogo ainda não terminou, retorna 0.
 *
 * @return 0, caso ainda não tenha acabado o jogo.
 * @return 1, caso o Jogador 1 vença.
 * @return 2, caso o Jogador 2 vença.
 * @return 3, caso ocorra um empate.
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
 * @brief Verifica as condições do jogo da Memória para decretar o fim do jogo:
 *
 * Esta função booleana percorre todas as coordenadas do tabuleiro, avaliando se todas as posições
 * já foram escolhidas (ou seja, se não têm nenhuma vazia).
 * Caso exista pelo menos uma coordenada vazia, o jogo ainda não acabou. Caso contrário, o jogo chegou ao fim.
 *
 * @return Verdadeiro, se o jogo tiver acabado
 * @return Falso, se o jogo não tiver acabado.
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