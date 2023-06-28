#include <iostream>
#include "include/DoublyLinkedList.h"
#include "SetColor.h"
#include <cstdlib> // для rand() и srand()
#include <ctime>   // для time()

void testDoublyLinkedList(int N) {
    const int MAX_VALUE = 40;
    const int MIN_VALUE = 20;
    auto getRand { [](){return (rand() % (MAX_VALUE - MIN_VALUE + 1) + MIN_VALUE);} };
    DoublyLinkedList<int> list;
    srand(time(0)); // Инициализация генератора случайных чисел

    // Заполнение списка случайными числами
    for (int i = 0; i < N; i++) {
        int randomNumber = getRand(); // Случайное число от 20 до 200
        list.insert(randomNumber);
        //cout << "Inserted " << randomNumber << " into the list." << endl;
    }

    // Вывод списка
    cout << "List after insertion: ";
    list.print();

    // Поиск элемента в списке
    int searchNumber = getRand(); // Случайное число от 20 до 200
    bool found = list.search(searchNumber);
    cout << "Is " << searchNumber << " in the list? " << (found ? "Yes" : "No") << endl;

    // Удаление элемента из списка
    int removeNumber = getRand(); // Случайное число от 20 до 200
    bool removed = list.remove(removeNumber);
    cout << "Was " << removeNumber << " removed from the list? " << (removed ? "Yes" : "No") << endl;

    // Вывод списка после удаления
    cout << "List after removal: ";
    list.print();

    // Поиск элемента по индексу
    int index = rand() % N; // Случайный индекс
    Node<int>* node = list.getElementByIndex(index);
    if (node != nullptr) {
        cout << "Element at index " << index << ": " << node->value << endl;
    } else {
        cout << "No element at index " << index << endl;
    }
}

int main() {
    int listCapacity;
    cout << "Enter list capacity = ";
    cin >> listCapacity;
    testDoublyLinkedList(listCapacity);
    getchar();
    return 0;
}