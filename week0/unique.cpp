#include <bits/stdc++.h>
using namespace std;
vector<int>v;

int main(){
    for (int i=0; i<5; i++){
        v.push_back(i);
        v.push_back(i);
    }

    // for (int i : v) cout << i << "\n";
    // cout << "\n";

    auto it = unique(v.begin(), v.end()); // returning the starting index of the rest of the unorganized vector elements
    v.erase(it, v.end()); // erasing the unorganized elements

    cout << it - v.begin() << "\n"; // 

    for (int i : v) cout << i << "\n";
    
    return 0;
}