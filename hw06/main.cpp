#include <iostream>

#include "mylist.h"
#include "myvector.h"

template <typename T>
void Print(const T& t) {
    for (size_t i = 0; i < t.size(); ++i) {
        std::cout << t[i] << " ";
    }
    std::cout << std::endl;
}

void TestMyList() {
    // 1 создание объекта контейнера для хранения объектов типа int
    List<int> my_list;

    // 2 добавление в контейнер десяти элементов (0, 1 ... 9)
    for (int i = 0; i < 10; ++i) {
        my_list.push_back(i);
    }

    // 3 вывод содержимого контейнера на экран
    Print(my_list);

    // 4 вывод размера контейнера на экран
    std::cout << "Size: " << my_list.size() << std::endl;

    // 5 удаление третьего (по счёту), пятого и седьмого элементов
    my_list.erase(6); // 7
    my_list.erase(4); // 5
    my_list.erase(2); // 3

    // 6 вывод размера контейнера на экран
    Print(my_list);

    // 7 добавление элемента 10 в начало контейнера
    my_list.push_front(10);

    // 8 вывод размера контейнера на экран
    Print(my_list);

    // 9 добавление элемента 20 в середину контейнера
    my_list.insert(my_list.size() / 2, 20);

    // 10 вывод размера контейнера на экран
    Print(my_list);

    // 11 добавление элемента 30 в конец контейнера
    my_list.push_back(30);

    // 12 вывод размера контейнера на экран
    Print(my_list);
}

void TestMyVector() {
    // 1 создание объекта контейнера для хранения объектов типа int
    Vector<int> my_vector;

    // 2 добавление в контейнер десяти элементов (0, 1 ... 9)
    for (int i = 0; i < 10; ++i) {
        my_vector.push_back(i);
    }

    // 3 вывод содержимого контейнера на экран
    Print(my_vector);

    // 4 вывод размера контейнера на экран
    std::cout << "Size: " << my_vector.size() << std::endl;

    // 5 удаление третьего (по счёту), пятого и седьмого элементов
    my_vector.erase(6); // 7
    my_vector.erase(4); // 5
    my_vector.erase(2); // 3

    // 6 вывод размера контейнера на экран
    Print(my_vector);

    // 7 добавление элемента 10 в начало контейнера
    my_vector.insert(0, 10);

    // 8 вывод размера контейнера на экран
    Print(my_vector);

    // 9 добавление элемента 20 в середину контейнера
    my_vector.insert(my_vector.size() / 2, 20);

    // 10 вывод размера контейнера на экран
    Print(my_vector);

    // 11 добавление элемента 30 в конец контейнера
    my_vector.push_back(30);

    // 12 вывод размера контейнера на экран
    Print(my_vector);
}

int main() {
    std::cout << "--- Testing List ---" << std::endl;
    TestMyList();
    std::cout << std::endl;

    std::cout << "--- Testing Vector ---" << std::endl;
    TestMyVector();
}
