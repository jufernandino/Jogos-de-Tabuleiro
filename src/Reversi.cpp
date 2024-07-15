#include "Reversi.hpp"
#include <iostream>

using namespace std;

Reversi::Reversi()
{
    inicializarJogo();
}

void Reversi::inicializarJogo()
{
    // Inicializar o tabuleiro com espaços vazios
    this->rows = TAMANHO_TABULEIRO;
    this->columns = TAMANHO_TABULEIRO;
    tabuleiro.criaTabuleiro();

    // Configura as peças centrais
    tabuleiro.setPosicao(3, 3, 'X'); // Coloca a peça X nas posiçoes especificadas
    tabuleiro.setPosicao(4, 4, 'X');
    tabuleiro.setPosicao(3, 4, 'O'); // Coloca a peça O nas posições especificadas
    tabuleiro.setPosicao(4, 3, 'O');
    jogadorAtual = 'X'; // O primeiro jogador vai começar com X
}

void Reversi::exibirTabuleiro() // Metodo para exibir o estado atual do tabuleiro
{
    tabuleiro.imprimeTabuleiro();
}

bool Reversi::fazerMovimento(int linha, int coluna)
{
    if (!verificarMovimentoValido(linha, coluna))
    {
        return false;
    }
    colocarPeca(linha, coluna);
    inverterPecas(linha, coluna);
    mudarJogador();
    return true;
}

bool Reversi::verificarMovimentoValido(int linha, int coluna)
{
    // Checa se a posiçao esta dentro do tabuleiro e se é um espaço vazio
    if (linha < 0 || linha >= TAMANHO_TABULEIRO || coluna < 0 || coluna >= TAMANHO_TABULEIRO || tabuleiro.getPosicao(linha, coluna) != ' ')
        return false;

    // Pega a cor do adversario com base no jogador atual
    char corAdversario = (jogadorAtual == 'X') ? 'O' : 'X';

    // Verifica todas as direções
    // N-O, N, N-L, O, L, S-O, S e S-L.
    const int direcoes[8][2] = {{-1, -1}, {-1, 0}, {-1, 1}, {0, -1}, {0, 1}, {1, -1}, {1, 0}, {1, 1}};

    for (auto &direcao : direcoes) // loop para percorrer todos os elementos da coleção de direções
    //"direcao" é a variável que irá representar cada item na coleção durante a iteração (auto deduz o seu tipo)
    {
        // direcao vai ser um vetor com duas partes: dLinha e dColuna.
        int dLinha = direcao[0];
        int dColuna = direcao[1];
        int linhaAtual = linha + dLinha; // atualiza as coordenadas com base na direção testada
        int colunaAtual = coluna + dColuna;
        bool encontrouAdversario = false; // Inicialmente é falso

        while (linhaAtual >= 0 && linhaAtual < TAMANHO_TABULEIRO && colunaAtual >= 0 && colunaAtual < TAMANHO_TABULEIRO)
        {
            if (tabuleiro.getPosicao(linhaAtual, colunaAtual) == corAdversario)
            {
                // Se a posição atual tem uma peça do adversario, "encontrouAdversario" vira true.
                encontrouAdversario = true;
            }
            else if (tabuleiro.getPosicao(linhaAtual, colunaAtual) == jogadorAtual && encontrouAdversario)
            {
                // Se, na posição, encontrar uma peça do mesmo jogador e houver pelo menos uma peça adversária entre as duas peças, a jogada é válida.
                return true;
            }
            else
            {
                break;
            }
            linhaAtual += dLinha;
            colunaAtual += dColuna;
        }
    }
    return false;
}

void Reversi::colocarPeca(int linha, int coluna)
{
    tabuleiro.setPosicao(linha, coluna, jogadorAtual); // Coloca a peça do jogador atual na posição especificada
}

void Reversi::inverterPecas(int linha, int coluna)
{
    // Código para inverter as peças
    // Verifique todas as direções e inverter as peças adversárias
}

void Reversi::mudarJogador()
{
    jogadorAtual = (jogadorAtual == 'X') ? 'O' : 'X';
}

bool Reversi::verificarFimDeJogo()
{
    // Verificar se não há mais movimentos válidos ou se o tabuleiro está cheio
}

void Reversi::mostrarResultado()
{
    int contagemX = contarPecas('X');
    int contagemO = contarPecas('O');
    cout << "Resultado final:" << endl;
    cout << "X: " << contagemX << " O: " << contagemO << endl;
    if (contagemX > contagemO)
    {
        cout << "Jogador X venceu!" << endl;
    }
    else if (contagemX < contagemO)
    {
        cout << "Jogador O venceu!" << endl;
    }
    else
    {
        cout << "Empate!" << endl;
    }
}

int Reversi::contarPecas(char cor)
{
    int contador = 0;
    for (int i = 0; i < TAMANHO_TABULEIRO; ++i)
    {
        for (int j = 0; j < TAMANHO_TABULEIRO; ++j)
        {
            if (tabuleiro.getPosicao(i, j) == cor)
            {
                ++contador;
            }
        }
    }
    return contador;
}
