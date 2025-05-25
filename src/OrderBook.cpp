
#include "../include/OrderBook.hpp"
#include <iostream>

OrderBook::OrderBook()
    : buyOrders([](Order a, Order b) { return a.price < b.price; }),
      sellOrders([](Order a, Order b) { return a.price > b.price; }),
      nextOrderId(1) {}

void OrderBook::addOrder(OrderType type, const std::string& symbol, double price, int quantity) {
    Order order(nextOrderId++, type, symbol, price, quantity);
    if (type == OrderType::BUY)
        buyOrders.push(order);
    else
        sellOrders.push(order);
    matchOrders();
}

void OrderBook::matchOrders() {
    while (!buyOrders.empty() && !sellOrders.empty() &&
           buyOrders.top().price >= sellOrders.top().price) {
        Order buy = buyOrders.top();
        Order sell = sellOrders.top();
        buyOrders.pop();
        sellOrders.pop();

        int matchedQty = std::min(buy.quantity, sell.quantity);
        trades.emplace_back(Trade{buy.id, sell.id, buy.symbol, sell.price, matchedQty});

        if (buy.quantity > matchedQty)
            buyOrders.push(Order(buy.id, buy.type, buy.symbol, buy.price, buy.quantity - matchedQty));
        if (sell.quantity > matchedQty)
            sellOrders.push(Order(sell.id, sell.type, sell.symbol, sell.price, sell.quantity - matchedQty));
    }
}

const std::vector<Trade>& OrderBook::getTrades() const {
    return trades;
}
