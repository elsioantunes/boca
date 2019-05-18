#ifndef QUICKSORT2_H
#define QUICKSORT2_H

#include <iostream>
#include <vector>

namespace aed2
{

///////////////////////////////////////////////////////////////////////////////
/// Quicksort class.
///
/// Implements an in place Quicksort algorithm.
///////////////////////////////////////////////////////////////////////////////
template <class T>
class QuickSort
{
public:
    QuickSort(std::vector<T>& v);
	int GetSwaps( ) const { return numSwaps; }

protected:
    std::vector<T>& _v; ///< Reference to the vector to be sorted.

    void QuickSortRec(int p, int r);
	int numSwaps; ///< Number of swaps performed.
};

///////////////////////////////////////////////////////////////////////////////
/// Constructor.
///
/// \param _v Vector of elements to be sorted in place.
///////////////////////////////////////////////////////////////////////////////
template <class T>
QuickSort<T>::QuickSort(std::vector<T>& v) : _v(v)
{
	numSwaps = 0;
    QuickSortRec(0, (int) v.size() - 1);
}

///////////////////////////////////////////////////////////////////////////////
/// Recursively sorts v in the range [p, q] using Quicksort.
///
/// \param p Lower range index.
/// \param p Higher range index.
///////////////////////////////////////////////////////////////////////////////
template <class T>
void QuickSort<T>::QuickSortRec(int p, int r)
{
    if (p > r)
        return;

    // Partition
    T key = _v.at(r); // Pivot
    auto i = p - 1;
    for (auto j = p; j < r; ++j)
    {
        if (_v.at(j) <= key)
        {
            i++;
            // Swap v.at(i) <-> v.at(j)
            T tmp = _v.at(i);
            _v.at(i) = _v.at(j);
            _v.at(j) = tmp;
			numSwaps++;
        }
    }
    // swap v.at(i+1) <-> v.at(r)
    T tmp = _v.at(i + 1);
    _v.at(i + 1) = _v.at(r);
    _v.at(r) = tmp;
	numSwaps++;

    auto q = i + 1;
    QuickSortRec(p, q - 1);
    QuickSortRec(q + 1, r);
}

}

#endif // QUICKSORT2_H
