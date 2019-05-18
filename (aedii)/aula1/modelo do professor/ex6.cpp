// Random queries of a string vector from standard input.
// Run with: $ ./ex6 < wordlist.txt

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <random>

#include "timing.h"

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
    // Read a vector of strings from the standard input
    vector<string> vl;

    int words = 0;
    string line;
    while (getline(cin, line))
    {
        vl.push_back(line);
        words++;
    }
    cout << words << " words read." << endl;

    int seed = (int) chrono::system_clock::now().time_since_epoch().count();

    // Set up a random uniform distribution
    uniform_int_distribution<int> rndDist(0, (int)vl.size()-1);

    // Random number generator
    default_random_engine rndGen(seed);

    // Measure the linear search
    time_point t1 = time_now();
    for (int i = 0; i < NUM_QUERIES; ++i)
    {
        LinearSearch(vl, vl[rndDist(rndGen)]);
    }
    auto duration = itime_ms(time_now() - t1);
    cout << "Linear search time: " << duration << " ms.\n";

    // Reset random number generator
    rndGen.seed(seed);

    // Create a sorted version for binary search
    vector<string> vb = vl;
    time_point tss = time_now();
    sort(vb.begin(), vb.end());
    cout << "Sorted for binary search in " << itime_ms(time_now() - tss) << " ms.\n";

    // Measure the binary search    
    t1 = time_now();
    for (int i = 0; i < NUM_QUERIES; ++i)
    {
        BinarySearch(vb, vb[rndDist(rndGen)]);
    }
    duration = itime_ms(time_now() - t1);
    cout << "Binary search time: " << duration << " ms.\n";

}
