#include "product.h"
#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>

Product::Product(const std::string& title, const std::string& description, const std::string& category,
                 const std::string& subcategory, double price, const std::string& unit, int quantity)
    : title(title), description(description), category(category), subcategory(subcategory), price(price), unit(unit), quantity(quantity) {}

const std::string& Product::getTitle() const {
    return title;
}

const std::string& Product::getDescription() const {
    return description;
}

const std::string& Product::getCategory() const {
    return category;
}

double Product::getPrice() const {
    return price;
}

int Product::getQuantity() const {
    return quantity;
}

void Product::setTitle(const std::string& newTitle) {
    title = newTitle;
}

void Product::setDescription(const std::string& newDescription) {
    description = newDescription;
}

void Product::setPrice(double newPrice) {
    price = newPrice;
}

void Product::setQuantity(int newQuantity) {
    quantity = newQuantity;
}

std::string Product::toFileFormat() const {
    std::ostringstream oss;
    oss << title << " @ " << description << " @ " << category << " @ " << subcategory << " @ " << price << " @ " << unit << " @ " << quantity;
    return oss.str();
}

void Product::addNewProduct(const std::string& title, const std::string& description, const std::string& category,
                             const std::string& subcategory, double price, const std::string& unit, int quantity) {
    std::ofstream file("files/products.txt", std::ios::app);
    if (!file) {
        std::cerr << "Error: Unable to open file for writing products." << std::endl;
        return;
    }
    file << title << " @ " << description << " @ " << category << " @ " << subcategory << " @ " << price << " @ " << unit << " @ " << quantity << "\n";
}

std::vector<Product> Product::loadProducts(const std::string& filepath) {
    std::vector<Product> products;
    std::ifstream file(filepath);
    if (!file) {
        std::cerr << "Error: Unable to open file for reading products." << std::endl;
        return products;
    }

    std::string line;
    while (std::getline(file, line)) {
        std::istringstream ss(line);
        std::string title, description, category, subcategory, unit;
        double price;
        int quantity;

        if (std::getline(ss, title, '@') && std::getline(ss, description, '@') &&
            std::getline(ss, category, '@') && std::getline(ss, subcategory, '@') &&
            ss >> price && ss.ignore(1) && std::getline(ss, unit, '@') && ss >> quantity) {

            products.emplace_back(title, description, category, subcategory, price, unit, quantity);
        } else {
            std::cerr << "Warning: Malformed line in products file: " << line << std::endl;
        }
    }

    return products;
}