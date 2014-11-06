//
//  sort2.h
//  (quicksort)
//  Header File for quicksort class
//

#ifndef SORT2_H 
#define SORT2_H

#include <iostream>

struct arrayWithLength{
        int length;
        int *arr;
};

class Quicksort {
public:
        Quicksort(); // constructor
	~Quicksort(); // destructor
        
        // read in a list of values from stdin
        void readList();
        
        // sort function
        void sort();
        
        // print the array
        void printArray();
        
private:
        arrayWithLength sortArray;
	void quicksort(int left, int right);
	int partition(int left, int right);
};

#endif /* defined(__Sorting__Quicksort__) */

