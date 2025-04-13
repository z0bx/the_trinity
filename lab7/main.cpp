#include <iostream>
#include <cstring> //strcpy(), strlen()
#include <cmath>   // M_PI, sqrt()
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

// Static хувьсагчийг классын гадна талд үүсгэж байна
int shape::object_count = 0; // Анхдагч утга оноож байна

// Shape class-аас удамшсан twod class
class twod : public shape
{
protected:
    int a; // Талын урт эсвэл радиусыг хадгалах гишүүн өгөгдөл

public:
    twod(int _a) : a(_a) {}        // анхдагч байгуулагч
    virtual float area() = 0;      // талбай хадгалах жинхэнэ хийсвэр функц
    virtual float perimeter() = 0; // периметр хадгалах жинхэнэ хийсвэр функц
    virtual void print()  override         // хэвлэх функц - нэр, хэмжээ, талбай, периметр
    {
        this -> shape::print(); // Shape class-н print-г дуудаж байна
        cout << this -> a << " ";
        // виртуал функцүүдийг тухайн объектын төрлөөс хамаарч дуудуулж байна
        cout << "talbai:" << this->area() << endl;
        cout << "perimeter:" << this->perimeter() << endl;
    }
};

// twod-гээс удамшсан Circle class
class circle : public twod
{
public:
    circle(int _a) : twod(_a) // анхдагч байгуулагч
    {
        this -> set_name("Circle"); // нэрийг Circle болгон тохируулна
    }

    float area() override // area-г дахин тодорхойлно
    {
        return M_PI * this -> a * this -> a; // дугуйн талбайг буцаана
    }
    float perimeter() override // perimeter-г дахин тодорхойлно
    {
        return M_PI * 2 * this -> a; // дугуйн периметрийг буцаана
    }
};

// twod-гээс удамшсан Square class
class square : public twod
{
public:
    square(int _a) : twod(_a) // анхдагч байгуулагч
    {
        this -> set_name("Square"); // нэриийг Square болгон тохируулна
    }

    float area() override // area-г дахин тодорхойлно
    {
        return this -> a * this -> a; // квадратын талбайг буцаана
    }

    float perimeter() override // perimeter-г дахин тодорхойлно
    {
        return 4 * this -> a; // квадратын периметрийг буцаана
    }
};

// twod-гээс удамшсан Traingle class
class triangle : public twod
{
public:
    triangle(int _a) : twod(_a) // анхдагч байгуулагч
    {
        this -> set_name("Triangle"); // нэриийг Triangle болгон тохируулна
    }

    float area() override // area-г дахин тодорхойлно
    {
        return (sqrt(3) / 4) * this -> a * this -> a; // зөв гурвалжингийн талбайг буцаана
    }

    float perimeter() override // perimeter-г дахин тодорхойлно
    {
        return 3 * this -> a; // зөв гурвалжингийн периметрийг буцаана
    }
};
// main функц
int main()
{
    cout << "Objectiin too: ";
    shape::print_count(); //Static хувьсагч дамжуулсан статик хэвлэх функцийг дуудаж байна
    int size; // дүрсүүдийн объектийн тоон хэмжээтэй массивийн хэмжээ
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
