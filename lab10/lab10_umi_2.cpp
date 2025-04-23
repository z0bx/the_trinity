#include <iostream>
#include <cmath>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

// Abstract base class
class shape {
protected:
    char *name;
public:
    shape() : name(nullptr) {}
    virtual ~shape() { delete[] name; }
    char *get_name() { return this->name; }
    void set_name(const char *n) {
        if (name != nullptr) delete[] name;
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }
    virtual float area() = 0;
    virtual void print() {
        cout << name << " ";
    }
};

// 2D shape base class
class twod : public shape {
protected:
    int a;
public:
    twod(int _a) : a(_a) {}
    virtual float area() = 0;
    virtual void print() override {
        shape::print();
        cout << a << " ";
        cout << this->area() << endl;
    }
};

class circle : public twod {
public:
    circle(int _a) : twod(_a) { set_name("Circle"); }
    float area() override {
        return M_PI * a * a;
    }
};

class square : public twod {
public:
    square(int _a) : twod(_a) { set_name("Square"); }
    float area() override {
        return a * a;
    }
};

class triangle : public twod {
public:
    triangle(int _a) : twod(_a) { set_name("Triangle"); }
    float area() override {
        return (sqrt(3) / 4) * a * a;
    }
};

// Загвар класс бүхий LinkedList
template<typename T>
class LinkedList {
private:
    struct Node {
        T data;
        Node* next;
        Node(T d) : data(d), next(nullptr) {}
    };
    Node* head;
    int count;

public:
    LinkedList() : head(nullptr), count(0) {}

    ~LinkedList() {
        while (head != nullptr) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
    }

    void add(T t) {
        Node* newNode = new Node(t);
        if (!head) head = newNode;
        else {
            Node* cur = head;
            while (cur->next) cur = cur->next;
            cur->next = newNode;
        }
        count++;
    }

    void insert(T t, int index) {
        if (index < 0 || index > count) return;
        Node* newNode = new Node(t);
        if (index == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            Node* cur = head;
            for (int i = 0; i < index - 1; i++) cur = cur->next;
            newNode->next = cur->next;
            cur->next = newNode;
        }
        count++;
    }

    T get(int index) {
        Node* cur = head;
        for (int i = 0; i < index; i++) cur = cur->next;
        return cur->data;
    }

    void remove(int index) {
        if (index < 0 || index >= count) return;
        Node* temp;
        if (index == 0) {
            temp = head;
            head = head->next;
        } else {
            Node* cur = head;
            for (int i = 0; i < index - 1; i++) cur = cur->next;
            temp = cur->next;
            cur->next = temp->next;
        }
        delete temp;
        count--;
    }

    int length() { return count; }

    void bubble_sort_by_area() {
        if (!head || !head->next) return;

        for (int i = 0; i < count - 1; ++i) {
            Node* cur = head;
            Node* prev = nullptr;
            while (cur && cur->next) {
                twod* a = dynamic_cast<twod*>(cur->data);
                twod* b = dynamic_cast<twod*>(cur->next->data);
                if (a && b && a->area() > b->area()) {
                    // Swap nodes
                    Node* temp = cur->next;
                    cur->next = temp->next;
                    temp->next = cur;
                    if (prev) prev->next = temp;
                    else head = temp;
                    prev = temp;
                } else {
                    prev = cur;
                    cur = cur->next;
                }
            }
        }
    }

    void print_all() {
        Node* cur = head;
        while (cur) {
            cur->data->print();
            cur = cur->next;
        }
    }
};

// Main function
int main() {
    srand(time(0));

    LinkedList<twod*> list;

    int n = rand() % 11 + 20; // 20-30 ширхэг
    for (int i = 0; i < n; i++) {
        int type = rand() % 3;
        int size = rand() % 10 + 1;
        if (type == 0) list.add(new circle(size));
        else if (type == 1) list.add(new square(size));
        else list.add(new triangle(size));
    }

    cout << "\nBefore sorting:\n";
    list.print_all();

    list.bubble_sort_by_area();

    cout << "\nAfter sorting by area:\n";
    list.print_all();

    return 0;
}
