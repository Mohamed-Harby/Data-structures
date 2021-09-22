#ifndef VECTOR_H_
#define VECTOR_H_

#include<iostream>
#include<set>
#include <assert.h>

using namespace std;

class Vector {
private:
	int size;
	int *arr = nullptr;
	int capacity;
	void expand_capacity();
public:
	Vector(int sz);
	~Vector();
	void clear();
	int getSize();
	int front();
	int back();
	void set(int idx, int val);
	int get(int idx);
	void print();
	int find(int val);
	void push_back(int val);
	void insert1(int idx, int val); // O(n) for both best case and worst case

	void insert2(int idx, int val); // O(1) for best case and O(n) for worst case

	void right_rotate(int times);
	void left_rotate(int times);
	int pop(int idx);
	int find_transposition(int val);
};

#endif /* VECTOR_H_ */
