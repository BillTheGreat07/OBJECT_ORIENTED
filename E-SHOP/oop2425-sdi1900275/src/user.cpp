#include "user.h"
#include "admin.h"
#include "customer.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>

User::User(const std::string& username, const std::string& password, bool isAdmin)
    : username(username), password(password), isAdmin(isAdmin) {}

User* User::login(const std::string& username, const std::string& password) {
    std::ifstream file("files/users.txt");
    std::string line;
    while(std::getline(file, line)) {
        std::istringstream ss(line);
        std::string user, pass;
        int adminFlag;
        ss >> user >> pass >> adminFlag;

        if(user == username && pass == password) {
            if(adminFlag == 1) {
                return new Admin(username, password);
            }else {
                return new Customer(username, password);
            }
        }
    }
    return nullptr;
}

void User::registerUser() { 
    std::string username, password;
    char isAdminFlag;
    std::cout << "Enter username: ";
    std::cin >> username;
    std::cout << "Enter password: ";
    std::cin >> password;
    std::cout << "Are you an admin? (Y/N): ";
    std::cin >> isAdminFlag;

    std::ofstream file("files/users.txt", std::ios::app);
    file << username << " " << password << " " << (isAdminFlag == 'Y' || isAdminFlag == 'y' ? 1 : 0) << "\n";
    file.close();

    std::cout << "Registration successful!\n";
}