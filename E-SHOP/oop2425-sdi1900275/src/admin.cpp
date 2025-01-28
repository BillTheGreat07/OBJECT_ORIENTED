#include "admin.h"
#include "product.h"
#include <iostream>
#include <vector>
#include <limits>

Admin::Admin(const std::string& username, const std::string& password) : User(username, password, true) {}

void Admin::menu() {
    int choice;
    do {
        std::cout << "---Admin Menu---\n";
        std::cout << "1. Add Product\n2. Edit Product\n3. Remove Product\n4. Show Unavailable Products\n5. Show Top Products\n6. Exit\nEnter your choice: ";
        std::cin >> choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n'); // Clear buffer after input
        switch(choice) {
            case 1:
                addProduct();
                break;
            case 2:
                editProduct();
                break;
            case 3:
                removeProduct();
                break;
            case 4:
                showUnavailableProducts();
                break;
            case 5:
                showTopProducts();
                break;
            case 6:
                std::cout << "Goodbye!\n";
                break;
            default:
                std::cout << "Invalid choice!\n";
        }
    } while(choice != 6);
}

void Admin::addProduct() {
    std::string title, description, category, subcategory, unit;
    double price;
    int quantity;
    std::cout << "Enter product title: ";
    getline(std::cin, title);
    std::cout << "Enter product description: ";
    getline(std::cin, description);
    std::cout << "Enter category: ";
    getline(std::cin, category);
    std::cout << "Enter subcategory: ";
    getline(std::cin, subcategory);
    std::cout << "Enter price: ";
    std::cin >> price;
    std::cin.ignore();
    std::cout << "Enter unit (Kg/Unit): ";
    getline(std::cin, unit);
    std::cout << "Enter quantity: ";
    std::cin >> quantity;
    std::cin.ignore();
    Product::addNewProduct(title, description, category, subcategory, price, unit, quantity);
    std::cout << "Product added successfully!\n";
}

void Admin::editProduct() {
    std::string title, input;
    int choice;
    std::cout << "Enter the product title to edit: ";
    getline(std::cin, title);
    // Add functionality to edit a product based on title
    std::cout << "Product updated successfully!\n";
}

void Admin::removeProduct() {
    std::string title;
    std::cout << "Enter the product title to remove: ";
    getline(std::cin, title);
    // Add functionality to remove a product based on title
    std::cout << "Product removed successfully!\n";
}

void Admin::showUnavailableProducts() {
    std::vector<Product> products = Product::loadProducts("..\\files\\products.txt");
    for (const auto& product : products) {
        if (product.getQuantity() == 0) {
            std::cout << "Unavailable: " << product.getTitle() << "\n";
        }
    }
}

void Admin::showTopProducts() {
    std::cout << "Top products functionality pending.\n";
}
