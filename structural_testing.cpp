#include <iostream>
#include <windows.h>
#include "user.h"

using namespace std;

/*
 МЕТОД: Структурное тестирование
 Идея: тесты строятся на основе структуры кода.
 Строится граф потоков управления, вычисляется цикломатическое число.
 Цикломатическое число = количество независимых ветвей.
 */

void testStructuralTesting() {
    cout << "=== Структурное тестирование ===" << endl;
    cout << "Тестируем метод getDisplayName() класса User" << endl << endl;
       
    //Цикломатическое число: C(G) = E - N + 2 = 9 - 7 + 2 = 4   
    cout << "Тест 1: Пустой username" << endl;
    User user1(1, "", "test@example.com", 25);
    cout << "Результат: " << user1.getDisplayName() << endl << endl;
    
    cout << "Тест 2: Длинный username (> 10 символов)" << endl;
    User user2(1, "verylongusername", "test@example.com", 25);
    cout << "Результат: " << user2.getDisplayName() << endl << endl;
    
    cout << "Тест 3: Короткий username (<= 10 символов)" << endl;
    User user3(1, "john", "test@example.com", 25);
    cout << "Результат: " << user3.getDisplayName() << endl << endl;
    
    cout << "Вывод: цикломатическое число задаёт минимальное количество тестов" << endl;
    cout << "для полного покрытия всех ветвей кода." << endl;
}

int main() {
    SetConsoleCP(65001);
    SetConsoleOutputCP(65001);
    
    testStructuralTesting();
    
    system("pause");
    return 0;
}