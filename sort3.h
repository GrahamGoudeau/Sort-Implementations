//
//  sort3.h
//  (Radix sort (LSD))
//  Header File for Radixsort class
//

#ifndef SORT3_H 
#define SORT3_H

#include <iostream>

struct arrayWithLength{
        int length;
        int *arr;
};



class Radixsort {
public:
        Radixsort(); // constructor
	~Radixsort(); // destructor
        
        // read in a list of values from stdin
        void readList();
        
        // sort function
        void sort();
        
        // print the array
        void printArray();
        
private:
        arrayWithLength sortArray;
	int get_bucket(int key, int place_value);
	void initialize_buckets();

	int max;
};

struct Queue_Node {
	int value;

	Queue_Node *next;
	Queue_Node *prev;
};

class Queue {
public:
	Queue();
	~Queue();	
	
	void enqueue(int value);
	int dequeue();
	bool is_empty();

private:
	int size;

	Queue_Node *head;
	Queue_Node *tail;
};

#endif /* defined(__Sorting__Radixsort) */


