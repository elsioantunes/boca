#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool isSorted(vector<int> a){
    for(int i=1;i<a.size();i++)
        if(a[i]<a[i-1]) return false;
    return true;
}

int main(){
    vector<int> a = {10, 2, -1, 7, 8, 3, 20, 4};
    //sort(a.begin(), a.end());

    cout << isSorted(a) << endl;

}