#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

#include "bubblesort.h"
#include "selectionsort.h"
#include "insertionsort.h"
#include "shellsort.h"
#include "quicksort.h"
#include "mergesort.h"
#include "timing.h"

#define NUM_VECTORS 16 // Each vector contains 2^0 to 2^(NUM_VECTORS-1) keys

using namespace std;

int main()
{
    int seed = (int) chrono::system_clock::now().time_since_epoch().count();
    default_random_engine rndGen(seed);

    // Create each vector
    vector<int> v[NUM_VECTORS];
	int size = 1;
	for (int i = 0; i < NUM_VECTORS; ++i)
	{		
		// This one will contain integers in the range [0..2^i]
	    for (int j = 0; j < size; ++j)
    	    v[i].push_back(j);

	    shuffle (v[i].begin(), v[i].end(), rndGen);   

		size *= 2;
	}

	time_point t1;
	vector<int> vcopy;

	// Perform the timing tests
    cout << "BubbleSort..." << endl;
	for (int i = 0; i < NUM_VECTORS; ++i)
	{		
		vcopy = v[i];
    	t1 = time_now();
	    aed2::BubbleSort<int> sort(vcopy);
    	auto duration = dtime_ms(time_now() - t1);
    	cout << "2^" << i << ": " << duration << " ms." << endl;
	}
	cout << endl;

	cout << "SelectionSort..." << endl;
	for (int i = 0; i < NUM_VECTORS; ++i)
	{		
		vcopy = v[i];
    	t1 = time_now();
	    aed2::SelectionSort<int> sort(vcopy);
    	auto duration = dtime_ms(time_now() - t1);
    	cout << "2^" << i << ": " << duration << " ms." << endl;
	}
	cout << endl;

	cout << "InsertionSort..." << endl;
	for (int i = 0; i < NUM_VECTORS; ++i)
	{		
		vcopy = v[i];
    	t1 = time_now();
	    aed2::InsertionSort<int> sort(vcopy);
    	auto duration = dtime_ms(time_now() - t1);
    	cout << "2^" << i << ": " << duration << " ms." << endl;
	}
	cout << endl;

	cout << "ShellSort..." << endl;
	for (int i = 0; i < NUM_VECTORS; ++i)
	{		
		vcopy = v[i];
    	t1 = time_now();
	    aed2::ShellSort<int> sort(vcopy);
    	auto duration = dtime_ms(time_now() - t1);
    	cout << "2^" << i << ": " << duration << " ms." << endl;
	}
	cout << endl;

	cout << "QuickSort..." << endl;
	for (int i = 0; i < NUM_VECTORS; ++i)
	{		
		vcopy = v[i];
    	t1 = time_now();
	    aed2::QuickSort<int> sort(vcopy);
    	auto duration = dtime_ms(time_now() - t1);
    	cout << "2^" << i << ": " << duration << " ms." << endl;
	}
	cout << endl;

	cout << "MergeSort..." << endl;
	for (int i = 0; i < NUM_VECTORS; ++i)
	{		
		vcopy = v[i];
    	t1 = time_now();
	    aed2::MergeSort<int> sort(vcopy);
    	auto duration = dtime_ms(time_now() - t1);
    	cout << "2^" << i << ": " << duration << " ms." << endl;
	}
	cout << endl;
}
