#ifndef LINKEDLIST_HPP
#define LINKEDLIST_HPP

#include <iostream>
using namespace std;

// Linked List-н node template structure
template <class T>
struct Node {
    T data; // Элементүүдийн өгөгдөл
    Node* next; // Дараагийн node-н холбоос

    Node(T t) : data(t), next(nullptr) {}
};

// LinkedList класс нь динамик өгөгдлийн бүтцийг ашиглана
template <class T>
class LinkedList {
private:
    Node<T>* head; // head pointer нь node төрлийн structure луу заана
    int size; // LinkedList-н хэмжээ

public:
    // Байгуулагч функц
    LinkedList() : head(nullptr), size(0) {}

    // Устгагч функц, бүх linkedlist-н node-үүдийг санах ойгоос чөлөөлнө
    ~LinkedList() {
        while (head != nullptr) {
            Node<T>* temp = head;
            head = head->next;
            delete temp;
        }
    }

    // Node нэмэх функц
    void add(T t) {
        // new оператор ашиглан дараагийн node-г үүсгэнэ
        Node<T>* newNode = new Node<T>(t);
        // Хэрэв head null-руу зааж байвал head шинэ node-рүү заана
        if (head == nullptr) {
            head = newNode;
        }
        // Үгүй бол linkedlist-н хамгийн ард нь дараагийн node-г үүсгэнэ 
        else {
            Node<T>* temp = head;
            while (temp->next != nullptr) {
                temp = temp->next;
            }
            temp->next = newNode;
        }
        size++; // LinkedList-н хэмжээг нэмэгдүүлнэ
    }

    // Индексээр node-г оруулах
    void insert(T t, int index) {
        // хэрэв index 0-с бага, эсвэл параметрт оруулсан index-н утга хэмжээгээс хэтэрвэл ажиллахгүй
        if (index < 0 || index > size) return;
        // new оператор ашиглан дараагийн node-г үүсгэнэ
        Node<T>* newNode = new Node<T>(t);
        // хэрэв index-н утга 0 байвал head шинэ node-рүү заана
        if (index == 0) {
            newNode->next = head;
            head = newNode;
        } 
        else {
            // оруулах гэж байгаа index-г заасан node руу очоод шинэ node-рүү заана.
            Node<T>* temp = head;
            for (int i = 0; i < index - 1; ++i) {
                temp = temp->next;
            }
            // шинэ node нь дараагийн node-рүү заана
            newNode->next = temp->next;
            temp->next = newNode;
        }
        size++; // linkedlist-н хэмжээг нэмэгдүүлнэ 
    }

    // Индексээр элементийг авах
    T get(int index) {
        // параметрээр авсан утга хэмжээнээс хэтэрвэл утга авахгүй
        if (index < 0 || index >= size) throw out_of_range("Index out of range");
        // node-рүү заасан заагч үүсгэн index хүртэл list-ээр гүйгээд утгыг буцаана
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
