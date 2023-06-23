#include <iostream>
#include "include/postfix.h"
#include "include/stack.h"
#include <random>
using namespace std;

void TestStack()
{
    cout << "TestStack called" << endl;
       // Создаем пустой стек
    CustomStack::Stack<int> stack = CustomStack::CreateStack<int>();

    // Генератор случайных чисел
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> dis(0, 100);

    // Случайное количество элементов
    int n = dis(gen);

    // Добавляем случайное количество элементов в стек
    for (int i = 0; i < n; ++i) {
        CustomStack::push(stack, i);
    }

    std::cout << "Added " << n << " elements to stack." << std::endl;

    // Удаляем элементы из стека и печатаем их
    while(!CustomStack::isEmpty(stack)) {
        if(auto val = CustomStack::pop(stack)) {
            std::cout << "Popped element: " << *val << std::endl;
        }
    }

    // Проверяем, пуст ли стек
    std::cout << "Stack is empty: " << (CustomStack::isEmpty(stack) ? "Yes" : "No") << std::endl;
}

void TestPostFix()
{
    try
    {
        cout << "TestPostFix called" << endl;
        std::string infix;
        std::cout << "Enter an infix expression: ";
        std::cin >> infix;
        //std::cout << infix << '\n';
        std::string postfix = infix_to_postfix(infix);
        std::cout << "Postfix expression: " << postfix << '\n';
    }
    catch (const std::exception &e)
    {
        std::cout << "Ошибка: " << e.what() << std::endl;
    }
}
int main()
{
    int userChoise = 0;
    cout << "Choise mode \n 1) TestStack \n 2) TestPostFix \nYou choise: ";
    cin >> userChoise;
    switch (userChoise)
    {
    case 1:
        TestStack();
        break;
    case 2:
        TestPostFix();
        break;
    default:
        break;
    }
    cin.get();
    return 0;
}