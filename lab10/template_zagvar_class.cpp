// Загвар класс - дурын төрлийн өгөгдлийг хадгалах Linked List
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
        while (head != nullptr) {
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
