#include "sort3.h"
#include <iostream>
#include <cmath>

using namespace std;

Radixsort::Radixsort() {
	sortArray.length = 0;
	sortArray.arr = NULL;
	max = 0;	
}

Radixsort::~Radixsort() {
	delete [] sortArray.arr;
	sortArray.arr = NULL;
}

// reads in a list of integers from stdin and returns an arrayWithLength
void Radixsort::readList(){
        int currentCapacity = 10;
        sortArray.arr = new int[currentCapacity];
        
        while (cin >> sortArray.arr[sortArray.length]) {
		if (sortArray.arr[sortArray.length] > max)
			max = sortArray.arr[sortArray.length];
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

void Radixsort::sort() {
	// base 10, so ten buckets
	Queue buckets[10];
	// requires log10(max) passes through all the data 
	for (int place_value = 1; place_value < log10(max) + 1; place_value++) {
		for (int num = 0; num < sortArray.length; num++) {
			int value = sortArray.arr[num];
			// correct bucket based on current place value
			int bucket = get_bucket(value, place_value);
			buckets[bucket].enqueue(value);
		}

		int bucket = 0;
		for (int num = 0; num < sortArray.length; num++) {
			// empty the nonempty buckets back into the array
			while (buckets[bucket].is_empty()) bucket++;
			sortArray.arr[num] = buckets[bucket].dequeue();
			
		}
	}
} 


int Radixsort::get_bucket(int key, int place_value) {
	// LSD RADIX SORT
	// "get bucket" algorithm by Graham Goudeau
	// if x = KEY mod (10^place_value) (gives PLACE_VALUE # of last digits)
	// take x/10^place_value-1 to strip away all but the desired digit
	// example: {floor((mod(123456789,10^i))/(10^(i-1)))} for i from 1 to 10
	// yields the set {1,2,3,4,5,6,7,8,9,0}
	int last_digits = key % ((int) pow(10, place_value));
	int get_first = last_digits / ((int) pow(10, place_value-1));
	return get_first;
}

void Radixsort::printArray() {
	for (int i = 0; i < sortArray.length; i++)
		cout << sortArray.arr[i] << endl;
}




/************************************************
 * 		QUEUE FUNCTIONS			*
 * 	(based on queue implementation		*
 * 	from my HW 3 assignment)		*
 ***********************************************/

Queue::Queue() {
	size = 0;
	head = NULL;
	tail = NULL;
}

Queue::~Queue() {
	Queue_Node *temp = head;
	while (temp != NULL) {
		head = temp->next;
		delete temp;
		temp = head;
	}
}

void Queue::enqueue(int value) {
	Queue_Node *new_node = new Queue_Node;
	new_node->value = value;
	if (head == NULL) {
		new_node->next = NULL;
		new_node->prev = NULL;
		head = new_node;
		tail = new_node;
		return;
	}

	new_node->prev = tail;
	new_node->next = NULL;
	tail->next = new_node;
	tail = new_node;
}

int Queue::dequeue() {
	int return_value = head->value;
	Queue_Node *to_delete = head;
	head = head->next;
	if (head != NULL)
		head->prev = NULL;
	else
		tail = NULL;

	delete to_delete;

	return return_value;	
}

bool Queue::is_empty() {
	return head == NULL;
}

