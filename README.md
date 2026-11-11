# developer-testing-playbook

Учебный репозиторий. Набор консольных приложений на C++, демонстрирующих классические подходы к тестированию программного обеспечения начиная с анализа входных данных и заканчивая проверками взаимодействий между классами.

Реализованные подходы:

**Области эквивалентности.** Метод «чёрного ящика». Входные данные разбиваются на классы, внутри которых программа ведёт себя одинаково. Для каждого класса подбирается хотя бы одна тестовая последовательность. Правила построения: тестовая последовательность может состоять из одного элемента; в разных тестах используются последовательности разной длины; ключевой элемент располагается в начале, середине и конце последовательности. Позволяет сократить количество тестов с полного перебора до разумного минимума при сохранении покрытия основных сценариев.

**Структурное тестирование.** Метод «белого ящика». По коду строится граф потоков управления, вычисляется цикломатическое число Маккейба, которое задаёт минимальное количество независимых ветвей, которые необходимо пройти тестами. Если все независимые ветви выполнены, гарантируется, что каждый оператор отработал хотя бы раз, а каждое условие проверено как в истинной, так и в ложной ветви. Метод применяется к отдельным модулям и методам.

**Модульное тестирование.** Проверка отдельного класса в изоляции от его спецификации. Используется тестовый драйвер — автономный класс, который создаёт экземпляры тестируемого класса, вызывает его методы и логирует результаты. Спецификация тестового случая включает: название класса, название теста, описание логики, входные данные, ожидаемый результат. Тестирование выполняется до интеграции класса в другие компоненты;

**Интеграционное тестирование.** Проверка взаимодействия между классами, уже прошедшими модульное тестирование. Цель — убедиться, что объекты корректно обмениваются сообщениями, а не проверить работу системы в целом. Выделяются четыре типа взаимодействий: параметр объектного типа в сигнатуре метода, возврат объекта из метода, создание экземпляра другого класса внутри реализации, ссылка на глобальный экземпляр.

**Статус: Архив / Read-Only.** Проект завершён, разработка и внесение изменений не планируются.

---

# developer-testing-playbook

Educational repository. A set of C++ console applications demonstrating classic approaches to software testing, starting from input data analysis and ending with verification of interactions between classes.

Implemented approaches:

**Equivalence Partitioning.** A "black-box" method. Input data is divided into classes within which the program behaves identically. For each class, at least one test sequence is selected. Construction rules: a test sequence may consist of a single element; different tests use sequences of different lengths; the key element is placed at the beginning, middle, and end of the sequence. It allows reducing the number of tests from exhaustive enumeration to a reasonable minimum while preserving coverage of the main scenarios.

**Structural Testing.** A "white-box" method. A control flow graph is built from the code, and McCabe's cyclomatic complexity is calculated, which defines the minimum number of independent paths that must be covered by tests. If all independent paths are executed, it is guaranteed that every statement runs at least once, and every condition is checked in both true and false branches. The method is applied to individual modules and methods.

**Unit Testing.** Verification of a single class in isolation against its specification. A test driver is used — an autonomous class that creates instances of the class under test, invokes its methods, and logs the results. A test case specification includes: class name, test name, logic description, input data, expected result. Testing is performed before integrating the class into other components;

**Integration Testing.** Verification of interactions between classes that have already passed unit testing. The goal is to ensure that objects exchange messages correctly, rather than verifying the system as a whole. Four types of interactions are identified: an object-typed parameter in a method signature, returning an object from a method, creating an instance of another class inside the implementation, and referencing a global instance.

**Status: Archive / Read-Only.** The project is completed, no further development or changes are planned.
