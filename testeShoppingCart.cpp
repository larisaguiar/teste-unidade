#define CATCH_CONFIG_MAIN
#include "/usr/include/catch2/catch.hpp"

#include "shoppingCart.cpp"


TEST_CASE("ShoppingCart Tests") {
    ShoppingCart shoppingCart;

    // Configuração inicial
    shoppingCart.addItem(Item("ESM", 65.0));
    shoppingCart.addItem(Item("GoF", 120.0));

    SECTION("Test Add Item") {
        shoppingCart.addItem(Item("Clean Code", 80.0));
        REQUIRE(shoppingCart.getItemCount() == 3);
        REQUIRE(shoppingCart.getTotalPrice() == Approx(265.0));
    }

    SECTION("Test Remove Item") {
        shoppingCart.removeItem(Item("ESM", 65.0));
        REQUIRE(shoppingCart.getItemCount() == 1);
        REQUIRE(shoppingCart.getTotalPrice() == Approx(120.0));
    }

    SECTION("Test Get Total Price") {
        REQUIRE(shoppingCart.getTotalPrice() == Approx(185.0));
    }

    SECTION("Test Clear Cart") {
        shoppingCart.clearCart();
        REQUIRE(shoppingCart.getItemCount() == 0);
        REQUIRE(shoppingCart.getTotalPrice() == Approx(0.0));
    }
}