#ifndef USER_H
#define USER_H
#include <string>
#include <map>

class User {
protected:
    std::string username;
    std::string password;
    bool isAdmin;

public:
    User(const std::string& username, const std::string& password, bool isAdmin);
    virtual ~User() = default;
    virtual void menu() = 0;
    static User* login(const std::string& username, const std::string& password);
    static void registerUser();
};

#endif