#ifndef Jogadores_H
#define Jogadores_H
#include <string>
#include <iostream>
#include <sstream>
#include <fstream>

using namespace std;

class Jogadores{
    public:
    int id;
    static int automatic;
    string Apelido;
    string Nome;

    int Jogadores::pesquisaJogador(string Apelido);

    Jogadores::Jogadores(string Apelido, string Nome); //construtor, faz o cadastro

    Jogadores::signInjogador(string Apelido);

    Jogadores::removeJogador(string Apelido,);

    void Jogadores::listarJogadores()/

}

#endif