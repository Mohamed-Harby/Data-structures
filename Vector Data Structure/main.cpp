#include<iostream>
#include<set>
#include <assert.h>
#include "vector.h"
using namespace std;

int main() {
	int n;
	cin >> n; // 6
	Vector v(n);
	int tmp;
	for (int i = 0; i < n; ++i)
		cin >> tmp, v.set(i, tmp); // 1 2 3 4 5 6

	v.print();					// 1 2 3 4 5 6
	v.right_rotate(2000000000);
	v.print();					// 5 6 1 2 3 4
	v.left_rotate(3);
	v.print();					// 2 3 4 5 6 1

	int val = v.pop(3); 	// pop element with index 3
	cout << val << "\n";	// 5
	v.print();				// 2 3 4 6 1

	cout << v.find_transposition(6) << "\n";	// 2
	v.print();									// 2 3 6 4 1

	return 0;
}
