#include <iostream>

using std::cout;
using std::endl;


void insertEnd(int arr[], int n, int length, int capacity) {
	if (length < capacity) {
		arr[length] = n;
	}
}

void removeEnd(int arr[], int length) {
	if (length > 0) {
		arr[length-1] = 0;
	}
}

void insertMiddle(int arr[], int i, int n, int length) {
	for (int index=length-1; index>=i; index--) {
		arr[index+1] = arr[index];
	}
	
	arr[i] = n;
}

void removeMiddle(int arr[], int i, int length) {
	for (int index=i+1; index<length; index++) {
		arr[index-1] = arr[index];
}

void printArr(int arr[], int capacity) {
	for (int index=0; index<capacity; index++) {
		cout << arr[index] << " ";
	}
	cout << endl;
}
