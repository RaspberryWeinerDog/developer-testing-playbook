#include "user.h"

User::User(int id, const std::string& username, const std::string& email, int age)
    : id(id), username(username), email(email), age(age), isActive(true) {}

int User::getId() const { return id; }
std::string User::getUsername() const { return username; }
std::string User::getEmail() const { return email; }
int User::getAge() const { return age; }
bool User::isActiveUser() const { return isActive; }

// Метод валидации: проверяет корректность данных пользователя
bool User::validate() const {
    // Проверка ID
    if (id <= 0) return false;
    
    // Проверка username: минимум 3 символа, только буквы и цифры
    if (username.length() < 3 || username.length() > 20) return false;
    for (char c : username) {
        if (!isalnum(c)) return false;
    }
    
    // Проверка email: наличие @ и .
    if (email.find('@') == std::string::npos) return false;
    if (email.find('.') == std::string::npos) return false;
    
    // Проверка возраста: от 1 до 120
    if (age < 1 || age > 120) return false;
    
    return true;
}

// Метод для структурного тестирования: возвращает отображаемое имя
std::string User::getDisplayName() const {
    if (username.empty()) {
        return "Unknown";
    } else if (username.length() > 10) {
        return username.substr(0, 10) + "...";
    } else {
        return username;
    }
}

// Метод обновления email
bool User::updateEmail(const std::string& newEmail) {
    if (newEmail.find('@') == std::string::npos) {
        return false;
    }
    if (newEmail.find('.') == std::string::npos) {
        return false;
    }
    email = newEmail;
    return true;
}

// Метод сравнения двух пользователей
bool User::compareWith(const User& other) const {
    if (id == other.id) return true;
    if (username == other.username) return true;
    if (email == other.email) return true;
    return false;
}