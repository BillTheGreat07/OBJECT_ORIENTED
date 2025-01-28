#include "order.h"
#include "cart.h"
#include <fstream>
#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>

int Order::orderCounter = 1;

Order::Order(const Cart& cart): orderId(orderCounter++), cart(cart), totalCost(cart.calculateTotal()) {}

int Order::getOrderId() const {
    return orderId;
}

double Order::getTotalCost() const {
    return totalCost;
}

void Order::saveOrder(const Order& order, const std::string& username) {
    std::ofstream file("files/order_history/" + username + "_history.txt", std::ios::app);
    if (!file) {
        std::cerr << "Error: Unable to open file for writing order history." << std::endl;
        return;
    }

    file << "---CART " << order.getOrderId() << " START---\n";
    for (const auto& item : order.cart.getItems()) {
        file << std::setw(5) << item.second << " " << item.first.getTitle() << "\n";
    }
    file << "---CART " << order.getOrderId() << " END---\n";
    file << "Total Cost: " << std::fixed << std::setprecision(2) << order.getTotalCost() << "\n\n";
}

void Order::loadOrders(const std::string& username) {
    std::ifstream file("files/order_history/" + username + "_history.txt");
    if (!file) {
        std::cerr << "No order history found for user: " << username << std::endl;
        return;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::cout << line << "\n";
    }
    std::cout << std::endl;
}
