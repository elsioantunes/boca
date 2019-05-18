#ifndef SELECTIONSORT_H
#define SELECTIONSORT_H

#include <iostream>
#include <vector>

namespace aed2
{

///////////////////////////////////////////////////////////////////////////////
/// Selection sort class.
///
/// Implements an in place selection sort algorithm.
///////////////////////////////////////////////////////////////////////////////
template <class T>
class SelectionSort
{
public:
    SelectionSort(std::vector<T>& v);

protected:
    std::vector<T>& _v; ///< Reference to the vector to be sorted.
};

///////////////////////////////////////////////////////////////////////////////
/// Constructor.
///
/// \param _v Vector of elements to be sorted in place.
///////////////////////////////////////////////////////////////////////////////
template <class T>
SelectionSort<T>::SelectionSort(std::vector<T>& v) : _v(v)
{
    int size = (int) v.size();
    for (int i = 0; i < size - 1; ++i)
    {
        int jmin = i;
        for (int j = i + 1; j < size; ++j)
        {
            if (v.at(j) < v.at(jmin))
            {
                jmin = j;
            }
        }
        // Swap
        if (jmin != i)
        {
            T tmp = v.at(i);
            v.at(i) = v.at(jmin);
            v.at(jmin) = tmp;
        }
    }
}

}

#endif // SELECTIONSORT_H