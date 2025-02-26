#include <bits/stdc++.h>
using namespace std;
int n;

int main(){

    vector<int>v = {5,10,13,14,15,30,50};
    int pos = lower_bound(v.begin(), v.end(), 11) - v.begin();

    cout << pos << "\n";
    v[pos] = 11;

    for (int i : v) cout << i << " ";
    cout << "\n";


    return 0;
}