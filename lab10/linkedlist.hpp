#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>
using namespace std;

// Node бүтэц нь LinkedList-ийн бүрэлдэхүүн хэсэг
template <typename T>
struct Node {
    T data; // Элементүүдийн өгөгдөл
    Node* next; // Дараагийн элементийн холбоос

    Node(T t) : data(t), next(nullptr) {}
};

// LinkedList класс нь динамик өгөгдлийн бүтцийг ашиглах
template <typename T>
class LinkedList {
private:
    Node<T>* head; // Жагсаалтын эхлэл
    int size; // Жагсаалтын хэмжээ

public:
    // Конструктор
    LinkedList() : head(nullptr), size(0) {}

    // Деструктор, санах ойн менежмент
    ~LinkedList() {
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Элемент нэмэх функц
    void add(T t) {
        Node<T>* newNode = new Node<T>(t);
        if (head == nullptr) {
            head = newNode;
        } else {
            Node<T>* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        size++;
    }

    // Определлэх индексээр элементийг оруулах
    void insert(T t, int index) {
        if (index < 0 || index > size) return;

        Node<T>* newNode = new Node<T>(t);
        if (index == 0) {
            newNode->next = head;
            head = newNode;
        } else {
            Node<T>* temp = head;
            for (int i = 0; i < index - 1; ++i) {
                temp = temp->next;
            }
            newNode->next = temp->next;
            temp->next = newNode;
        }
        size++;
    }

    // Индексээр элементийг авах
    T get(int index) {
        if (index < 0 || index >= size) throw out_of_range("Index out of range");

        Node<T>* temp = head;
        for (int i = 0; i < index; ++i) {
            temp = temp->next;
        }
        return temp->data;
    }

    // Индексээр элементийг устгах
    void deleteAt(int index) {
        if (index < 0 || index >= size) return;

        Node<T>* temp = head;
        if (index == 0) {
            head = head->next;
            delete temp;
        } else {
            for (int i = 0; i < index - 1; ++i) {
                temp = temp->next;
            }
            Node<T>* toDelete = temp->next;
            temp->next = toDelete->next;
            delete toDelete;
        }
        size--;
    }

    // Жагсаалтын хэмжээ
    int length() const {
        return size;
    }

    // Жагсаалтыг талбайгаар нь эрэмбэлэх функц
    void sort() {
        for (int i = 0; i < size - 1; ++i) {
            Node<T>* temp = head;
            for (int j = 0; j < size - i - 1; ++j) {
                if (temp->data->area() > temp->next->data->area()) {
                    T tmp = temp->data;
                    temp->data = temp->next->data;
                    temp->next->data = tmp;
                }
                temp = temp->next;
            }
        }
    }

    // Жагсаалтыг хэвлэх
    void print() const {
        Node<T>* temp = head;
        while (temp != nullptr) {
            temp->data->print();
            temp = temp->next;
        }
    }
};

#endif // LINKEDLIST_HPP
