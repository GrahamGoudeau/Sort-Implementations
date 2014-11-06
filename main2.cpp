#include "sort2.h"
#include <iostream>

using namespace std;

int main()
{
        Quicksort sorter;
        
        sorter.readList();
        sorter.sort();
        cout << "Output:\n";
	sorter.printArray();

	return 0;
}
	

