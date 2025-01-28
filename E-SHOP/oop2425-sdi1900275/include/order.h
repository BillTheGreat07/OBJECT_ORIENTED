#ifndef ORDER_H
#define ORDER_H
#include <vector>
#include "cart.h"

class Order {
private:
    static int orderCounter;
    int orderId;
    Cart cart;
    double totalCost;

public:
    Order(const Cart& cart);
    int getOrderId() const;
    double getTotalCost() const;
    static void saveOrder(const Order& order, const std::string& username);
    static void loadOrders(const std::string& username);
};

#endif
