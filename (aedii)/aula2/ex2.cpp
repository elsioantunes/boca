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

#define NUM_KEYS 10000 // Number of keys (keys from 1 to NUM_KEYS)

using namespace std;

///////////////////////////////////////////////////////////////////////////////
/// Checks whether the given vector is sorted in non decreasing order.
///
/// \param v Vector to check.
///
/// \retval true If v is sorted in non decreasing order.
/// \retval false If v is not sorted in non decreasing order.
///////////////////////////////////////////////////////////////////////////////
template <class T>
bool isSorted(std::vector<T>& v)
{
    for (auto it = std::begin(v); it < std::end(v)-1; it++)
    {
        if (*it > *(it+1))
            return false;
    }
    return true;
}

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
    cout << "BubbleSort... ";
    aed2::BubbleSort<int> bubbleSort(vcopy);
    cout << (isSorted(vcopy) ? "Sorted" : "NOT sorted!") << endl;

	vcopy = v;
    cout << "SelectionSort... ";
    aed2::SelectionSort<int> selectionSort(vcopy);
    cout << (isSorted(vcopy) ? "Sorted" : "NOT sorted!") << endl;

	vcopy = v;
    cout << "InsertionSort... ";
    aed2::InsertionSort<int> insertionSort(vcopy);
    cout << (isSorted(vcopy) ? "Sorted" : "NOT sorted!") << endl;    

	vcopy = v;
    cout << "ShellSort... ";
    aed2::ShellSort<int> shellSort(vcopy);
    cout << (isSorted(vcopy) ? "Sorted" : "NOT sorted!") << endl;

	vcopy = v;
    cout << "QuickSort... ";
    aed2::QuickSort<int> quickSort(vcopy);
    cout << (isSorted(vcopy) ? "Sorted" : "NOT sorted!") << endl;

	vcopy = v;
    cout << "MergeSort... ";
    aed2::MergeSort<int> mergeSort(vcopy);
    cout << (isSorted(vcopy) ? "Sorted" : "NOT sorted!") << endl;
}
