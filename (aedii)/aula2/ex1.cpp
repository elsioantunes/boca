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
    time_point t1 = time_now();
    aed2::BubbleSort<int> bubbleSort(vcopy);
    auto duration = dtime_ms(time_now() - t1);
    cout << "Time to run: " << duration << " ms." << endl;
    cout << endl;

	vcopy = v;
    cout << "SelectionSort... " << endl;
    t1 = time_now();
    aed2::SelectionSort<int> selectionSort(vcopy);
    duration = dtime_ms(time_now() - t1);
    cout << "Time to run: " << duration << " ms." << endl;
    cout << endl;

	vcopy = v;
    cout << "InsertionSort... " << endl;
    t1 = time_now();
    aed2::InsertionSort<int> insertionSort(vcopy);
    duration = dtime_ms(time_now() - t1);
    cout << "Time to run: " << duration << " ms." << endl;
    cout << endl;

	vcopy = v;
    cout << "ShellSort... " << endl;
    t1 = time_now();
    aed2::ShellSort<int> shellSort(vcopy);
    duration = dtime_ms(time_now() - t1);
    cout << "Time to run: " << duration << " ms." << endl;
    cout << endl;

	vcopy = v;
    cout << "QuickSort... " << endl;
    t1 = time_now();
    aed2::QuickSort<int> quickSort(vcopy);
    duration = dtime_ms(time_now() - t1);
    cout << "Time to run: " << duration << " ms." << endl;
    cout << endl;

	vcopy = v;
    cout << "MergeSort... " << endl;
    t1 = time_now();
    aed2::MergeSort<int> mergeSort(vcopy);
    duration = dtime_ms(time_now() - t1);
    cout << "Time to run: " << duration << " ms." << endl;
    cout << endl;
}
