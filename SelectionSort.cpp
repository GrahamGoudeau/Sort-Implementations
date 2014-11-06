//
//  SelectionSort.cpp
//  Sorts integers using the SelectionSort algorithm


#include "SelectionSort.h"

using namespace std;

SelectionSort::SelectionSort(){ // constructor
        sortArray.length = 0;
        sortArray.arr = NULL;
}

SelectionSort::~SelectionSort() {
	delete [] sortArray.arr;
	sortArray.arr = NULL;
}

// reads in a list of integers from stdin and returns an arrayWithLength
void SelectionSort::readList(){
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

void SelectionSort::sort(){
        // selection sort on sortArray
	for (int basis = 0; basis < sortArray.length; basis++) {
		int curr_min = sortArray.arr[basis];
		int min_index = basis;
		for (int next = basis; next < sortArray.length; next++) {
			if (sortArray.arr[next] < curr_min) {
				curr_min = sortArray.arr[next];
				min_index = next;
			}
		}
		if (min_index != basis) {
			sortArray.arr[min_index] = sortArray.arr[basis];
			sortArray.arr[basis] = curr_min;
		}
	}
}

void SelectionSort::printArray(){
        // prints out the integers in sorted order
	for (int i = 0; i < sortArray.length; i++)
		cout << sortArray.arr[i] << endl;
}


