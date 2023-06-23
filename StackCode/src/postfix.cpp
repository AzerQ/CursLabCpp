#include "include/postfix.h"
#include <iostream>

int get_precedence(char op)
{
    switch (op)
    {
    case '+':
    case '-':
        return 1;
    case '*':
    case '/':
        return 2;
    case '^':
        return 3;
    default:
        return 0;
    }
}

std::string infix_to_postfix(std::string infix)
{
    //std::cout << infix;
    CustomStack::Stack<char> stack;
    std::string postfix;

    for (char c : infix)
    {
        if (std::isdigit(c))
        {
            postfix += c;
        }
        else if (c == '(')
        {
            CustomStack::push(stack, c);
        }
        else if (c == ')')
        {
            while (!CustomStack::isEmpty(stack) && CustomStack::peek(stack).has_value() && CustomStack::peek(stack).value() != '(')
            {
                auto popped = CustomStack::pop(stack);
                if (popped.has_value())
                {
                    postfix += popped.value();
                }
            }
            if (!CustomStack::isEmpty(stack))
            {
                CustomStack::pop(stack); // Pop the '('
            }
        }
        else
        { // If the character is an operator
            while (!CustomStack::isEmpty(stack) && get_precedence(c) <= get_precedence(CustomStack::peek(stack).value_or(0)))
            {
                std::optional<char> popped;
                try
                {
                    popped = CustomStack::pop(stack);
                }
                catch (const std::exception &e)
                {
                }
                if (popped.has_value())
                {
                    postfix += popped.value();
                }
            }
            CustomStack::push(stack, c);
        }
    }

    // Pop any remaining operators from the stack and add to postfix
    while (!CustomStack::isEmpty(stack))
    {
        auto popped = CustomStack::pop(stack);
        if (popped.has_value())
        {
            postfix += popped.value();
        }
    }

    return postfix;
}