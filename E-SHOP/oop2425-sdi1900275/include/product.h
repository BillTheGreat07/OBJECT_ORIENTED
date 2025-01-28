#ifndef PRODUCT_H
#define PRODUCT_H
#include <string>
#include <vector>

class Product {
private:
    std::string title;
    std::string description;
    std::string category;
    std::string subcategory;
    double price;
    std::string unit;
    int quantity;

public:
    Product(const std::string& title, const std::string& description, const std::string& category,
            const std::string& subcategory, double price, const std::string& unit, int quantity);

    const std::string& getTitle() const;
    const std::string& getDescription() const;
    const std::string& getCategory() const;
    double getPrice() const;
    int getQuantity() const;

    void setTitle(const std::string& newTitle);
    void setDescription(const std::string& newDescription);
    void setPrice(double newPrice);
    void setQuantity(int newQuantity);

    std::string toFileFormat() const;

    static void addNewProduct(const std::string& title, const std::string& description, const std::string& category,
                              const std::string& subcategory, double price, const std::string& unit, int quantity);
    static std::vector<Product> loadProducts(const std::string& filepath);
};

#endif