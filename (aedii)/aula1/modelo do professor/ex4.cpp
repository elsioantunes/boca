// Timing a single query of linear search and binary search.

#include <iostream>
#include <vector>
#include <algorithm>

#include "timing.h"

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
    // Create a vector containing 10 integer keys
    vector<int> v {6, 4, 10, 8, 3, 1, 16, 9, 2, 0};
   
    // Iterate and print keys of vector
    for (int x : v)
    {
        cout << x << ' ';
    }
    cout << endl;

    // Measure the linear search
    time_point t1 = time_now();
    LinearSearch(v, 9);
    auto duration = itime_ns(time_now() - t1);
    cout << "Linear search time: " << duration << " ns.\n";

    // Array must be sorted
    sort(v.begin(), v.end());

    // Measure the binary search
    t1 = time_now();
    BinarySearch(v, 9);
    duration = itime_ns(time_now() - t1);
    cout << "Binary search time: " << duration << " ns.\n";
}
