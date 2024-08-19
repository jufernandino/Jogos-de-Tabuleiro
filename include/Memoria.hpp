#ifndef Memoria_H
#define Memoria_H
#include "Tabuleiro.hpp"

using namespace std;
/**
 * @class Memoria
 * @brief Classe que representa o jogo da Memória
 *
 * A classe "Memoria" é uma classe herdeira de classe base "Tabuleiro" e implementa a lógica específica do
 * jogo da Memória, incluindo a verificação de condição de vitória (função que sobrescreve a da classe base).
 * Além disso inclui métodos próprios como: inicialização do tabuleiro com os símbolos/letras,
 * verificação se a jogada é valida de acordo com as regras do jogo da Memória, validação/execução da jogada,
 * verificação se duas coordenadas possuem o mesmo símbolo (se são pares), validação das casas que formam pares,
 * verificação se há movimentos possíveis.
 */
class Memoria : public Tabuleiro
{
public:
    /**
     * @brief Construtor da classe.
     *
     */
    Memoria();

    /**
     * @brief Esta função sobrescreve o método "confereGanhador" da classe base "Tabuleiro"
     * e implementa a lógica para verificar se há um vencedor na partida de jogo da Memoria.
     *
     * @retval int 0
     * @retval int 1
     * @retval int 2
     * @retval int 3
     */
    virtual int confereGanhador() override;

    /**
     * @brief Validação da jogada.
     *
     * @param x int
     * @param y int
     * @param x2 int
     * @param y2 int
     * @param jogadorDaVez char
     *
     * @retval true
     * @retval false
     */
    bool ehJogadaValida(int x, int y, int x2, int y2, char jogadorDaVez);

    /**
     * @brief Execução de uma jogada.
     *
     * @param x int
     * @param y int
     * @param x2 int
     * @param y2 int
     * @param jogadorDaVez char
     *
     * @retval none
     */
    void validaJogada(int x, int y, int x2, int y2, char jogadorDaVez);

    /**
     * @brief Análise se duas posições formam um par.
     *
     * @param x int
     * @param y int
     * @param x2 int
     * @param y2 int
     * @param jogadorDaVez char
     *
     * @retval true
     * @retval false
     */
    bool formamPares(int x, int y, int x2, int y2, char jogadorDaVez);

    /**
     * @brief Execução de ações no tabuleiro, dependendo se tem pares.
     *
     * @param x int
     * @param y int
     * @param x2 int
     * @param y2 int
     * @param jogadorDaVez char
     *
     * @retval none
     */
    void validaPares(int x, int y, int x2, int y2, char jogadorDaVez);

    /**
     * @brief Verificador de fim da partida.
     *
     * @retval true
     * @retval false
     */
    bool verificarFimDeJogo();

    /**
     * @brief Inicialização da matriz/tabuleiro auxiliar para os símbolos.
     *
     * @retval none
     */
    void inicializaTabuleiroSimbolos();

private:
    /**
     * @brief Matriz para armazenar os símbolos em um tabuleiro auxiliar.
     * @var
     */
    char aux[4][4];
    /**
     * @brief Variável para armazenar os pontos do jogador 1.
     * @var
     */
    int pontosJogador1;
    /**
     * @brief Variável para armazenar os pontos do jogador 2.
     * @var
     */
    int pontosJogador2;
    /**
     * @brief Variável para armazenar qual é jogador atual.
     * @var
     */
    int jogadorAtual;
};

#endif