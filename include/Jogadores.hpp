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
 * @brief Classe para representar os jogadores.
 *
 * A classe "Jogadores" fornece uma interface básica para cadastrar jogadores,
 * pesquisar por jogador, fazer login, remover jogador, salvar dados de vitória
 * e derrota de cada jogador em estatisticas, visualizar as estaticas, mostrar o ranking
 * de cada jogo, carregar jogadores e ordenar os jogadores por apelido ou por nome.
 * Tudo isso é realizado com persistência de dados em arquivo.
 */
class Jogadores
{
public:
    string Apelido;
    string Nome;
    int reversiWins;
    int reversiDefeats;
    int reversiEmpates;
    int lig4Wins;
    int lig4Defeats;
    int lig4Empates;
    int tictactoeWins;
    int tictactoeDefeats;
    int tictactoeEmpates;
    int campoMinadoWins;
    int campoMinadoDefeats;
    int memoriaWins;
    int memoriaDefeats;
    int memoriaEmpates;
    bool victory;
    bool empate;

    /**
     * @brief Procura por um jogador no arquivo utilizando seu apelido.
     *
     * @param Apelido int
     * @retval int
     */
    static int pesquisaJogador(string Apelido);

    /**
     * @brief Construtor padrão da classe Jogadores.
     *
     * Inicializa os atributos de um jogador com valores padrão.
     */
    Jogadores();

    /**
     * @brief Construtor da classe Jogadores com parâmetros.
     *
     * Inicializa um jogador com os valores fornecidos e salva suas informações em
     * um arquivo.
     *
     * @param Apelido string 
     * @param Nome string
     * 
     */
    Jogadores(string Apelido, string Nome);

    /**
     * @brief Login de um jogador
     *
     * Realiza o login de um jogador, carregando suas informações do vetor de
     * jogadores.
     *
     * @param Apelido string
     * @param jogadoresVector string
     * 
     * @retval Jogadores
     */
    Jogadores logIn(string Apelido, vector<Jogadores> &jogadoresVector);

    /**
     * @brief Resscrita de informações no arquivo
     *
     * Reescreve o arquivo de jogadores com as informações atualizadas.
     * Apaga o conteúdo anterior do arquivo e grava as informações presentes no
     * vetor de jogadores.
     *
     * @param jogadoresVector vetor Jogadores
     * 
     * @retval none
     */
    static void reescreveArquivo(vector<Jogadores> &jogadoresVector);

    /**
     * @brief Remove um jogador.
     *
     * Procura pelo jogador no vetor utilizando o apelido, remove-o e atualiza o
     * arquivo de jogadores.
     *
     * @param jogadoresVector vetor Jogadores
     * @param Apelido string
     * 
     * @retval none
     */
    static void removeJogador(vector<Jogadores> &jogadoresVector, string &Apelido);
    
    /**
     * @brief Atualiza as estatísticas de um jogador para um jogo específico.
     *
     * Com base no jogo escolhido e no resultado (vitória ou derrota), atualiza as
     * estatísticas do jogador.
     *
     * @param jogoEscolhido char
     * @param jogadoresVector vetor Jogadores
     * 
     * @retval none
     */
    void atualizaEstatisticas(char jogoEscolhido, vector<Jogadores> &jogadoresVector);

    /**
     * @brief Exibir ranking de jogadores.
     *
     * Mostra o ranking dos jogadores para um jogo específico, ordenado pelo
     * número de vitórias.
     *
     * @param jogoEscolhido char
     * @param jogadoresVector vetor Jogadores
     * 
     * @retval none
     */
    static void mostrarRanking(const char &jogoEscolhido, vector<Jogadores> &jogadoresVector);

    /**
     * @brief Mostra as estatísticas dos jogadores, ordenadas por apelido ou nome.
     *
     * @param jogadoresVector vetor Jogadores
     * @param ordenacao string
     */
    static void mostrarEstatisticas(vector<Jogadores> &jogadoresVector, const string &ordenacao);

    /**
     * @brief Carrega as informações dos jogadores a partir de um arquivo para o
     * vetor de jogadores.
     *
     * Lê o arquivo de jogadores e preenche o vetor de jogadores com as informações carregadas.
     *
     * @param jogadoresVector vetor Jogadores
     */
    static void carregarJogadores(vector<Jogadores> &jogadoresVector);

    /**
     * @brief Cadastro de novo jogador.
     *
     * Cadastra um novo jogador no sistema e o adiciona ao vetor de jogadores.
     * Verifica se o apelido já existe e, caso contrário, adiciona o novo jogador ao
     * vetor e ao arquivo.
     *
     * @param apelido string
     * @param nome string
     * @param Jogador Jogadores
     * @param jogadoresVector vetor Jogadores
     */
    static void cadastrarJogadores(string apelido, string nome, Jogadores &Jogador, vector<Jogadores> &jogadoresVector);

    /**
     * @brief Ordenação alfabética pelos apelidos.
     *
     * Ordena o vetor pela ordem dos apelidos.
     *
     * @param apelido string
     * @param nome string
     * @param Jogador Jogadores
     * @param jogadoresVector vetor Jogadores
     */
    void ordenacaoApelido(vector<Jogadores> &jogadoresVector);

    /**
     * @brief Ordenação pela ordem alfabética pelos nomes.
     *
     * Ordena o vetor pela ordem dos nomes.
     *
     * @param apelido string
     * @param nome string
     * @param Jogador Jogadores
     * @param jogadoresVector vetor Jogadores
     */
    void ordenacaoNome(vector<Jogadores> &jogadoresVector);
};

#endif