#ifndef USER_H
#define USER_H

#include <cctype>
#include <string>
#include <vector>

class User {
private:
    int id;
    std::string username;
    std::string email;
    int age;
    bool isActive;

public:
    User(int id, const std::string& username, const std::string& email, int age);
    
    // Геттеры
    int getId() const;
    std::string getUsername() const;
    std::string getEmail() const;
    int getAge() const;
    bool isActiveUser() const;
    
    // Методы для тестирования
    bool validate() const;
    std::string getDisplayName() const;
    bool updateEmail(const std::string& newEmail);
    bool compareWith(const User& other) const;
};

#endif // USER_H