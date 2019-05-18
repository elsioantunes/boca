#ifndef INSERTIONSORT2_H
#define INSERTIONSORT2_H

#include <iostream>
#include <vector>

namespace aed2
{

///////////////////////////////////////////////////////////////////////////////
/// Insertion sort class.
///
/// Implements an in-place insertion sort algorithm.
///////////////////////////////////////////////////////////////////////////////
template <class T>
class InsertionSort
{	
public:
    InsertionSort(std::vector<T>& v);
	int GetSwaps( ) const { return numSwaps; }

protected:
    std::vector<T>& _v; ///< Reference to the vector to be sorted.
	int numSwaps; ///< Number of swaps performed.
};

///////////////////////////////////////////////////////////////////////////////
/// Constructor.
///
/// \param _v Vector of elements to be sorted in place.
///////////////////////////////////////////////////////////////////////////////
template <class T>
InsertionSort<T>::InsertionSort(std::vector<T>& v) : _v(v)
{
	numSwaps = 0;

    int size = (int) v.size();
    for (int j = 1; j < size; ++j)
    {
        T key = v.at(j);
        int i = j - 1;
        while (i >= 0 && v.at(i) > key)
        {
            v[i + 1] = v[i];
            i--;
			numSwaps++;
        }
        v.at(i + 1) = key;
    }
}

}

#endif // INSERTIONSORT2_H
