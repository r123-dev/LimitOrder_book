
# LimitOrder Book

A high-performance C++ implementation of a Limit Order Book (LOB) system, designed to simulate order matching mechanisms used in financial exchanges. This project supports fundamental operations such as adding orders, matching orders, and canceling orders, providing a foundation for developing trading algorithms and conducting market simulations.

## 📁 Project Structure

```
LimitOrder_book/
├── include/        # Header files (e.g., Order.hpp, OrderBook.hpp)
├── src/            # Source files implementing core functionalities
├── lib/            # External libraries (e.g., Alpha Vantage API integration)
├── tests/          # Unit and integration tests
├── Makefile        # Build configuration
└── lob_engine      # Compiled executable
```

## 🚀 Features

- **Order Management**: Add, modify, and cancel buy/sell orders with unique identifiers.
- **Order Matching**: Efficient matching engine that processes incoming orders against existing ones based on price-time priority.
- **Alpha Vantage Integration**: Fetch real-time market data using the Alpha Vantage API for simulation and analysis.
- **Modular Design**: Clean separation of concerns with well-structured classes and functions.
- **Test Suite**: Comprehensive tests to ensure the correctness and robustness of the system.

## 🛠️ Installation

### Prerequisites

- **Operating System**: Linux or macOS
- **Compiler**: GCC with C++17 support
- **Dependencies**:
  - `libcurl` (for HTTP requests to Alpha Vantage API)

### Steps

1. **Clone the Repository**:

   ```bash
   git clone https://github.com/r123-dev/LimitOrder_book.git
   cd LimitOrder_book
   ```

2. **Build the Project**:

   ```bash
   make
   ```

   This will compile the source files and generate the `lob_engine` executable.

## 📈 Usage

After building the project, you can run the executable to start the simulation:

```bash
./lob_engine
```

The application will prompt you for inputs or execute predefined scenarios, depending on the implementation in `main.cpp`.

## 🔍 Testing

To run the test suite and validate the functionality:

```bash
make test
```

Ensure that all tests pass to confirm the integrity of the system.

## 📌 Notes

- **Alpha Vantage API Key**: To use the market data features, obtain a free API key from [Alpha Vantage](https://www.alphavantage.co/support/#api-key) and configure it in the appropriate source file or environment variable as per your implementation.

- **REST API Integration**: Currently, the project does not include REST API capabilities. Future enhancements may incorporate RESTful interfaces for external interactions.

## 📄 License

This project is licensed under the MIT License. See the [LICENSE](LICENSE) file for details.

## 🤝 Contributing

Contributions are welcome! Please fork the repository and submit a pull request for any enhancements or bug fixes.
