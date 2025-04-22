#ifndef SHAPE_HPP
#define SHAPE_HPP
#include <iostream>
#include <cstring>
using namespace std;
// Shape class-г тодорхойлж байна
class shape
{
protected:
    // Дүрсийн нэрийг хадгалах динамик массив
    char *name;

    // Static хувьсагч: бүх 'shape' болон түүнээс удамшсан классын объектийн тоог хадгалах
    static int object_count;

public:
    // Анхдагч байгуулагч
    shape() : name(nullptr)
    {
        // Объект үүсгэх үед object_count 1-ээр нэмэгдэнэ
        this->object_count++; // this ашиглаж object_count руу хандаж байна
    }
    // Устгагч (destructor) функц - объектийг санах ойгоос устгах үед дуудагдана
    virtual ~shape()
    {
        // Хэрэв name нь nullptr биш бол санах ойг чөлөөлнө
        delete[] name;        // name-г чөлөөлөх
        this->object_count--; // this ашиглаж object_count руу хандах

        // Объект устгах бүрт object_count 1-ээр багасна
        object_count--;
    }

    // Утга оноох статик функц
    static void set_count(int count)
    {
        object_count = count;
    }

    // Утга авах статик функц
    static int get_count()
    {
        return object_count;
    }

    // Одоогийн объектийн утгыг хэвлэх
    static void print_count()
    {
        cout << "Niit object: " << object_count << endl;
    }

    // Объектийн нэрийг буцаах функц
    char *get_name()
    {
        return this->name; // this нь тухайн объектын name гишүүнд хандаж байна.
    }
    // Объектийн нэрийг тохируулах функц
    void set_name(const char *n)
    {
        // Хэрэв өмнө нь нэр өгсөн бол санах ойг чөлөөлнө
        if (this->name != nullptr) // this-ээр тухайн объектоос name гишүүн рүү шууд хандана
            delete[] this->name;   // Санах ойгоос чөлөөлнө

        // Шинэ нэрт зориулж санах ой гаргах, хуулах
        this->name = new char[strlen(n) + 1]; // +1 нь төгсгөлийн '\0'- д зориулагдсан
        strcpy(this->name, n);                // тэмдэгт мөрийг хуулна
    }
    virtual void print() { cout << name << " "; }
};
#endif