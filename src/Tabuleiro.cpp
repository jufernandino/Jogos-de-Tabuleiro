#include "Tabuleiro.hpp"
#include <iomanip>
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

/**
 * @brief Construtor padrão da classe Tabuleiro.
 *
 * Inicializa as variáveis `rows` e `columns` com valor 0.
 */
Tabuleiro::Tabuleiro()
{
  this->rows = 0;
  this->columns = 0;
}

/**
 * @brief Cria o tabuleiro alocando memória dinamicamente.
 *
 * A função aloca uma matriz de caracteres com dimensões `rows` e `columns`
 * e inicializa cada célula com um espaço em branco.
 */
void Tabuleiro::criaTabuleiro()
{
  matrix = new char *[rows];
  for (int i = 0; i < rows; i++)
  {
    matrix[i] = new char[columns];
    for (int j = 0; j < columns; j++)
    {
      matrix[i][j] = ' ';
    }
  }
}

/**
 * @brief Imprime o tabuleiro na tela.
 *
 * A função exibe o tabuleiro com as células separadas por linhas e colunas,
 * numerando as colunas no topo e as linhas na lateral.
 */
void Tabuleiro::imprimirTabuleiro()
{
  cout << '\n';
  string aux = "-";
  cout << "  ";
  for (int k = 0; k < this->columns; k++)
  {
    cout << k << "   ";
    aux += "----";
  }
  cout << '\n';
  cout << aux;
  for (int i = 0; i < rows; i++)
  {
    cout << '\n';
    for (int j = 0; j < columns; j++)
    {
      cout << '|' << ' ' << matrix[i][j] << ' ';
    }
    cout << '|' << ' ' << i;
    cout << '\n';
    cout << aux;
  }
  cout << '\n';
}

/**
 * @brief Libera a memória alocada para o tabuleiro.
 *
 * A função libera a memória alocada dinamicamente para a matriz `matrix`,
 * evitando vazamentos de memória.
 */
void Tabuleiro::liberaMemoria()
{
  for (int i = 0; i < rows; i++)
  {
    delete[] matrix[i];
  }
  delete[] matrix;
}

/**
 * @brief Valida e realiza uma jogada no tabuleiro.
 *
 * Verifica se a posição `(x, y)` está dentro das dimensões do tabuleiro e se está vazia.
 * Caso positivo, a célula recebe o caractere `z` representando o jogador.
 * Caso contrário, informa que a jogada é inválida.
 *
 * @param x Coordenada da linha da jogada.
 * @param y Coordenada da coluna da jogada.
 * @param z Caractere que representa o jogador (ex: 'X' ou 'O').
 */
void Tabuleiro::validaJogada(int x, int y, char z)
{
  if (x < this->rows && y < this->columns && matrix[x][y] == ' ')
  {
    matrix[x][y] = z;
  }
  else
  {
    cout << "\nEssa jogada é invalida! Passa a vez!\n"
         << endl;
  }
}

/**
 * @brief Mostra as regras do jogo selecionado.
 *
 * O usuário pode optar por ler as regras antes de iniciar o jogo. As regras são lidas
 * de um arquivo "Regras.txt" e exibidas na tela. O arquivo deve conter tags específicas
 * para identificar as regras de cada jogo, como `<R>` para Reversi.
 *
 * @param jogoEscolhido Caracter que identifica o jogo escolhido.
 */
void Tabuleiro::mostrarRegras(const char &jogoEscolhido)
{
  cout << "\nJ - JOGAR\n"
       << "L - Ler regras do jogo\n"
       << endl;

  string lerRegras;
  cin >> lerRegras;

  if (lerRegras == "J" || lerRegras == "j")
  {
    cout << "\n--------\nJOGAR PARTIDA\n--------\n"
         << endl;
    return;
  }
  else if (lerRegras == "L" || lerRegras == "l")
  {

    ifstream arquivo("Regras.txt");

    if (!arquivo.is_open())
    {
      cout << "ERRO: não foi possível abrir o arquivo Regras.txt" << endl;
      return;
    }

    string linha;
    string regras;

    bool continuar = false;

    string escolha(1, jogoEscolhido); // conversão string para char
    string aux = "<" + escolha + ">";
    // cout << "Procurando por regras com tag: " << inicioRegras << endl;

    while (getline(arquivo, linha))
    {
      // Remover espaços em branco antes e depois da linha
      linha.erase(0, linha.find_first_not_of(" \t\r\n")); // Remove espaços no início
      linha.erase(linha.find_last_not_of(" \t\r\n") + 1); // Remove espaços no final

      if (linha == aux)
      {
        continuar = true;
        continue;
      }
      if (linha.find('<') != string::npos && linha.find('>') != string::npos)
      {
        if (continuar)
        {
          break;
        }
      }

      if (continuar)
      {
        regras += linha + "\n";
      }
    }

    arquivo.close();

    if (!regras.empty())
    {
      cout << "\n-------------- \nREGRAS DO JOGO\n--------------\n\n"
           << regras << endl;

      cout << "Vamos começar? Tecle ENTER para iniciar o jogo" << endl;

      cin.ignore();
      cin.get();

      cout << "\n--------\nJOGAR PARTIDA\n--------" << endl;
    }
  }
}