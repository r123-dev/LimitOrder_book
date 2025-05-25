
#define CATCH_CONFIG_MAIN
#include "../lib/catch.hpp"
#include "../include/OrderBook.hpp"

TEST_CASE("Order Matching Logic", "[OrderBook]") {
    OrderBook book;
    book.addOrder(OrderType::BUY, "AAPL", 101.0, 50);
    book.addOrder(OrderType::SELL, "AAPL", 100.0, 50);
    const std::vector<Trade>& allTrades = book.getTrades();
    REQUIRE(allTrades.size() == 1);
    REQUIRE(allTrades[0].price == 100.0);
    REQUIRE(allTrades[0].quantity == 50);
}
