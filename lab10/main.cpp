#include <iostream>
#include <cstdlib>
#include <ctime>
#include "circle.hpp"
#include "square.hpp"
#include "triangle.hpp"
#include "linkedlist.hpp"

using namespace std;

int main() {
    srand(time(0));

    // Shape-ийн обьектуудыг хадгалах LinkedList үүсгэх
    LinkedList<shape*> shapes;

    // Санамсаргүй хэмжээтэй гурвалжин, дөрвөлжин, тойрог объектуудыг үүсгэх
    for (int i = 0; i < 20 + rand() % 10; i++) {
        int shapeType = rand() % 3;
        int size = 1 + rand() % 10; // 1-10 хэмжээтэй санамсаргүй хэмжээ

        switch (shapeType) {
        case 0:
            shapes.add(new circle(size));
            break;
        case 1:
            shapes.add(new square(size));
            break;
        case 2:
            shapes.add(new triangle(size));
            break;
        }
    }

    // Жагсаалтыг талбайгаар нь эрэмбэлэх
    shapes.sort();

    // Эрдэмжсэн жагсаалтыг хэвлэх
    cout << "Sorted by area:" << endl;
    shapes.print();

    // Санах ойг цэвэрлэх
    for (int i = 0; i < shapes.length(); ++i) {
        delete shapes.get(i);
    }

    return 0;
}
