#include <bits/stdc++.h>
using namespace std;

int n = 5;
int r = 3;
int a[5] = {1,2,3,4,5}; // integer array

void print(vector<int> v) {
    for (int i: v) {
        cout << a[i] << " ";
    }
    cout << "\n";
}

void combination(int start, vector<int> v) {
    // End condition
    if (v.size() == r) {
        print(v);
        return;
    }

    // Recursion
    for (int i = start + 1; i < n; i++) {
        v.push_back(i); 
        combination(i, v);
        v.pop_back();
    }

    return;
}

int main(){
    vector<int> v;
    combination(-1, v);
    return 0;
}