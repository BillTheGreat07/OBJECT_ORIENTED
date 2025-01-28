#include <iostream>
#include <fstream>
#include "user.h"
#include "admin.h"
#include "customer.h"
#include "product.h"
#include "category.h"
#include "cart.h"
#include "order.h"

const std::string USERS_FILE = "files/users.txt";
const std::string PRODUCTS_FILE = "files/products.txt";
const std::string CATEGORIES_FILE = "files/categories.txt";

void handleFileError(const std::string& filename) {
    std::cerr << "Error: Unable to open file: " << filename << "\n";
    exit(EXIT_FAILURE);
}

int main() {
    
    std::ifstream userFile(USERS_FILE);
    if(!userFile) handleFileError(USERS_FILE);
    userFile.close();

    std::ifstream productFile(PRODUCTS_FILE);
    if(!productFile) handleFileError(PRODUCTS_FILE);
    productFile.close();

    std::ifstream categoryFile(CATEGORIES_FILE);
    if(!categoryFile) handleFileError(CATEGORIES_FILE);
    categoryFile.close();

    std::cout << "Welcome to the e-shop!!!\n";
    std::cout << "Do you want to login or register? (enter option): ";
    std::string option;
    std::cin >> option;
    if(option == "login") {
        std::string username, password;
        std::cout << "Please enter your username: ";
        std::cin >> username;
        std::cout << "Please enter your password: ";
        std::cin >> password;
        User* user = User::login(username, password);
        if(user) {
            user->menu();
            delete user;
        }else {
            std::cout << "Invalid credentials!\n";
        }
    }else if (option == "register") {
        User::registerUser();
    }else {
        std::cout << "Invalid option!\n";
    }
    return 0;
}
