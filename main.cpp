#include <iostream>
#include <cstring> //strcpy(), strlen()
#include <cmath>   // M_PI, sqrt()
using namespace std;

// Shape classiig todorkhoilj baina
class shape {
    protected:
        //Bursiin neriigkhadgalakh zoriulalttai dinamic turliin massiv
        char *name;
    
        //Static khuvtsagch: bukh 'shape' bolon tuunii udam claasiin objectiin toog khadgalakh
        static int object_count;
    public:
        //Ankhdagch baiguulagch(constructor)
        shape() : name(nullptr) {
            //Object-uusgekh burt object_count 1-eer nemegdene
            this -> object_count++; // this ашиглаж object_count руу хандаж байна
        }
        // Ustagagch (destructor) funkts - objectiig sanakh oigoos ustgakh uyd duudagdana
        virtual ~shape() {
            //Khereb name ni nullptr bish bol sanakh oig chuluulnu
            delete[] this name; // this ашиглаж name-г чөлөөлөх
            this -> object_count--; // this ашиглаж object_count руу хандах
    
            //Object ustgakh burt object_count 1-eer bagsana
            object_count--;
        }
    
        //Utga onookh static funkts
        static void set_count(int count) {
            object_count = count;
        }
    
        //Utga abakh static funkts
        static int get_count() {
            return object_count;
        }
    
        //Odoogiin object-iin toog kheblekh
        static void print_count() {
            cout << "Niit object: " << object_count << endl;
        }
    
        //Objectiin neriig butsaakh funkts
        char *get_name() { 
            return this->name; //this нь тухайн объектын name гишүүнд хандаж байна.
        } 
        //Objectiin neriig tikhiruulakh funkts
        void set_name(const char *n) { 
            //Khereb umnun ner ugsun bol sabakh oig chuluulnu
            if (this -> name != nullptr) //this-ээр тухайн объектоос name гишүүн рүү шууд хандаж байнан.
                delete[] this -> name;

    
            //Shine nert zoriulj sanakh oi gargakh, khuulakh
            this -> name = new char[strlen(n) + 1]; // +1 ni tugsguliin '\0'-g zuriulagdsan
            strcpy(this -> name, n); //temdegt muriig khuulna
        }
        virtual void print() { cout << name << " "; }
    };
    
//Static khuvtsagchiig classiin gadna tald uusgej baina
int shape::object_count = 0; //Ankhdagch utga 0 object baina
    

class twod : public shape
{
protected:
    int a;

public:
    twod(int _a) : a(_a) {}        // анхдагч байгуулагч
    virtual float area() = 0;      // талбай хадгалах жинхэнэ хийсвэр функц
    virtual float perimeter() = 0; // периметр хадгалах жинхэнэ хийсвэр функц
    virtual void print() // хэвлэх функц - нэр, хэмжээ, талбай, периметр
    {
        shape::print();
        cout << a << " ";
        cout << "talbai:" << this -> area() << endl;
        cout << "perimeter:" << this -> perimeter() << endl; // виртуал функцүүдийг тухайн объектын төрлөөс хамаарч дуудуулж байна
    }
};

// Square class
class circle : public twod {
public:
    circle(int _a) : twod(_a) { 
        this -> set_name("Circle"); 
    }

    float area() override {
        return M_PI * a * a;
    }
    float perimeter() override
    {
        return M_PI * 2 * a;
    }
};

// Square class 
class square : public twod {
public:
    square(int _a) : twod(_a) {
        this -> set_name("Square");
    }
    
    float area() override {
        return a * a;
    }

    float perimeter() override {
        return 4 * a;
    }
};

// Traingle class
class triangle : public twod {
public:
    triangle(int _a) : twod(_a) {
        this -> set_name("Triangle");
    }

    float area() override {
        return (sqrt(3) / 4) * a * a;
    }

    float perimeter() override {
        return 3 * a;
    }
};

int main()
{
    int size;
    cout << "heden durs oruulah ve?: " << endl;
    cin >> size;
    
    twod **shapes = new twod *[size]; // twod* руу заасан динамик массив зарлаж байна.
    
    // Дүрсүүдийг оруулж буй давталт
    for (int i = 0; i < size; i++)
    {
        int k;
        int a;
        cout << "durs " << i << ": " << endl
             << "1. Square" << endl
             << "2. Triangle" << endl
             << "3. Circle" << endl;
        cin >> k;
        cout << "a: ";
        cin >> a;
        // Сонголтоор обьект үүсгэх
        switch (k)
        {
        case 1:
            shapes[i] = new square(a);
            break;
        case 2:
            shapes[i] = new triangle(a);
            break;
        case 3:
            shapes[i] = new circle(a);
            break;
        default:
            cout << "Buruu songolt hiilee, dahin hiine uu: " << endl;
            i--;
            break;
        }
    }
    
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
    for (int i = 0; i < size; i++) {
        shapes[i]->print();
        cout << endl;
    }
    // Санах ойгоос чөлөөлөх
    for (int i = 0; i < size; i++) {
        delete shapes[i];
    }
    delete[] shapes;
    
    return 0;
}
