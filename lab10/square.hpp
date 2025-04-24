#ifndef SQUARE_HPP
#define SQUARE_HPP

#include "twod.hpp"

// Square класс нь twod классаас өвлөж авсан
class square : public twod {
public:
    // Конструктор
    square(int _a) : twod(_a) {
        set_name("Square");
    }

    // Талбайг тооцоолох функц
    float area() override {
        return a * a;
    }

    // Тойргийн уртыг тооцоолох функц
    float perimeter() override {
        return 4 * a;
    }
};

#endif // SQUARE_HPP
