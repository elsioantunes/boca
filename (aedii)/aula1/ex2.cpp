#include <iostream>
#include <vector>
using namespace std;

template <typename T>
int LinearSearch(const vector<T> &v, const T &key){
    for (int i = 0; i < v.size(); ++i)
        if (v[i] == key)
            return i;
    return -1;
}

int main(){
    vector<string> v {"elsio","bruno","pedro","lucas","aline","renan"};
    for (string x : v)
        cout << x << ' ';
    cout << endl;

    string str = "aline";
    int idx = LinearSearch(v, "aline");
    
    if (++idx)
        cout << "Key found at " << --idx << "." << endl;
    else
        cout << "Key not found." << endl;
}
