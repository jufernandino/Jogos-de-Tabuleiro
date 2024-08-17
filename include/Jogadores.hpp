#ifndef Jogadores_H
#define Jogadores_H

#include <string>
#include <iostream>
#include <sstream>
#include <fstream>
#include <vector>

using namespace std;
/**
 * @class Jogadores
 * @brief Classe que representa os jogadores e suas estatísticas em diferentes jogos.
 * 
 * Esta classe permite gerenciar as informações dos jogadores, como apelido, nome, 
 * vitórias, derrotas, empates em vários jogos, e suas estatísticas. 
 * Também fornece métodos para manipulação de jogadores e seus dados.
 */
class Jogadores
{
public:
    string Apelido; ///< Apelido do jogador.
    string Nome; ///< Nome do jogador.
    int reversiWins; ///< Número de vitórias no jogo Reversi.
    int reversiDefeats; ///< Número de derrotas no jogo Reversi.
    int reversiEmpates; ///< Número de empates no jogo Reversi.
    int lig4Wins; ///< Número de vitórias no jogo Lig4.
    int lig4Defeats; ///< Número de derrotas no jogo Lig4.
    int lig4Empates; ///< Número de empates no jogo Lig4.
    int tictactoeWins; ///< Número de vitórias no jogo TicTacToe.
    int tictactoeDefeats; ///< Número de derrotas no jogo TicTacToe.
    int tictactoeEmpates; ///< Número de empates no jogo TicTacToe.
    int campoMinadoWins; ///< Número de vitórias no jogo Campo Minado.
    int campoMinadoDefeats; ///< Número de derrotas no jogo Campo Minado.
    int memoriaWins; ///< Número de vitórias no jogo Memória.
    int memoriaDefeats; ///< Número de derrotas no jogo Memória.
    int memoriaEmpates; ///< Número de empates no jogo Memória.
    bool victory; ///< Indica se o jogador venceu a última partida.
    bool empate; ///< Indica se o jogador empatou a última partida.


/**
 * @brief Procura um jogador pelo apelido no arquivo de jogadores.
 * 
 * @param Apelido Apelido do jogador a ser procurado.
 * @return Retorna o índice do jogador no arquivo, ou -1 se não encontrado.
 */
    static int pesquisaJogador(string Apelido); // procura o jogador pelo seu apelido no arquivo

/**
 * @brief Construtor padrão da classe Jogadores.
 */
    Jogadores();

/**
 * @brief Construtor que inicializa um jogador com apelido e nome.
 * 
 * @param Apelido Apelido do jogador.
 * @param Nome Nome do jogador.
 */
    Jogadores(string Apelido, string Nome);

/**
 * @brief Realiza o login de um jogador, procurando-o na lista de jogadores.
 * 
 * @param Apelido Apelido do jogador.
 * @param jogadoresVector Vetor de jogadores onde o login será realizado.
 * @return Retorna o jogador logado.
 */
    Jogadores logIn(string Apelido, vector<Jogadores> &jogadoresVector);

/**
 * @brief Reescreve o arquivo de jogadores com os dados atualizados.
 * 
 * @param jogadoresVector Vetor de jogadores com as informações atualizadas.
 */
    static void reescreveArquivo(vector<Jogadores> &jogadoresVector);

/**
 * @brief Remove um jogador da lista de jogadores.
 * 
 * @param jogadoresVector Vetor de jogadores.
 * @param Apelido Apelido do jogador a ser removido.
 */
    static void  removeJogador(vector<Jogadores> &jogadoresVector, string &Apelido);

/**
 * @brief Atualiza as estatísticas do jogador com base no jogo escolhido.
 * 
 * @param jogoEscolhido Caracter que identifica o jogo que foi jogado.
 * @param jogadoresVector Vetor de jogadores com as informações atualizadas.
 */
    void atualizaEstatisticas(char jogoEscolhido, vector<Jogadores> &jogadoresVector);

/**
 * @brief Mostra o ranking dos jogadores para um jogo específico.
 * 
 * @param jogoEscolhido Caracter que identifica o jogo.
 * @param jogadoresVector Vetor de jogadores com as informações atualizadas.
 */
    static void mostrarRanking(const char &jogoEscolhido, vector<Jogadores> &jogadoresVector);

/**
 * @brief Mostra as estatísticas dos jogadores ordenadas por apelido ou nome.
 * 
 * @param jogadoresVector Vetor de jogadores com as informações atualizadas.
 * @param ordenacao Critério de ordenação: 'A' para apelido, 'N' para nome.
 */
    static void mostrarEstatisticas(vector<Jogadores> jogadoresVector, const string &ordenacao);

/**
 * @brief Carrega os jogadores a partir de um arquivo para o vetor de jogadores.
 * 
 * @param jogadoresVector Vetor de jogadores que será preenchido.
 */
    static void carregarJogadores(vector<Jogadores> &jogadoresVector);

/**
 * @brief Cadastra um novo jogador e o adiciona ao vetor de jogadores.
 * 
 * @param apelido Apelido do novo jogador.
 * @param nome Nome do novo jogador.
 * @param Jogador Referência ao objeto Jogadores a ser cadastrado.
 * @param jogadoresVector Vetor de jogadores onde o novo jogador será adicionado.
 */
    static void  cadastrarJogadores(string apelido, string nome, Jogadores &Jogador, vector<Jogadores> &jogadoresVector);

/**
 * @brief Ordena os jogadores pelo apelido.
 * 
 * @param jogadoresVector Vetor de jogadores a ser ordenado.
 */
    void ordenacaoApelido(vector<Jogadores> &jogadoresVector);

/**
 * @brief Ordena os jogadores pelo nome.
 * 
 * @param jogadoresVector Vetor de jogadores a ser ordenado.
 */
    void ordenacaoNome(vector<Jogadores> &jogadoresVector);
};

#endif