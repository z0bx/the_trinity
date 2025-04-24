#ifndef CIRCLE_HPP
#define CIRCLE_HPP

#include "twod.hpp"

// Circle класс нь twod классаас өвлөж авсан
class circle : public twod {
public:
    // Конструктор
    circle(int _a) : twod(_a) {
        set_name("Circle");
    }

    // Талбайг тооцоолох функц
    float area() override {
        return M_PI * a * a;
    }

    // Тойргийн уртыг тооцоолох функц
    float perimeter() override {
        return 2 * M_PI * a;
    }
};

#endif // CIRCLE_HPP
