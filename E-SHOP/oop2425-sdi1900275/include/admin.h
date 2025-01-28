#ifndef ADMIN_H
#define ADMIN_H
#include "user.h"
#include "product.h"
#include <string>
class Admin : public User {
public:
    Admin(const std::string& username, const std::string& password);
    void menu() override;
    void addProduct();
    void editProduct();
    void removeProduct();
    void showUnavailableProducts();
    void showTopProducts();
};
#endif
