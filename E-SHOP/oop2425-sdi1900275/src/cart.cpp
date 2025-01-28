#include "cart.h"
#include "product.h"
#include <iostream>
#include <algorithm>

void Cart::addProduct(const Product& product, int quantity) {
    if (quantity > product.getQuantity()) {
        std::cout << "Requested quantity exceeds stock. Adding maximum available: " << product.getQuantity() << "\n";
        quantity = product.getQuantity();
    }
    for (auto& item : items) {
        if (item.first.getTitle() == product.getTitle()) {
            item.second += quantity;
            return;
        }
    }
    items.emplace_back(product, quantity);
}

void Cart::removeProduct(const std::string& title) {
    items.erase(
        std::remove_if(items.begin(), items.end(), [&](const auto& item) { return item.first.getTitle() == title; }),
        items.end());
}

void Cart::updateQuantity(const std::string& title, int newQuantity) {
    for (auto& item : items) {
        if (item.first.getTitle() == title) {
            if (newQuantity <= 0) {
                removeProduct(title);
            } else {
                item.second = std::min(newQuantity, item.first.getQuantity());
                if (newQuantity > item.first.getQuantity()) {
                    std::cout << "Quantity reduced to available stock: " << item.first.getQuantity() << "\n";
                }
            }
            return;
        }
    }
}

void Cart::viewCart() const {
    std::cout << "---CART START---\n";
    for (const auto& item : items) {
        std::cout << item.second << " " << item.first.getTitle() << "\n";
    }
    std::cout << "---CART END---\n";
    std::cout << "Total Cost: " << calculateTotal() << "\n";
}

double Cart::calculateTotal() const {
    double total = 0;
    for (const auto& item : items) {
        total += item.first.getPrice() * item.second;
    }
    return total;
}

void Cart::clearCart() {
    items.clear();
}

const std::vector<std::pair<Product, int>>& Cart::getItems() const {
    return items;
}
