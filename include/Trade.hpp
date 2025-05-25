
#ifndef TRADE_HPP
#define TRADE_HPP

#include <iostream>
#include <string>

struct Trade {
 int buyOrderId;
int sellOrderId;
 std::string symbol;
 double price;
 int quantity;
};


inline std::ostream& operator<<(std::ostream& os, const Trade& trade) {
 os << "Trade => Buy Order ID: " << trade.buyOrderId
<< ", Sell Order ID: " << trade.sellOrderId
<< ", Symbol: " << trade.symbol
<< ", Price: " << trade.price
<< ", Quantity: " << trade.quantity;
 return os;
}

#endif
