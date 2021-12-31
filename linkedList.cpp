#include <iostream>

using namespace std;

struct Node {
    int data{};
    Node *next{};

    explicit Node(int d) : data(d) {} // 'explict' to avoid the implicit conversion 'int' and 'Node'
};

class linkedList {
private:
    Node *head{};
    Node *tail{};

public:
    int length = 0;

    void print();

    void push_back(int data);

    void push_front(int data);

    void delete_back();

    void delete_front();
};

void linkedList::print() {
    Node *curr = head;
    while (curr != nullptr) {
        cout << curr->data << ' ';
        curr = curr->next;
    }
}

void linkedList::push_back(int data) {
    Node *curr = new Node(data);
    if (head == nullptr) {
        head = tail = curr;
    } else {
        tail->next = curr;
        tail = curr;
    }
    ++length;
}

void linkedList::push_front(int data) {
    Node *curr = new Node(data);
    if (head == nullptr) {
        head = tail = curr;
    } else {
        curr->next = head;
        head = curr;
    }
    ++length;
}

void linkedList::delete_back() {

}

void linkedList::delete_front() {
    Node *tmp = head;
    head = head->next;
    delete tmp;
}

int main() {

}
