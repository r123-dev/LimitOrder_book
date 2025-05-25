#include "../include/Order.hpp"


std::string orderTypeToString(OrderType type) {
    switch (type) {
        case OrderType::BUY: return "BUY";
        case OrderType::SELL: return "SELL";
        default: return "UNKNOWN";
    }
}


std::ostream& operator<<(std::ostream& os, const Order& order) {
    os << "Order{id: " << order.id
       << ", type: " << orderTypeToString(order.type)
       << ", symbol: " << order.symbol
       << ", price: " << order.price
       << ", quantity: " << order.quantity << "}";
    return os;
}
