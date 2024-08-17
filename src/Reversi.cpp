#include "Reversi.hpp"
#include <iomanip>
#include <iostream>
#include <string>
#include <vector>

/**
 * @brief Construtor da classe Reversi.
 *
 * Inicializa o tabuleiro do jogo Reversi com 8 linhas e 8 colunas.
 */
Reversi::Reversi()
{
  this->rows = 8;
  this->columns = 8;
}

/**
 * @brief Verifica a condição de vitória em um jogo Reversi.
 *
 * Esta função confere se há um ganhador no jogo Reversi,
 * contabilizando o número de peças de cada jogador no tabuleiro.
 * Caso o jogador 1 tenha mais peças, a função retorna 1 (vitória do Jogador 1).
 * Caso o jogador 2 tenha mais peças, a função retorna 2 (vitória do Jogador 2).
 * Caso ambos tenham o mesmo número de peças, a função retorna 3 (empate).
 * Se o jogo ainda não terminou, retorna 0.
 *
 * @return Retorna 0 caso ainda não tenha acabado o jogo
 * @return Retorna 1 caso o Jogador1 vença
 * @return Retorna 2 caso o Jogador2 vença
 * @return Retorna 3 caso tenha empate
 */
int Reversi::confereGanhador()
{
  int contadorX = 0;
  int contadorO = 0;

  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < columns; ++j)
    {
      if (matrix[i][j] == 'X')
      {
        contadorX++;
      }
      else if (matrix[i][j] == 'O')
      {
        contadorO++;
      }
    }
  }

  if (contadorX > contadorO)
  {
    return 1; /// jogador 1 ganhou
  }
  else if (contadorO > contadorX)
  {
    return 2; /// jogador 2 ganhou
  }
  else if (contadorX == contadorO)
  {
    return 3; /// empate
  }

  return 0;
}

/**
 * @brief Inicializa o jogo Reversi
 *
 * Esta função implementa as condições iniciais para o Reversi,
 * posicionando as peças centrais do jogo e declarando que sempre o
 * primeiro jogador terá X como o caracter representante de suas peças.
 *
 */
void Reversi::inicializarJogo()
{
  matrix[3][3] = 'X';
  matrix[4][4] = 'X';
  matrix[3][4] = 'O';
  matrix[4][3] = 'O';

  jogadorAtual = 'X';
}

/**
 * @brief Verifica se a jogada é valida de acordo com as regas do Reversi.
 *
 * Primeiro verifica se a posição `(x, y)` está dentro das dimensões do tabuleiro, e se está vazia.
 * Confere em todas as direções possíveis (NO, N, NE, O, L, SO, S, SE) se existem peças do jogador adversário.
 * Além disso, confere se a extremidade final termina com a peça do jogador atual.
 * Caso a posição tenha todos os pré-requisitos, a jogada é considerada válida, retornando verdadeiro.
 * Caso contrário, a jogada é considerada inválida e retorna falso.
 *
 * @param x Coordenada da linha.
 * @param y Coordenada da coluna.
 * @param jogadorDaVez Peça do jogador (X ou O).
 *
 * @return Retorna verdadeiro, caso atenda a todas as condições de ser uma jogada válida.
 * @return Retorna falso caso contrário.
 */
