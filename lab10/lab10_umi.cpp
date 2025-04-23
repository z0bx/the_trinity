#include <iostream>
#include <string.h>
#include <cmath>
#include <cstdlib>  // rand(), srand()
#include <ctime>    // time()
using namespace std;

//shape болон twod төрлийн классууд

// Суурь класс - shape
class shape {
protected:
    char *name;  // Дүрсний нэрийг хадгалах
public:
    shape() : name(nullptr) {}  // Анхдагч байгуулагч
    virtual ~shape() { delete[] name; }  // Санах ойг чөлөөлнө

    char *get_name() { return this->name; }  // Нэр авах функц
    void set_name(const char *n) {  // Нэр оноох функц
        if (name != nullptr) delete[] name;
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    virtual void print() { cout << name << " "; }  // Дүрсийн нэр хэвлэх
};

// 2D дүрсийн суурь класс
class twod : public shape {
protected:
    int a;  // хэмжээ (тал, радиус гэх мэт)
public:
    twod(int _a) : a(_a) {}

    virtual float area() = 0;  // Талбайг бодох цэвэр виртуал функц

    virtual void print() {
        shape::print();  // нэр хэвлэх
        cout << a << " ";  // хэмжээ хэвлэх
        cout << this->area() << endl;  // талбайг хэвлэх
    }
};

// Circle класс (дугуй)
class circle : public twod {
public:
    circle(int _a) : twod(_a) { set_name("Circle"); }

    float area() override { return M_PI * a * a; }  // πr²
};

// Square класс (квадрат)
class square : public twod {
public:
    square(int _a) : twod(_a) { set_name("Square"); }

    float area() override { return a * a; }  // a²
};

// Triangle класс (тэнцүүхэн хажуут гурвалжин)
class triangle : public twod {
public:
    triangle(int _a) : twod(_a) { set_name("Triangle"); }

    float area() override { return (sqrt(3) / 4) * a * a; }  // (√3 / 4) * a²
};

// ===================== Template LinkedList класс =====================
template <typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(const T& _data) : data(_data), next(nullptr) {}
    };
    Node* head;
    int size;

public:
    LinkedList() : head(nullptr), size(0) {}

    ~LinkedList() {
        while (head != nullptr) {  // Бүх зангилааг устгана
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void add(T t) {
        Node* newNode = new Node(t);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node* p = head;
            while (p->next != nullptr) p = p->next;
            p->next = newNode;
        }
        size++;
    }

    void insert(T t, int index) {
        if (index < 0 || index > size) return;
        Node* newNode = new Node(t);
        if (index == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* p = head;
            for (int i = 0; i < index - 1; i++) p = p->next;
            newNode->next = p->next;
            p->next = newNode;
        }
        size++;
    }

    T get(int index) {
        Node* p = head;
        for (int i = 0; i < index; i++) p = p->next;
        return p->data;
    }

    void remove(int index) {
        if (index < 0 || index >= size) return;
        Node* temp;
        if (index == 0) {
            temp = head;
            head = head->next;
        } else {
            Node* p = head;
            for (int i = 0; i < index - 1; i++) p = p->next;
            temp = p->next;
            p->next = p->next->next;
        }
        delete temp;
        size--;
    }

    int length() { return size; }

    T& operator[](int index) {
        Node* p = head;
        for (int i = 0; i < index; i++) p = p->next;
        return p->data;
    }
};

// ===================== Main функц =====================
int main() {
    srand(time(0));  // random seed

    LinkedList<twod*> shapes;  // 2D дүрсүүдийн жагсаалт

    int n = rand() % 11 + 20;  // 20-30 тооны дүрс үүсгэнэ

    for (int i = 0; i < n; i++) {
        int shapeType = rand() % 3;  // 0=circle, 1=square, 2=triangle
        int size = rand() % 20 + 1;  // Хэмжээ 1-20

        switch (shapeType) {
            case 0: shapes.add(new circle(size)); break;
            case 1: shapes.add(new square(size)); break;
            case 2: shapes.add(new triangle(size)); break;
        }
    }

    // Bubble sort - талбайгаар эрэмбэлэх
    for (int i = 0; i < shapes.length() - 1; i++) {
        for (int j = 0; j < shapes.length() - i - 1; j++) {
            if (shapes[j]->area() > shapes[j + 1]->area()) {
                swap(shapes[j], shapes[j + 1]);  // солих
            }
        }
    }

    // Эрэмбэлсэн дүрсүүдийг хэвлэх
    cout << "Shapes sorted by area:" << endl;
    for (int i = 0; i < shapes.length(); i++) {
        shapes[i]->print();
    }

    // Санах ой чөлөөлөх (дүрсүүдийг устгах)
    for (int i = 0; i < shapes.length(); i++) {
        delete shapes[i];
    }

    return 0;
}
