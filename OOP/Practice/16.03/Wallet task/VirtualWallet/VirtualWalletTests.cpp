#pragma once

#include "../catch_amalgamated.hpp"
#include "VirtualWallet.hpp"

TEST_CASE("Register card full wallet") {
    VirtualWallet wallet = VirtualWallet();
    Card card1 = Card(0, 120);
    Card card2 = Card(1, 120);
    Card card3 = Card(2, 120);
    Card card4 = Card(3, 120);
    Card card5 = Card(4, 120);
    Card cardFail = Card(1230,22);

    wallet.registerCard(card1);
    wallet.registerCard(card2);
    wallet.registerCard(card3);
    wallet.registerCard(card4);
    wallet.registerCard(card5);

    REQUIRE(wallet.registerCard(cardFail) == false);

}

TEST_CASE("Add one card multiple times"){
    VirtualWallet wallet = VirtualWallet();
    Card card1 = Card(0, 120);

    wallet.registerCard(card1);

    REQUIRE(wallet.registerCard(card1) == false);
}

TEST_CASE("Make payment from unexisting card"){
    VirtualWallet wallet = VirtualWallet();

    REQUIRE(wallet.makePayment(1, 200) == false);
}

TEST_CASE("Make payment from card with negative value"){
    VirtualWallet wallet = VirtualWallet();
    Card card = Card(1,120);
    REQUIRE(wallet.makePayment(1, -10) == false);
}

TEST_CASE("Make payment from card with not enough money"){
    VirtualWallet wallet = VirtualWallet();
    Card card = Card(1,120);
    REQUIRE(wallet.makePayment(1, 130) == false);
}

TEST_CASE("Feed unexisting card") {
    VirtualWallet wallet = VirtualWallet();

    REQUIRE(wallet.feedCard(0, 120) == false);
}

TEST_CASE("Feed card with negative sum") {
    VirtualWallet wallet = VirtualWallet();
    Card card = Card(0,700);

    REQUIRE(wallet.feedCard(0, -120) == false);
}

TEST_CASE("Return unexisting card"){
    VirtualWallet wallet = VirtualWallet();

    REQUIRE(wallet.getCard(-1) =    = nullptr);
}