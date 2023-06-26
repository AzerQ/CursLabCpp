//
// Created by AzerQ on 26.06.2023.
//

#ifndef LINKEDLIST_SETCOLOR_H
#define LINKEDLIST_SETCOLOR_H
#include <iostream>

// Цвета текста
enum class TextColor {
    Default = 0,
    Black = 30,
    Red,
    Green,
    Yellow,
    Blue,
    Magenta,
    Cyan,
    White
};

// Цвета фона
enum class BackgroundColor {
    Default = 0,
    Black = 40,
    Red,
    Green,
    Yellow,
    Blue,
    Magenta,
    Cyan,
    White
};

// Функция для установки цвета текста и фона
void setColor(TextColor textColor, BackgroundColor bgColor) {
    std::cout << "\033[" << static_cast<int>(textColor) << "m";   // устанавливаем цвет текста
    std::cout << "\033[" << static_cast<int>(bgColor) << "m";    // устанавливаем цвет фона
}

void clearColors(){
    setColor(TextColor::Default, BackgroundColor::Default);
}
#endif //LINKEDLIST_SETCOLOR_H
