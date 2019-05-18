// Linear search in a dynamic size array of 10 keys.

#include <iostream>
#include <vector>

using namespace std;

///////////////////////////////////////////////////////////////////////////////
/// Linear search in a vector (dynamic size array).
///
/// \param v Vector.
/// \param key Search key.
///
/// \return Index of the key found or -1 if not found.
///////////////////////////////////////////////////////////////////////////////
int LinearSearch(const vector<int> &v, const int &key)
{
    for (int i = 0; i < v.size(); ++i)
    {
        if (v[i] == key)
            return i;
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

    // Perform the linear search
    int idx = LinearSearch(v, 9);
    if (idx >= 0)
    {
        cout << "Key found at " << idx << "." << endl;
    }
    else
    {
        cout << "Key not found." << endl;
    }
}
