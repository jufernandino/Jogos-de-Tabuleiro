#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "Tabuleiro.hpp"
#include "Reversi.hpp"

TEST_CASE("Teste Reversi"){
    Reversi r;

    CHECK(r.ehJogadaValida(2, 4, 'X') == true);
    CHECK(r.ehJogadaValida(-1, -2, 'X') == false);
    CHECK(r.ehJogadaValida(3, 5, 'P') == false);
}