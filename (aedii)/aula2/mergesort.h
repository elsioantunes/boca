#ifndef MERGESORT_H
#define MERGESORT_H

#include <iostream>
#include <vector>

namespace aed2
{

///////////////////////////////////////////////////////////////////////////////
/// Merge sort class.
///
/// Implements an in-place recursive Merge sort algorithm.
///////////////////////////////////////////////////////////////////////////////
template <class T>
class MergeSort
{
public:
    MergeSort(std::vector<T>& v);

protected:
    std::vector<T>& _v; ///< Reference to the vector to be sorted.

    void MergeSortRec(int p, int q);
    void MergeRec(int p, int q, int r);
};

///////////////////////////////////////////////////////////////////////////////
/// Constructor.
///
/// \param _v Vector of elements to be sorted in place.
///////////////////////////////////////////////////////////////////////////////
template <class T>
MergeSort<T>::MergeSort(std::vector<T>& v) : _v(v)
{
    MergeSortRec(0, (int) v.size() - 1);
}

///////////////////////////////////////////////////////////////////////////////
/// Recursively sorts v in the range [p, q] using Merge sort.
///
/// \param p Lower range index.
/// \param p Higher range index.
///////////////////////////////////////////////////////////////////////////////
template <class T>
void MergeSort<T>::MergeSortRec(int p, int r)
{
    if (p >= r)
        return;

    auto q = (int) ((p + r) / 2);
    MergeSortRec(p, q);
    MergeSortRec(q + 1, r);
    MergeRec(p, q, r);
}

///////////////////////////////////////////////////////////////////////////////
/// Merges values in the range [p, q] with the values in the range [q, r].
/// Both ranges must contain sorted values.
///
/// \param p Lower range index.
/// \param q Middle range index.
/// \param r Highr range index.
///////////////////////////////////////////////////////////////////////////////
template <class T>
void MergeSort<T>::MergeRec(int p, int q, int r)
{
    std::vector<T> vl, vr;

    auto i = 0, j = 0;

    auto n1 = q - p + 1;
    for (; i < n1; ++i) // Fill vl with values in [p, q]
        vl.push_back(_v.at(p + i));

    auto n2 = r - q;
    for (; j < n2; ++j) // Fill vr with Values in (q, r]
        vr.push_back(_v.at(q + j + 1));

    // Merge vl with vr and outputs to v
    i = j = 0;
    for (auto k = p; k <= r; ++k)
    {
        bool geti = false;

        if (j >= n2 || (i < n1 && vl.at(i) <= vr.at(j)))
            geti = true;

        _v.at(k) = geti ? vl.at(i++) : vr.at(j++);
    }
}

}

#endif // MERGESORT_H
