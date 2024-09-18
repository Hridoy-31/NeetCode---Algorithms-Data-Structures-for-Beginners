#include <iostream>

using std::cout;
using std::endl;

// Resizeable array implementation
class Array {
	int capacity = 2;
	int length = 0;
	int *arr = new int[2];
	
	Array(){};
	
	void pushback(int n) {
		if (length == capacity) {
			resize();
		}
		arr[length] = n;
		length++;
	}
	
	void resize() {
		capacity = 2 * capacity;
		int *newArr = new int[capacity];
		
		for (int i=0; i<length; i++) {
			newArr[i] = arr[i];
		}
		
		arr = newArr;
	}
	
	void popback() {
		if (length > 0) {
			length--;
		}
	}
	
	int get(int i) {
		if (i < length) {
			return arr[i];
		}
	}
	
	void insert(int i, int n) {
		if (i < length) {
			arr[i] = n;
			return;
		}
	}
	
	void print() {
		for (int i=0; i<length; i++) {
			cout << arr[i] << " ";
		}
		cout << endl;
	}
};
