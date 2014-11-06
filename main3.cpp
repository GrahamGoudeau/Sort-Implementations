#include "sort3.h"
#include <iostream>

using namespace std;

int main()
{
        Radixsort sorter;
        
        sorter.readList();
        sorter.sort();
        cout << "Output:\n";
	sorter.printArray();

	return 0;
}
	

