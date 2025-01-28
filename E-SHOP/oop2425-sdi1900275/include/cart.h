#ifndef CART_H
#define CART_H
#include "product.h"
#include <vector>
#include <string>

class Cart {
private:
    std::vector<std::pair<Product, int>> items;

public:
    void addProduct(const Product& product, int quantity);
    void removeProduct(const std::string& title);
    void updateQuantity(const std::string& title, int newQuantity);
    void viewCart() const;
    double calculateTotal() const;
    void clearCart();
    const std::vector<std::pair<Product, int>>& getItems() const;
};

#endif
