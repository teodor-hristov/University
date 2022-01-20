#pragma once

#include "../catch_amalgamated.hpp"
#include "Card.hpp"

TEST_CASE("Card negaative constructor values") {
    Card card = Card(-1, -50);

    REQUIRE(card.getID() > 0);
    REQUIRE(card.getBalance() > 0);
}

TEST_CASE("Withdraw more than the card have"){
    Card card = Card(0, 150);
    REQUIRE(card.withdraw(200) == false);
}

TEST_CASE("Withdraw negative sum"){
    Card card = Card(0, 150);
    REQUIRE(card.withdraw(-10) == false);
}

TEST_CASE("Deposit negative sum") {
    int startBalance = 9999;
    Card card = Card(1, startBalance);

    card.deposit(-1);
    REQUIRE(card.getBalance() == startBalance);
}
