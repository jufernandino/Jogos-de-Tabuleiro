#ifndef Memoria_H
#define Memoria_H
#include "Tabuleiro.hpp"

using namespace std;
/**
 * @class Memoria
 * @brief Classe que representa o jogo da Memoria
 *
 * A classe "Memoria" é uma classe herdeira de classe base "Tabuleiro" e implementa a lógica específica do
 * jogo da Memória, incluindo a verificação de condição de vitoria (função que sobrescreve a da classe base).
 * Além disso inclui métodos próprios como: inicialização do tabuleiro com os simbolos,
 * verificação se a jogada é valida de acordo com as regras do jogo da Memoria, validação/execução da jogada,
 * verificação se duas coordenadas possuem o mesmo símbolo (pares), validação das casas que formam pares,
 * verificação se há movimentos possiveis.
 */
class Memoria : public Tabuleiro
{
public:
    /**
     * @brief Construtor da classe Memoria.
     *
     * Inicializa um objeto Memoria com as configurações padrões do tabuleiro.
     */
    Memoria();

    /**
     * @brief Confere se há um ganhador no jogo.
     *
     * Esta função sobrescreve o método "confereGanhador" da classe base "Tabuleiro"
     * e implementa a lógica para verificar se há um vencedor na partida de jogo da Memoria.
     *
     * @return Retorna 1 se houver um vencedor, 0 caso contrário.
     */
    virtual int confereGanhador() override;

    /**
     * @brief Verifica se a jogada é valida de acordo com as regras do jogo da Memoria.
     *
     * Esta função booleana agrupa todas as condições para determinar se uma jogada
     * é válida de acordo com as regras do jogo da Memoria.
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
    bool ehJogadaValida(int x, int y, int x2, int y2, char jogadorDaVez);

    /**
     * @brief Responsável por realizar apenas as jogadas consideradas validas
     *
     * Esta função valida/executa a jogada viável
     *
     * @param x Linha da coordenada1.
     * @param y Coluna da coordenada1.
     * @param x2 Linha da coordenada2.
     * @param y2 Coluna da coordenada2.
     * @param jogadorDaVez caracter que define qual é o jogador.
     */
    void validaJogada(int x, int y, int x2, int y2, char jogadorDaVez);

    bool formamPares(int x, int y, int x2, int y2, char jogadorDaVez);

    void validaPares(int x, int y, int x2, int y2, char jogadorDaVez);

    /**
     * @brief Verifica as condições do jogo da Memória para decretar o fim de uma partida.
     *
     * Esta função booleana confere todas as condições para determinar se o jogo acabou ou não.
     *
     * @return retorna verdadeiro, se o jogo tiver acabado, e falso, caso contrário.
     */
    bool verificarFimDeJogo();

private:
    void inicializaTabuleiroSimbolos();
    int pontosJogador1;
    int pontosJogador2;
    int jogadorAtual;
    char aux[4][4];
};

#endif