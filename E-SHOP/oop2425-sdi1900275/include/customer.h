#ifndef CUSTOMER_H
#define CUSTOMER_H
#include "user.h"
#include "cart.h"
#include <string>

class Customer : public User {
private:
    Cart cart;
public:
    Customer(const std::string& username, const std::string& password);
    void menu() override;
    void searchProducts();
    void addToCart();
    void completeOrder();
};
#endif
