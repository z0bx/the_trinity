#ifndef TWOD_HPP
#define TWOD_HPP

#include "shape.hpp"
#include <cmath>   // M_PI, sqrt()

// twod класс нь shape классаас өвлөж авсан
class twod : public shape {
protected:
    int a; // Хэмжээ буюу талбайг тооцоолох тал

public:
    // Конструктор
    twod(int _a) : a(_a) {}

    // Талбай болон тойргийн уртыг тооцоолох виртуал функц
    virtual float area() = 0;
    virtual float perimeter() = 0;

    // Хэлбэрийг хэвлэх функц
    virtual void print() override {
        cout << name << " ";
        cout << "Size: " << a << " ";
        cout << "Area: " << area() << " ";
        cout << "Perimeter: " << perimeter() << endl;
    }
};

#endif // TWOD_HPP
