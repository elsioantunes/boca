#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <iostream>
#include <vector>

namespace aed2
{

///////////////////////////////////////////////////////////////////////////////
/// Bubble sort class.
///
/// Implements an in-place bubble sort algorithm.
///////////////////////////////////////////////////////////////////////////////
template <class T>
class BubbleSort
{
public:
    BubbleSort(std::vector<T>& _v);

protected:
    std::vector<T>& _v; ///< Reference to the vector to be sorted.
};

///////////////////////////////////////////////////////////////////////////////
/// Constructor.
///
/// \param v Vector of elements to be sorted in place.
///////////////////////////////////////////////////////////////////////////////
template <class T>
BubbleSort<T>::BubbleSort(std::vector<T>& v) : _v(v)
{
    int size = (int) v.size();
    for (int i = 0; i < size; ++i)
    {
        int swaps = 0;
        for (int j = size - 1; j > i; --j)
        {
            if (v.at(j) < v.at(j - 1))
            {
                // Swap
                T tmp = v.at(j);
                v.at(j) = v.at(j - 1);
                v.at(j - 1) = tmp;
                swaps++;
            }
        }
        if (swaps == 0)
            return;
    }
}

}

#endif // BUBBLESORT_H
