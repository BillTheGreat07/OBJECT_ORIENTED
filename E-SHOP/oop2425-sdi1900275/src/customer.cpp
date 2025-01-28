#include "customer.h"
#include "product.h"
#include "order.h"
#include <iostream>
#include <vector>
#include <algorithm>

Customer::Customer(const std::string& username, const std::string& password) : User(username, password, false) {}

void Customer::menu() {
    int choice;
    do {
        std::cout << "---Customer Menu---\n";
        std::cout << "1. Search Products\n2. Add to Cart\n3. View Cart\n4. Complete Order\n5. Exit\nEnter your choice: ";
        std::cin >> choice;

        switch (choice) {
            case 1:
                searchProducts();
                break;
            case 2:
                addToCart();
                break;
            case 3:
                cart.viewCart();
                break;
            case 4:
                completeOrder();
                break;
            case 5:
                std::cout << "Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice! Please try again.\n";
        }
    } while (choice != 5);
}

void Customer::searchProducts() {
    std::vector<Product> products = Product::loadProducts("files/products.txt");

    std::cout << "Search Options:\n1. Search by Title\n2. View All Products\nEnter your choice: ";
    int searchChoice;
    std::cin >> searchChoice;

    if (searchChoice == 1) {
        std::string title;
        std::cout << "Enter product title: ";
        std::cin.ignore();
        std::getline(std::cin, title);

        auto it = std::find_if(products.begin(), products.end(), [&](const Product& p) {
            return p.getTitle() == title;
        });

        if (it != products.end()) {
            std::cout << "Product Found:\n";
            std::cout << "Title: " << it->getTitle() << "\nDescription: " << it->getDescription()
                      << "\nCategory: " << it->getCategory() << "\nPrice: " << it->getPrice()
                      << "\nAvailable Quantity: " << it->getQuantity() << "\n";
        } else {
            std::cout << "Product not found!\n";
        }
    } else if (searchChoice == 2) {
        std::cout << "Available Products:\n";
        for (const auto& product : products) {
            std::cout << "- " << product.getTitle() << " (" << product.getCategory() << ")\n";
        }
    } else {
        std::cout << "Invalid choice!\n";
    }
}

void Customer::addToCart() {
    std::vector<Product> products = Product::loadProducts("files/products.txt");
    std::string title;
    int quantity;

    std::cout << "Enter product title to add to cart: ";
    std::cin.ignore();
    std::getline(std::cin, title);
    std::cout << "Enter quantity: ";
    std::cin >> quantity;

    auto it = std::find_if(products.begin(), products.end(), [&](const Product& p) {
        return p.getTitle() == title;
    });

    if (it != products.end()) {
        if (quantity > 0 && quantity <= it->getQuantity()) {
            cart.addProduct(*it, quantity);
            std::cout << "Product added to cart successfully!\n";
        } else {
            std::cout << "Invalid quantity! Available stock: " << it->getQuantity() << "\n";
        }
    } else {
        std::cout << "Product not found!\n";
    }
}

void Customer::completeOrder() {
    if (cart.getItems().empty()) {
        std::cout << "Your cart is empty. Add products before completing an order!\n";
        return;
    }

    Order order(cart);
    Order::saveOrder(order, username);
    std::cout << "Order completed successfully! Total cost: " << order.getTotalCost() << "\n";

    cart.clearCart();
}