bool Reversi::ehJogadaValida(int x, int y, char jogadorDaVez)
{
  if (x < 0 || x >= rows || y < 0 || y >= columns || matrix[x][y] != ' ')
  {
    return false;
  }

  char corAdversario = ((jogadorDaVez == 'X') ? 'O' : 'X');
  const int direcoes[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

  for (int i = 0; i < 8; ++i)
  {
    int MoveLinha = direcoes[i][0];
    int MoveColuna = direcoes[i][1];
    int linhaAtual = x + MoveLinha;
    int colunaAtual = y + MoveColuna;
    bool encontrouAdversario = false;

    while (linhaAtual >= 0 && linhaAtual < rows && colunaAtual >= 0 && colunaAtual < columns)
    {
      if (matrix[linhaAtual][colunaAtual] == corAdversario)
      {
        encontrouAdversario = true;
      }
      else if (matrix[linhaAtual][colunaAtual] == jogadorDaVez && encontrouAdversario == true)
      {
        return true;
      }
      else
      {
        break;
      }
      linhaAtual = linhaAtual + MoveLinha;
      colunaAtual = colunaAtual + MoveColuna;
    }
  }
  return false;
}

/**
 * @brief Verifica se existe ao menos um movimento a ser feito no turno do jogador.
 *
 * Esta função percorre todas as coordenadas do tabuleiro, conferindo se há uma jogada válida para aquele jogador.
 * Caso uma das casas seja uma jogada válida, então contabiliza +1 em movimentosPossiveis.
 * Caso nenhuma casa represente uma jogada válida, movimentosPossiveis será equivalente a zero.
 *
 * @param jogadorDaVez Peça do jogador (X ou O).
 *
 * @return Retorna verdadeiro se movimentosPossiveis for difernte de 0.
 * @return Retorna falso se movimentosPossiveis for 0..
 */
bool Reversi::existeMovimentoPossivel(char jogadorDaVez)
{
  int movimentosPossiveis = 0;
  for (int i = 0; i < 8; ++i)
  {
    for (int j = 0; j < 8; ++j)
    {
      if (matrix[i][j] == ' ' && ehJogadaValida(i, j, jogadorDaVez))
      {
        movimentosPossiveis++;
      }
    }
  }
  if (movimentosPossiveis == 0)
  {
    return false;
  }
  return true;
}

/**
 * @brief Exibe todas as coordenadas de possíveis jogadas do turno.
 *
 * Este método mostra ao jogador do turno quais as possiveis casas ele poderá escolher.
 * Para isso, a função percorre todo o tabuleiro. Caso enontre um movimento
 * válido em determianda casa, então exibe na tela as coordenadas para essa jogada.
 *
 * @param jogadorDaVez Peça do jogador (X ou O).
 */
void Reversi::mostrarLocaisJogada(char jogadorDaVez)
{
  cout << "Coordenadas para jogadas possíveis: ";
  for (int i = 0; i < 8; ++i)
  {
    for (int j = 0; j < 8; ++j)
    {
      if (matrix[i][j] == ' ' && ehJogadaValida(i, j, jogadorDaVez))
      {
        /// Mostra a posição possível
        cout << "(" << i << "," << j << ") ";
      }
    }
  }
  cout << endl;
}

/**
 * @brief Valida uma jogada no tabuleiro.
 *
 * Esta função verifica se uma jogada é valida na partida de Reversi:
 * Primeiro verifica se a posição `(x, y)` representa uma jogada válida (ehJogadaValida = verdadeiro).
 * Caso a jogada seja válida, a célula recebe o caractere `z` representando o jogador
 * e depois as peças no meio são invertidas para o mesmo caractere
 * Caso contrário, informa que a jogada é inválida.
 *
 * @param x Coordenada da linha.
 * @param y Coordenada da coluna.
 * @param z Caractere do jogador (X ou O).
 */
void Reversi::validaJogada(int x, int y, char z)
{
  if (!ehJogadaValida(x, y, z))
  {
    cout << "ERRO: jogada inválida" << endl;
    return;
  }

  matrix[x][y] = z;
  inverterPecas(x, y, z);
}

/**
 * @brief Realizar a inversão das peças adversárias confinadas entre duas peças do jogador da vez.
 *
 * Esta função percorre todas as direções possíveis (NO, N, NE, O, L, SO, S, SE) a partir de uma coordenada fornecida `(x,y)`.
 * Durante a execução, são armazenada dentro de um vetor, todas as casas correspondentes ao caracter do jogador adversário.
 * Ao chegar na extremidade, se encontrar uma peça do jogador da vez, todas as coordenada armazenadas dentro do vetor,
 * recebem o caracter desse jogador.
 *
 * @param x Coordenada da linha.
 * @param y Coordenada da coluna.
 * @param jogadorDaVez Peça do jogador (X ou O).
 */
void Reversi::inverterPecas(int x, int y, char jogadorDaVez)
{
  char corAdversario = (jogadorDaVez == 'X') ? 'O' : 'X';
  const int direcoes[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

  for (int i = 0; i < 8; ++i)
  {
    int MoveLinha = direcoes[i][0];
    int MoveColuna = direcoes[i][1];
    int linhaAtual = x + MoveLinha;
    int colunaAtual = y + MoveColuna;

    /// salva as posições que vão ser invertidas
    vector<pair<int, int>> pecasParaInverter;

    while (linhaAtual >= 0 && linhaAtual < rows && colunaAtual >= 0 && colunaAtual < columns)
    {
      if (matrix[linhaAtual][colunaAtual] == corAdversario)
      { /// se for uma peça adversária
        /// Adicionar ao vetor de posições a posição atual
        pecasParaInverter.push_back({linhaAtual, colunaAtual});
      }
      else if (matrix[linhaAtual][colunaAtual] == jogadorDaVez)
      { /// Ao chegar na extremidada, em que volta a se a peça do jogador da vez
        /// percorre todas as posições do vetor
        for (auto &peca : pecasParaInverter)
        {
          matrix[peca.first][peca.second] = jogadorDaVez; /// Altera a cor
        }
        break;
      }
      else
      {
        break;
      }
      linhaAtual = linhaAtual + MoveLinha;
      colunaAtual = colunaAtual + MoveColuna;
    }
  }
}

/**
 * @brief  Verifica as condições do Reversi para decretar o fim de uma partida.
 *
 * Esta função percorre todas as coordenadas do tabuleiro, avaliando se estão vazias,
 * e se cumprem o requisito de jogada válida para qualquer um dos dois jogadores.
 * Caso exista pelo menos uma coordenada em conformidade com a condicional, o jogo ainda não acabou.
 * Caso contrário, então não existem mais movimentos para nenhum jogador, portanto é fim de jogo.
 *
 * @return retorna true, se o jogo tiver acabado, e false, caso contrário.
 */
bool Reversi::verificarFimDeJogo()
{
  for (int i = 0; i < rows; ++i)
  {
    for (int j = 0; j < columns; ++j)
    {
      if (matrix[i][j] == ' ' && (ehJogadaValida(i, j, 'X') || ehJogadaValida(i, j, 'O')))
      {
        return false;
      }
    }
  }
  return true;
}
