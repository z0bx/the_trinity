#ifndef TRIANGLE_HPP
#define TRIANGLE_HPP

#include "twod.hpp"

// Triangle класс нь twod классаас өвлөж авсан
class triangle : public twod {
public:
    // Конструктор
    triangle(int _a) : twod(_a) {
        set_name("Triangle");
    }

    // Талбайг тооцоолох функц
    float area() override {
        return (sqrt(3) / 4) * a * a;
    }

    // Тойргийн уртыг тооцоолох функц
    float perimeter() override {
        return 3 * a;
    }
};

#endif // TRIANGLE_HPP
