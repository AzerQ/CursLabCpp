#ifndef DOUBLYLINKEDLIST_H
#define DOUBLYLINKEDLIST_H

#include "Node.h"
#include <iostream>

using namespace std;

template<typename T>
class DoublyLinkedList {
public:
    DoublyLinkedList();

    ~DoublyLinkedList();

    void insert(const T &value);

    bool remove(const T &value);

    bool search(const T &value) const;

    void print() const;

    Node<T> getHead();

    Node<T> getTail();

    int getCount();

    Node<T> *getElementByIndex(int index);

private:
    Node<T> *head;
    Node<T> *tail;
    int count = 0;


};

template<typename T>
int DoublyLinkedList<T>::getCount() {
    return count;
}


template<typename T>
DoublyLinkedList<T>::DoublyLinkedList() : head(nullptr), tail(nullptr) {}

template<typename T>
DoublyLinkedList<T>::~DoublyLinkedList() {
    Node<T> *current = head;
    while (current != nullptr) {
        Node<T> *next = current->next;
        delete current;
        current = next;
    }
}

template<typename T>
void DoublyLinkedList<T>::insert(const T &value) {
    Node<T> *newNode = new Node<T>;
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
    count++;
}

template<typename T>
Node<T> DoublyLinkedList<T>::getHead() {
    return *head;
}

template<typename T>
Node<T> DoublyLinkedList<T>::getTail() {
    return *tail;
}


template<typename T>
bool DoublyLinkedList<T>::remove(const T &value) {

    Node<T> *current = head;
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
            count--;
            return true;
        }
        current = current->next;
    }
    return false;
}

template<typename T>
bool DoublyLinkedList<T>::search(const T &value) const {
    Node<T> *current = head;
    while (current != nullptr) {
        if (current->value == value) {
            return true;
        }
        current = current->next;
    }
    return false;
}

template<typename T>
void DoublyLinkedList<T>::print() const {
    cout << "[ elements count = "  << count << " ] " << "{ ";
    Node<T> *current = head;
    while (current != nullptr) {
        cout << current->value << " ";
        current = current->next;
    }
    cout << "}" << endl;
}

template<typename T>
Node<T> *DoublyLinkedList<T>::getElementByIndex(int index) {
    if (index < 0 || index >= count) {
        return nullptr;
    }

    Node<T> *current = nullptr;

    // Если индекс в первой половине списка, идем от начала
    if (index < count / 2) {
        current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
    }
        // Если индекс во второй половине списка, идем от конца
    else {
        current = tail;
        for (int i = count - 1; i > index; i--) {
            current = current->prev;
        }
    }
    return current;
}

#endif // DOUBLYLINKEDLIST_H
