#include "sort2.h"
#include <iostream>

using namespace std;

Quicksort::Quicksort() {
	sortArray.length = 0;
	sortArray.arr = NULL;	
}

Quicksort::~Quicksort() {
	delete [] sortArray.arr;
	sortArray.arr = NULL;
}

// reads in a list of integers from stdin and returns an arrayWithLength
void Quicksort::readList(){
        int currentCapacity = 10;
        sortArray.arr = new int[currentCapacity];
        
        while (cin >> sortArray.arr[sortArray.length]) {
                ++sortArray.length;
                if (sortArray.length==currentCapacity) {
                        int *temp = new int[currentCapacity*2];
                        for (int i=0;i<currentCapacity;i++) {
                                temp[i] = sortArray.arr[i];
                        }
                        delete [] sortArray.arr;
                        sortArray.arr = temp;
                        currentCapacity *= 2;
                }
        }
}

void Quicksort::sort() {
	quicksort(0, sortArray.length - 1);
}

void Quicksort::quicksort(int left, int right) {
	int pivot = partition(left, right);

	// recursively quicksort numbers less than, greater than pivot
	if (left < pivot - 1) {
		quicksort(left, pivot - 1);
	}
	if (pivot + 1 < right) {
		quicksort(pivot + 1, right);
	}
}

int Quicksort::partition(int left, int right) {
	// pick pivot in the middle (to avoid n^2 behavior);
	// swap that pivot with the leftmost position to
	// simplify the partitioning process
	int pivot_position = left+((right-left)/2);
	int pivot = sortArray.arr[pivot_position];
	int swap_temp = sortArray.arr[left];
	sortArray.arr[left] = pivot;
	sortArray.arr[pivot_position] = swap_temp; 

	// build lists of numbers less than/greater than the pivot	
	int left_iter = left;
	int right_iter = right;
	while (left_iter <= right_iter) {
		while (sortArray.arr[left_iter] <= pivot && left_iter < sortArray.length)
			left_iter++;
		
		while (sortArray.arr[right_iter] > pivot)
			right_iter--;

		if (left_iter < right_iter) {
			int temp = sortArray.arr[left_iter];
			sortArray.arr[left_iter] = sortArray.arr[right_iter];
			sortArray.arr[right_iter] = temp; 
		}
	}
	
	// put the pivot in its correct position at right_iter
	int temp = sortArray.arr[left];
	sortArray.arr[left] = sortArray.arr[right_iter];
	sortArray.arr[right_iter] = temp;
	
	return right_iter;
} 

void Quicksort::printArray() {
	for (int i = 0; i < sortArray.length; i++) {
		cout << sortArray.arr[i] << endl;
	}
}
