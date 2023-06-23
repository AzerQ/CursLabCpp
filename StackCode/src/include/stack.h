#pragma once
#include <optional>

namespace CustomStack
{
    template <typename T>
    struct Node
    {
        T data;
        Node<T>* next;
    };

    template <typename T>
    struct Stack
    {
        Node<T>* top;
    };

    template <typename T>
    Stack<T> CreateStack()
    {
        return Stack<T> { nullptr };
    }

    template <typename T>
    void push(Stack<T>& stack, T value)
    {
        Node<T>* node = new Node<T> { value, stack.top };
        stack.top = node;
    }

    template <typename T>
    std::optional<T> pop(Stack<T>& stack)
    {
        if (stack.top == nullptr)
        {
            return {};
        }
        else
        {
            Node<T>* node = stack.top;
            T value = node->data;
            stack.top = node->next;
            delete node;
            return value;
        }
    }

    template <typename T>
    bool isEmpty(const Stack<T>& stack)
    {
        return stack.top == nullptr;
    }

    template <typename T>
    std::optional<T> peek(const Stack<T>& stack)
    {
        if (stack.top == nullptr)
        {
            return {};
        }
        else
        {
            return stack.top->data;
        }
    }
}
