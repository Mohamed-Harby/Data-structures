#include "vector.h"

Vector::Vector(int sz) :
		size(sz) {
	if (size < 0)
		size = 1;
	capacity = size * 2;
	arr = new int[capacity] { };
}

Vector::~Vector() {
	delete[] arr;
	arr = nullptr;
}

void Vector::clear() {
	delete[] arr;
	arr = nullptr;
	size = 0;
	capacity = 0;
}

void Vector::expand_capacity() {
	capacity *= 2;
	int *tmp = new int[capacity] { };
	for (int i = 0; i < size; ++i)
		tmp[i] = arr[i];

	swap(arr, tmp);	// is O(1) for array created by 'new' keyword
	delete[] tmp;
}

int Vector::getSize() {
	return size;
}

int Vector::front() {
	return arr[0];
}

int Vector::back() {
	return arr[size - 1];
}

void Vector::set(int idx, int val) {
	assert(idx >= 0 and idx < size);
	arr[idx] = val;
}

int Vector::get(int idx) {
	assert(idx >= 0 and idx < size);
	return arr[idx];
}

void Vector::print() {
	for (int i = 0; i < size - 1; ++i) {
		cout << arr[i] << ' ';
	}
	cout << arr[size - 1] << '\n';
}

int Vector::find(int val) {
	for (int i = 0; i < size; ++i) {
		if (arr[i] == val)
			return i;
	}
	return -1;
}

void Vector::push_back(int val) {
	if (size == capacity)
		expand_capacity();
	arr[size++] = val;
}

void Vector::insert1(int idx, int val) { // O(n) for both best case and worst case
	assert(idx >= 0 && idx < size);
	if (size == capacity)
		expand_capacity();

	int *tmp = new int[capacity] { };
	int i = 0, j = 0; // i for tmp, j for arr
	while (j < size) {
		if (i == idx)
			tmp[i++] = val;

		else
			tmp[i++] = arr[j++];
	}
	swap(arr, tmp);
	delete[] tmp;
	++size;
}

void Vector::insert2(int idx, int val) {
	assert(idx >= 0 && idx < size);
	if (size == capacity)
		expand_capacity();

	for (int i = size; i >= idx; --i)
		arr[i + 1] = arr[i];

	arr[idx] = val;
	++size;
}

void Vector::right_rotate(int times) {
	times %= size;
	int *tmp = new int[times] { };
	int idx = 0;
	for (int i = size - times; i < size; ++i)
		tmp[idx++] = arr[i];

	idx = 0;
	for (int i = size - 1; i >= times; --i)
		arr[i] = arr[size - 1 - times - (idx++)];

	for (int i = 0; i < times; ++i) {
		arr[i] = tmp[i];
	}
	delete[] tmp;
}

void Vector::left_rotate(int times) {
	times %= size;
	int *tmp = new int[times] { };
	int idx = 0;
	for (int i = 0; i < times; ++i)
		tmp[i] = arr[i];

	idx = 0;
	for (int i = times; i < size; ++i)
		arr[i - times] = arr[times + (idx++)];

	idx = 0;
	for (int i = size - times; idx < times; ++i) {
		arr[i] = tmp[idx++];
	}
	delete[] tmp;
}

int Vector::pop(int idx) {
	assert(idx >= 0 && idx < size);
	int ret = arr[idx];
	while (idx < size - 1) {
		arr[idx] = arr[idx + 1];
		idx++;
	}
	--size;
	return ret;
}

int Vector::find_transposition(int val) {	// used when finding repetive values
	if (arr[0] == val)
		return 0;
	for (int i = 1; i < size; ++i) {
		if (arr[i] == val) {
			swap(arr[i], arr[i - 1]); // make it in the beginning for find it fast next time
			return i - 1; // return the new position
		}
	}
	return -1;
}
