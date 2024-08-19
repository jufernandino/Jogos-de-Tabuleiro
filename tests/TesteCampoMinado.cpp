#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "Tabuleiro.hpp"
#include "CampoMinado.hpp"

TEST_CASE("Teste funcoes Campo Minado"){
    CampoMinado c;

    CHECK(c.validaJogadaCampoMinado(9, 9) == false);
    CHECK(c.validaJogadaCampoMinado(-1, 0) == false);
    CHECK(c.validaJogadaCampoMinado(0, -2) == false);
    CHECK(c.validaJogadaCampoMinado(0, 0) == true);
}