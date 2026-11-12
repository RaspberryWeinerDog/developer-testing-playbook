#include <iostream>
#include <windows.h>
#include "user.h"

using namespace std;

/*
МЕТОД: Интеграционное тестирование
Идея: проверка взаимодействия между классами,
которые уже прошли модульное тестирование.
Цель - убедиться, что объекты корректно обмениваются сообщениями.
 */

void testIntegrationTesting() {
    cout << "=== Интеграционное тестирование ===" << endl;
    cout << "Тестируем взаимодействие двух объектов User" << endl << endl;
        
    cout << "Тест 1: Сравнение пользователей с одинаковым ID" << endl;
    User user1(1, "john", "john@example.com", 25);
    User user2(1, "jane", "jane@example.com", 30);
    bool result1 = user1.compareWith(user2);
    cout << "Результат: " << (result1 ? "ПРОЙДЕН (совпадают)" : "ПРОВАЛЕН") << endl << endl;
    
    cout << "Тест 2: Сравнение пользователей с одинаковым username" << endl;
    User user3(2, "john", "different@example.com", 35);
    bool result2 = user1.compareWith(user3);
    cout << "Результат: " << (result2 ? "ПРОЙДЕН (совпадают)" : "ПРОВАЛЕН") << endl << endl;
    
    cout << "Тест 3: Сравнение полностью разных пользователей" << endl;
    User user4(3, "alice", "alice@example.com", 28);
    bool result3 = user1.compareWith(user4);
    cout << "Результат: " << (!result3 ? "ПРОЙДЕН (не совпадают)" : "ПРОВАЛЕН") << endl << endl;
    
    cout << "Вывод: интеграционное тестирование проверяет, что объекты" << endl;
    cout << "корректно взаимодействуют друг с другом, а не просто работают по отдельности." << endl;
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    
    testIntegrationTesting();
    
    system("pause");
    return 0;
}