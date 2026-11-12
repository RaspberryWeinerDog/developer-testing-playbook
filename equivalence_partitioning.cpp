#include <iostream>
#include <windows.h>
#include "user.h"

using namespace std;

/*
 МЕТОД: Области эквивалентности
 Идея: входные данные разбиваются на классы эквивалентности.
 Внутри каждого класса программа ведёт себя одинаково.
 Для каждого класса выбирается хотя бы один тест.
 */

void testEquivalencePartitioning() {
    cout << "=== Области эквивалентности ===" << endl;
    cout << "Тестируем метод validate() класса User" << endl << endl;
    
    // Классы эквивалентности для ID:
    // 1. Невалидные: id <= 0
    // 2. Валидные: id > 0
    
    // Классы эквивалентности для username:
    // 1. Слишком короткий: < 3 символов
    // 2. Валидный: 3-20 символов, только буквы/цифры
    // 3. Слишком длинный: > 20 символов
    // 4. Содержит спецсимволы
    
    // Классы эквивалентности для email:
    // 1. Нет символа @
    // 2. Нет символа .
    // 3. Валидный email
    
    // Классы эквивалентности для age:
    // 1. Возраст < 1
    // 2. Валидный возраст: 1-120
    // 3. Возраст > 120
    
    cout << "Тест 1: Все поля валидные" << endl;
    User user1(1, "john123", "john@example.com", 25);
    cout << "Результат: " << (user1.validate() ? "ПРОЙДЕН" : "ПРОВАЛЕН") << endl << endl;
    
    cout << "Тест 2: Невалидный ID (id = 0)" << endl;
    User user2(0, "john123", "john@example.com", 25);
    cout << "Результат: " << (!user2.validate() ? "ПРОЙДЕН" : "ПРОВАЛЕН") << endl << endl;
    
    cout << "Тест 3: Слишком короткий username (2 символа)" << endl;
    User user3(1, "jo", "john@example.com", 25);
    cout << "Результат: " << (!user3.validate() ? "ПРОЙДЕН" : "ПРОВАЛЕН") << endl << endl;
    
    cout << "Тест 4: Email без @" << endl;
    User user4(1, "john123", "johnexample.com", 25);
    cout << "Результат: " << (!user4.validate() ? "ПРОЙДЕН" : "ПРОВАЛЕН") << endl << endl;
    
    cout << "Тест 5: Возраст за пределами диапазона (age = 150)" << endl;
    User user5(1, "john123", "john@example.com", 150);
    cout << "Результат: " << (!user5.validate() ? "ПРОЙДЕН" : "ПРОВАЛЕН") << endl << endl;
    
    cout << "Вывод: метод позволяет сократить количество тестов с полного перебора" << endl;
    cout << "до разумного минимума при сохранении покрытия основных сценариев." << endl;
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    
    testEquivalencePartitioning();
    
    system("pause");
    return 0;
}