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

