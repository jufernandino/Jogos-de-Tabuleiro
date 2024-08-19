#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

#include "Memoria.hpp"

TEST_CASE("Teste Memoria"){
    Memoria m;
    CHECK(m.ehJogadaValida(0, 0, 1, 1, '1') == true);
    CHECK(m.ehJogadaValida(1, 0, 1, 1, '2') == true);
    CHECK(m.ehJogadaValida(1, 0, 1, 1, 'P') == false);
    CHECK(m.ehJogadaValida(-1, 0, 1, 1, '1') == false);
    CHECK(m.ehJogadaValida(0, -10, 1, 1, '1') == false);
    CHECK(m.ehJogadaValida(0, 0, 1, -5, '1') == false);
    CHECK(m.ehJogadaValida(0, 0, -9, 1, '1') == false);
    CHECK(m.ehJogadaValida(0, 0, 100, 1, '1') == false);
}