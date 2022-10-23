#include<bits/stdc++.h>
using namespace std;

struct Node {
	int data;
	Node *prev { };
	Node *next { };
	Node(int data) {
		this->data = data;
	}
};

class DoublyLinkedList {
public:

	Node *head { };
	Node *tail { };
	int length = 0;

	void print() {
		cout << "[ ";
		for (Node *cur = head; cur != nullptr; cur = cur->next) {
			cout << cur->data << ", ";
		}
		cout << "]\n";
	}
	void print_reversed() {
		cout << "[ ";
		for (Node *cur = tail; cur != nullptr; cur = cur->prev) {
			cout << cur->data << ", ";
		}
		cout << "]\n";
	}

	void link(Node *first, Node *second) {
		first->next = second;
		second->prev = first;
	}

	void insert_end(int value) {
		Node *node = new Node(value);
		if (!head)
			head = tail = node;
		else {
			link(tail, node);
			tail = node;
		}
		length++;
	}

	void insert_front(int value) {
		Node *node = new Node(value);
		if (!head) {
			head = tail = node;
		} else {
			link(node, head);
			head = node;
		}
		length++;
	}

	void embed_after(Node * node, int value) {
		Node * middle = new Node(value);
		link(middle, node->next);
		link(node, middle);
	}

	void insert_sorted(int value) {
		if (length == 0 or value <= head->data) {
			insert_front(value);
		} else if (value >= tail->data) {
			insert_end(value);
		} else {
			for (Node *cur = head; cur; cur = cur->next) {
				if (value <= (cur->next)->data) {
					embed_after(cur, value);
					break;
				}
			}
		}
		length++;
	}

	void delete_front() {
		if (!head)
			return;
		Node * temp = head;
		head = head->next;
		delete temp;
		length--;
		if (head)
			head->prev = nullptr;
		if (length == 0)
			tail = nullptr;
	}

	void delete_end() {
		if (!tail)
			return;
		Node * temp = tail;
		tail = tail->prev;
		delete temp;
		length--;
		if (tail)
			tail->next = nullptr;
		if (length == 0)
			head = nullptr;
	}

	void delete_and_link(Node * node) {
		if (node == head)
			delete_front();
		else if (node == tail)
			delete_end();
		else {
			link(node->prev, node->next);
			delete node;
		}
		length--;
	}
};

int main() {
	DoublyLinkedList dll;
	dll.insert_sorted(10);
	dll.insert_sorted(2);
	dll.insert_sorted(300);
	dll.insert_sorted(7);
	dll.print();
	cout << bool(dll.head->prev == nullptr) << '\n';
//	dll.delete_front();
	cout << dll.head->prev << '\n';
	dll.print();
	dll.delete_and_link(dll.head);
	dll.delete_and_link(dll.tail);
	dll.print();
}

