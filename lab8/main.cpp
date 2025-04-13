#include "shape.hpp"
#include "twod.hpp"
#include "circle.hpp"
#include "square.hpp"
#include "triangle.hpp"
using namespace std;

// Static хувьсагчийг классын гадна талд үүсгэж байна
int shape::object_count = 0; // Анхдагч утга оноож байна

// main функц
int main()
{
    cout << "Objectiin too: ";
    shape::print_count(); // Static хувьсагч дамжуулсан статик хэвлэх функцийг дуудаж байна
    int size;             // дүрсүүдийн объектийн тоон хэмжээтэй массивийн хэмжээ
    cout << "heden durs oruulah ve?: " << endl;
    cin >> size; // хэмжээний утгыг гараас авна

    twod **shapes = new twod *[size]; // twod* руу заасан динамик массив зарлаж байна.

    // Дүрсүүдийг оруулж буй давталт
    for (int i = 0; i < size; i++)
    {
        int k; // Дүрсийн сонголтыг хадгалах хувсагч
        int a; // Тал эсвэл радиусын утгыг хадгалах хувьсагч
        // Хэрэглэгчид зориулсан дүрсийг сонгох цэс
        cout << "durs " << i + 1 << ": " << endl
             << "1. Square" << endl
             << "2. Triangle" << endl
             << "3. Circle" << endl;
        cin >> k; // Сонголтын утгыг гараас авна
        // а-н утгыг гараас авна
        cout << "a: ";
        cin >> a;
        // Сонголтоор обьектон массив үүсгэх switch case
        switch (k)
        {
        case 1:
            shapes[i] = new square(a); // хэрэв k-н утга 1 бол square объект үүсгэнэ
            break;
        case 2:
            shapes[i] = new triangle(a); // хэрэв k-н утга 2 бол square объект үүсгэнэ
            break;
        case 3:
            shapes[i] = new circle(a); // хэрэв k-н утга 3 бол square объект үүсгэнэ
            break;
        // 1, 2, 3-с өөр утга оруулбал массивт өөр объект үүсгэх
        default:
            cout << "Buruu songolt hiilee, dahin hiine uu: " << endl;
            i--;
            break;
        }
    }
    cout << "Objectiin too: " << shape::get_count() << endl; // Static нийлбэрийн утга буцаах функцыг дуудан хэвлэж байна
    // Bubble sort ашиглан талбайгаар эрэмбэлнэ.
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (shapes[j]->area() > shapes[j + 1]->area())
            {
                twod *temp = shapes[j];
                shapes[j] = shapes[j + 1];
                shapes[j + 1] = temp;
            }
        }
    }
    // Талбайгаар эрэмбэлсэн дүрсүүдээ хэвлэнэ.
    cout << "Talbaigaar erembelegdsen ni:" << endl;
    for (int i = 0; i < size; i++)
    {
        shapes[i]->print();
        cout << endl;
    }
    // Bubble sort ашиглан периметрээр эрэмбэлнэ.
    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (shapes[j]->perimeter() > shapes[j + 1]->perimeter())
            {
                twod *temp = shapes[j];
                shapes[j] = shapes[j + 1];
                shapes[j + 1] = temp;
            }
        }
    }
    // Периметрээр эрэмбэлсэн дүрсүүдээ хэвлэнэ.
    cout << "Perimetereer erembelegdsen ni:" << endl;
    for (int i = 0; i < size; i++)
    {
        shapes[i]->print();
        cout << endl;
    }
    // Санах ойгоос чөлөөлөх
    for (int i = 0; i < size; i++)
    {
        delete shapes[i];
    }
    delete[] shapes;

    return 0;
}
