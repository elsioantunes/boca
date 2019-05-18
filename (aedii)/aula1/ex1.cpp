#include <iostream>
#include <vector>
using namespace std;

int LinearSearch(const vector<int> &v, const int &key){
    for (int i = 0; i < v.size(); ++i)
        if (v[i] == key)
            return i;
    return -1;
}

int main(){
    vector<int> v {6, 4, 10, 8, 3, 1, 16, 9, 2, 0};
    for (int x : v)
        cout << x << ' ';

    cout << endl;

    int idx = LinearSearch(v, 334);
    
    if (++idx)
        cout << "Key found at " << --idx << "." << endl;
    else
        cout << "Key not found." << endl;
}
