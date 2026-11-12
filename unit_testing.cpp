#include <iostream>
#include <fstream>
#include <windows.h>
#include "user.h"

using namespace std;

/*
МЕТОД: Модульное тестирование
Идея: проверка отдельного класса в изоляции.
Используется тестовый драйвер, который создаёт экземпляры класса,
вызывает методы и логирует результаты.
 */

class TestDriver {
private:
    ofstream logFile;
    
    void log(const string& message) {
        cout << message << endl;
        logFile << message << endl;
    }
    
public:
    TestDriver() {
        logFile.open("unit_test_results.log");
        log("=== Модульное тестирование ===");
        log("Тестируем метод updateEmail() класса User");
        log("");
    }
    
    ~TestDriver() {
        logFile.close();
    }
    
    void runTest1() {
        log("Тест 1: Валидный email");
        User user(1, "john", "old@example.com", 25);
        bool result = user.updateEmail("new@example.com");
        log("Результат: " + string(result ? "ПРОЙДЕН" : "ПРОВАЛЕН"));
        log("Новый email: " + user.getEmail());
        log("");
    }
    
    void runTest2() {
        log("Тест 2: Email без @");
        User user(1, "john", "old@example.com", 25);
        bool result = user.updateEmail("invalidemail");
        log("Результат: " + string(!result ? "ПРОЙДЕН" : "ПРОВАЛЕН"));
        log("Email остался: " + user.getEmail());
        log("");
    }
    
    void runTest3() {
        log("Тест 3: Email без .");
        User user(1, "john", "old@example.com", 25);
        bool result = user.updateEmail("invalid@email");
        log("Результат: " + string(!result ? "ПРОЙДЕН" : "ПРОВАЛЕН"));
        log("Email остался: " + user.getEmail());
        log("");
    }
    
    void runAllTests() {
        runTest1();
        runTest2();
        runTest3();
        
        log("Вывод: тестовый драйвер позволяет изолированно тестировать");
        log("отдельный метод класса и логировать результаты для анализа.");
    }
};

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    
    TestDriver driver;
    driver.runAllTests();
    
    system("pause");
    return 0;
}