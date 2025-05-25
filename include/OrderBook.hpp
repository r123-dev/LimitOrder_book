
#ifndef ORDERBOOK_HPP
#define ORDERBOOK_HPP

#include "./Order.hpp"
#include "./Trade.hpp"
#include <queue>
#include <vector>
#include <functional>

class OrderBook {
private:
    std::priority_queue<Order, std::vector<Order>, std::function<bool(Order, Order)>> buyOrders;
    std::priority_queue<Order, std::vector<Order>, std::function<bool(Order, Order)>> sellOrders;
    std::vector<Trade> trades;  
    int nextOrderId;

public:
    OrderBook();
    void addOrder(OrderType type, const std::string& symbol, double price, int quantity);
    void matchOrders();

    const std::vector<Trade>& getTrades() const;
};

#endif
