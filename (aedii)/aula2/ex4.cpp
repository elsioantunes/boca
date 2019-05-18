#include <iostream>
#include <vector>
#include <chrono>
#include <random>
#include <algorithm>

#include "bubblesort2.h"
#include "selectionsort2.h"
#include "insertionsort2.h"
#include "shellsort2.h"
#include "quicksort2.h"

#define NUM_KEYS 10000 // Number of keys (keys from 1 to NUM_KEYS)

using namespace std;

int main()
{
    // Create a vector containing NUM_KEYS integers [1..NUM_KEYS]
    vector<int> v;
    for (int i = 1; i <= NUM_KEYS; ++i)
        v.push_back(i);

    // Randomly permutates v
    int seed = (int) chrono::system_clock::now().time_since_epoch().count();
    default_random_engine rndGen(seed);
    shuffle (v.begin(), v.end(), rndGen);   

	vector<int> vcopy = v; // Make a copy
    cout << "BubbleSort... " << endl;
    aed2::BubbleSort<int> bubbleSort(vcopy);
    cout << "Swaps: " << bubbleSort.GetSwaps() << endl;
    cout << endl;

	vcopy = v;
    cout << "SelectionSort... " << endl;
    aed2::SelectionSort<int> selectionSort(vcopy);
    cout << "Swaps: " << selectionSort.GetSwaps() << endl;
    cout << endl;

	vcopy = v;
    cout << "InsertionSort... " << endl;
    aed2::InsertionSort<int> insertionSort(vcopy);
    cout << "Swaps: " << insertionSort.GetSwaps() << endl;
    cout << endl;

	vcopy = v;
    cout << "ShellSort... " << endl;
    aed2::ShellSort<int> shellSort(vcopy);
    cout << "Swaps: " << shellSort.GetSwaps() << endl;
    cout << endl;

	vcopy = v;
    cout << "QuickSort... " << endl;
    aed2::QuickSort<int> quickSort(vcopy);
    cout << "Swaps: " << quickSort.GetSwaps() << endl;
    cout << endl;
}
