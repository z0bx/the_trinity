#ifndef SHAPE_HPP
#define SHAPE_HPP

#include <iostream>
#include <cstring>
using namespace std;

// Shape класс нь бусад хэлбэрийн суурь классын үүрэг гүйцэтгэдэг
class shape {
protected:
    // Хэлбэрийн нэр
    char* name;

public:
    // Конструктор, нэрийг initializ хийх
    shape() : name(nullptr) {}

    // Виртуал деструктор, хэрэв dynamically суулгасан бол нэрийг устгах
    virtual ~shape() {
        delete[] name;
    }

    // Хэлбэрийн нэрийг тохируулах функц
    void set_name(const char* n) {
        if (name != nullptr) {
            delete[] name;
        }
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    // Хэлбэрийн нэрийг авах функц
    char* get_name() {
        return name;
    }

    // Талбайг тооцоолох виртуал функц (дочер классууд дээр бичих шаардлагатай)
    virtual float area() = 0;

    // Хэлбэрийг хэвлэх виртуал функц (дочер классууд дээр бичих шаардлагатай)
    virtual void print() = 0;
};

#endif // SHAPE_HPP
