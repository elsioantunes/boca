// Timing random queries of linear search and binary search.

#include <iostream>
#include <vector>
#include <algorithm>
#include <random>

#include "timing.h"

#define NUM_KEYS 100000 // Number of keys (keys from 1 to NUM_KEYS)
#define NUM_QUERIES 10000 // Number of random queries

using namespace std;

///////////////////////////////////////////////////////////////////////////////
/// Linear search in a vector (dynamic size array).
///
/// \param v Vector.
/// \param key Search key.
///
/// \return Index of the key found or -1 if not found.
///////////////////////////////////////////////////////////////////////////////
template <typename T>
int LinearSearch(const vector<T> &v, const T &key)
{
    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i] == key)
            return i;
    }
    return -1;
}

///////////////////////////////////////////////////////////////////////////////
/// Binary search in a vector (dynamic size array).
///
/// \param v Vector sorted in increasing order.
/// \param key Search key.
///
/// \return Index of the key found or -1 if not found.
///////////////////////////////////////////////////////////////////////////////
template <typename T>
int BinarySearch(const vector<T> &v, const T &key)
{
    int low = 0, high = v.size() - 1;
    while (low <= high)
    {
        int mid = (low + high) / 2;
        if (v[mid] == key)
            return mid;
        else if (v[mid] < key)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return -1;
}

int main()
{
    // Create a vector containing NUM_KEYS integers [1..NUM_KEYS]
    vector<int> vb;
    for (int i = 1; i <= NUM_KEYS; ++i)
    {
        vb.push_back(i);
    }

    // Create a copy to linear search
    vector<int> vl = vb;

    // Randomly permutates vl (not really necessary but may be useful later)
    int seed = (int) chrono::system_clock::now().time_since_epoch().count();
    default_random_engine rndGen(seed);
    shuffle (vl.begin(), vl.end(), rndGen);   

    // Set up a random uniform distribution
    uniform_int_distribution<int> rndDist(0, NUM_KEYS);

    // Reset random number generator
    rndGen.seed(seed);

    // Measure the linear search
    time_point t1 = time_now();
    for (int i = 0; i < NUM_QUERIES; ++i)
    {
        LinearSearch(vl, rndDist(rndGen));
    }
    auto duration = itime_ms(time_now() - t1);
    cout << "Linear search time: " << duration << " ms.\n";

    // Reset random number generator
    rndGen.seed(seed);

    // Measure the binary search
    t1 = time_now();
    for (int i = 0; i < NUM_QUERIES; ++i)
    {
        BinarySearch(vb, rndDist(rndGen));
    }
    duration = itime_ms(time_now() - t1);
    cout << "Binary search time: " << duration << " ms.\n";
}
