#include <iostream>
#include "include/DoublyLinkedList.h"

int main() {
    DoublyLinkedList<int> list;

    list.insert(10);
    list.insert(20);
    list.insert(30);
    list.insert(40);

    std::cout << "List: ";
    list.print();

    std::cout << "Searching for value 30: ";
    if (list.search(30)) {
        std::cout << "Found" << std::endl;
    } else {
        std::cout << "Not found" << std::endl;
    }

    std::cout << "Removing value 20" << std::endl;
    if (list.remove(20)) {
        std::cout << "Removed successfully" << std::endl;
    } else {
        std::cout << "Failed to remove" << std::endl;
    }

    std::cout << "List after removal: ";
    list.print();

    return 0;
}