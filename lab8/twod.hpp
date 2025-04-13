#ifndef TWOD_HPP
#define TWOD_HPP
#include "shape.hpp"
// Shape class-аас удамшсан twod class
class twod : public shape
{
protected:
    int a; // Талын урт эсвэл радиусыг хадгалах гишүүн өгөгдөл

public:
    twod(int _a) : a(_a) {}        // анхдагч байгуулагч
    virtual float area() = 0;      // талбай хадгалах жинхэнэ хийсвэр функц
    virtual float perimeter() = 0; // периметр хадгалах жинхэнэ хийсвэр функц
    virtual void print() override  // хэвлэх функц - нэр, хэмжээ, талбай, периметр
    {
        this->shape::print(); // Shape class-н print-г дуудаж байна
        cout << this->a << " ";
        // виртуал функцүүдийг тухайн объектын төрлөөс хамаарч дуудуулж байна
        cout << "talbai:" << this->area() << endl;
        cout << "perimeter:" << this->perimeter() << endl;
    }
};

#endif