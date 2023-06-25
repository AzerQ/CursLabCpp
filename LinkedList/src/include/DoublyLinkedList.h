#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "Node.h"
#include <iostream>
using namespace  std;
template <typename T>
class DoublyLinkedList {
public:
    DoublyLinkedList();
    ~DoublyLinkedList();

    void insert(const T& value);
    bool remove(const T& value);
    bool search(const T& value) const;
    void print() const;

private:
    Node<T>* head;
    Node<T>* tail;
};

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

template <typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    Node<T>* current = head;
    while (current != nullptr) {
        Node<T>* next = current->next;
        delete current;
        current = next;
    }
}

template <typename T>
void DoublyLinkedList<T>::insert(const T& value) {
    Node<T>* newNode = new Node<T>;
    newNode->value = value;
    newNode->prev = nullptr;
    newNode->next = nullptr;

    if (head == nullptr) {
        head = newNode;
        tail = newNode;
    } else {
        tail->next = newNode;
        newNode->prev = tail;
        tail = newNode;
    }
}

template <typename T>
bool DoublyLinkedList<T>::remove(const T& value) {
    Node<T>* current = head;
    while (current != nullptr) {
        if (current->value == value) {
            if (current == head) {
                head = current->next;
                if (head != nullptr) {
                    head->prev = nullptr;
                } else {
                    tail = nullptr;
                }
            } else if (current == tail) {
                tail = current->prev;
                if (tail != nullptr) {
                    tail->next = nullptr;
                } else {
                    head = nullptr;
                }
            } else {
                current->prev->next = current->next;
                current->next->prev = current->prev;
            }
            delete current;
            return true;
        }
        current = current->next;
    }
    return false;
}

template <typename T>
bool DoublyLinkedList<T>::search(const T& value) const {
    Node<T>* current = head;
    while (current != nullptr) {
        if (current->value == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

template <typename T>
void DoublyLinkedList<T>::print() const {
    Node<T>* current = head;
    while (current != nullptr) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << endl;
}

#endif // DOUBLYLINKEDLIST_H
