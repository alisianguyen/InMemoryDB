#include <iostream>
#include <unordered_map>
#include <stdexcept>
#include <optional>

class InMemoryDB {
private:
    std::unordered_map<std::string, int> mainState;
    std::unordered_map<std::string, int> transactionState;
    bool transactionInProgress;

public:
    InMemoryDB() : transactionInProgress(false) {}

    // Retrieve the value associated with the key
    std::optional<int> get(const std::string &key) {
        if (transactionInProgress && transactionState.find(key) != transactionState.end()) {
            return transactionState[key];
        }
        auto it = mainState.find(key);
        return it != mainState.end() ? std::optional<int>(it->second) : std::nullopt;
    }

    // Create or update a key-value pair
    void put(const std::string &key, int value) {
        if (!transactionInProgress) {
            throw std::runtime_error("Transaction is not in progress");
        }
        transactionState[key] = value;
    }

    // Begin a transaction
    void begin_transaction() {
        if (transactionInProgress) {
            throw std::runtime_error("A transaction is already in progress");
        }
        transactionState = mainState;
        transactionInProgress = true;
    }

    // Commit the transaction
    void commit() {
        if (!transactionInProgress) {
            throw std::runtime_error("No transaction in progress to commit");
        }
        mainState = transactionState;
        transactionState.clear();
        transactionInProgress = false;
    }

    // Rollback the transaction
    void rollback() {
        if (!transactionInProgress) {
            throw std::runtime_error("No transaction in progress to rollback");
        }
        transactionState.clear();
        transactionInProgress = false;
    }
};

int main() {
    InMemoryDB inmemoryDB;

    // Test cases based on provided example
    try {
        std::cout << (inmemoryDB.get("A").has_value() ? std::to_string(inmemoryDB.get("A").value()) : "null") << std::endl; // should return null

        inmemoryDB.put("A", 5); // should throw an error
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    inmemoryDB.begin_transaction(); // starts a transaction
    inmemoryDB.put("A", 5);
    std::cout << (inmemoryDB.get("A").has_value() ? std::to_string(inmemoryDB.get("A").value()) : "null") << std::endl; // should return null

    inmemoryDB.put("A", 6);
    inmemoryDB.commit(); // commit the transaction
    std::cout << (inmemoryDB.get("A").has_value() ? std::to_string(inmemoryDB.get("A").value()) : "null") << std::endl; // should return 6

    try {
        inmemoryDB.commit(); // should throw an error
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    try {
        inmemoryDB.rollback(); // should throw an error
    } catch (const std::exception &e) {
        std::cout << e.what() << std::endl;
    }

    std::cout <<