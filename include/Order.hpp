#ifndef ORDER_HPP
#define ORDER_HPP

#include <iostream>
#include <string>

enum class OrderType { BUY, SELL };




struct Order {
    int id;
    OrderType type;
    std::string symbol;
    double price;
    int quantity;

    Order(int id_, OrderType type_, std::string symbol_, double price_, int quantity_)
        : id(id_), type(type_), symbol(std::move(symbol_)), price(price_), quantity(quantity_) {}
};
std::ostream& operator<<(std::ostream& os, const Order& order);
#endif
