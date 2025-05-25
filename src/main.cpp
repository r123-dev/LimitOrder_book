#include "../include/Order.hpp"
#include "../include/Trade.hpp"
#include "../include/OrderBook.hpp"  

#include <iostream>
#include <string>
#include <sstream>
#include <curl/curl.h>
#include "../lib/json.hpp"

using json = nlohmann::json;

const std::string API_KEY = "4663Q82AA014BS1N";


static size_t WriteCallback(void* contents, size_t size, size_t nmemb, std::string* output) {
    output->append((char*)contents, size * nmemb);
    return size * nmemb;
}


double fetchLatestPrice(const std::string& symbol) {
    std::cout << "[INFO] Fetching live price for symbol: " + symbol << std::endl;
    CURL* curl = curl_easy_init();
    std::string readBuffer;

    if (curl) {
        std::ostringstream url;
        url << "https://www.alphavantage.co/query?function=GLOBAL_QUOTE&symbol="
            << symbol << "&apikey=" << API_KEY;

        curl_easy_setopt(curl, CURLOPT_URL, url.str().c_str());
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA, &readBuffer);

        CURLcode res = curl_easy_perform(curl);
        if (res != CURLE_OK) {
            std::cerr << "[ERROR] CURL error: " + std::string(curl_easy_strerror(res)) << std::endl;
            curl_easy_cleanup(curl);
            return -1;
        }

        curl_easy_cleanup(curl);

        try {
            json j = json::parse(readBuffer);
            std::string priceStr = j["Global Quote"]["05. price"];
            double price = std::stod(priceStr);
            std::cout << "[INFO] Live price fetched: " + priceStr << std::endl;
            return price;
        } catch (...) {
            std::cerr << "[ERROR] Failed to parse JSON or fetch valid price." << std::endl;
            return -1;
        }
    }

    std::cerr << "[ERROR] CURL initialization failed." << std::endl;
    return -1;
}

class Logger {
public:
    static void info(const std::string& message) {
        std::cout << "[INFO] " << message << std::endl;
    }

    static void error(const std::string& message) {
        std::cerr << "[ERROR] " << message << std::endl;
    }
};

int main() {
    Logger::info("Starting Limit Order Book Matching Engine");
    std::string symbol = "AAPL";  

    double livePrice = fetchLatestPrice(symbol);
    if (livePrice <= 0) {
        Logger::error("Failed to retrieve valid live price. Exiting.");
        return 1;
    }

    OrderBook book;


    book.addOrder(OrderType::BUY, symbol, livePrice - 1.0, 100);


    book.addOrder(OrderType::SELL, symbol, livePrice - 1.0, 100);

    book.matchOrders();

    Logger::info("Trades matched:");


    const std::vector<Trade>& allTrades = book.getTrades();

std::cout << "[INFO] Trades matched:\n";
std::cout << "[DEBUG] trades.size() = " << allTrades.size() << std::endl;

for (const auto& trade : allTrades) {
    std::cout << "[DEBUG] About to print trade..." << std::endl;
    std::cout << trade << std::endl;
}

    Logger::info("Engine execution completed.");
    return 0;
}
