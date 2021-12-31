#include <iostream>
#include <cassert>

using namespace std;

struct Node {
    int data{};
    Node *next{};

    explicit Node(int d) : data(d) {} // 'explict' to avoid the implicit conversion between 'int' and 'Node'

    ~Node() {
        cout << "the node with value " << data << " with address " << this << " is destroyed\n";
    }
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

    void clear();

    bool nullHead();

    bool nullTail();

    void verify();
};

void linkedList::print() {
    Node *curr = head;
    while (curr != nullptr) {
        cout << curr->data << ' ';
        curr = curr->next;
    }
    cout << '\n';
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
    // write your code here
    --length;
}

void linkedList::delete_front() {
    Node *tmp = head;
    if (head != nullptr)
        head = head->next;

    if (tail == tmp)    // all items are deleted
        tail = nullptr;

    delete tmp;
    --length;
}

void linkedList::clear() {
    Node *tmp;
    while (head != nullptr) {
        tmp = head;
        head = head->next;
        delete tmp;
    }
    tail = nullptr;
}

bool linkedList::nullHead() {
    return head == nullptr;
}

bool linkedList::nullTail() {
    return tail == nullptr;
}

void linkedList::verify() {
    int verified_length = 0;
    Node *it = head;
    while (it != nullptr) {
        ++verified_length;
        it = it->next;
    }
    delete it;
    assert(verified_length == length);

    if (verified_length == 0)
        assert(head == nullptr && tail == nullptr);
    else if (verified_length == 1)
        assert(head == tail && head != nullptr && tail != nullptr);
    else
        assert(head != tail && head != nullptr && tail != nullptr);

    assert(tail->next == nullptr);
}

int main() {
    linkedList ll;
    ll.push_back(1);
    ll.push_back(2);
    ll.push_back(3);
    ll.push_back(4);
    ll.delete_front();
    ll.delete_front();
    ll.delete_front();
    ll.delete_front();
    ll.push_back(5);
    ll.push_back(9);
//    ll.clear();

    ll.verify();
//    ll.delete_front();
//    ll.print();

}
