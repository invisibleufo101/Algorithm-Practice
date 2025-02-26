#include <bits/stdc++.h>
using namespace std;
int arr[9];
int n=9, r=7;

/**
 * Solving the problem in the most straightforward way
 * 
 * 9c7 
*/

void solve(vector<int>v){
    int sum=0;
    for (auto i: v) sum += i;

    if(sum == 100){
        sort(v.begin(), v.end());
        for (auto i: v) cout << i << "\n";
        exit(0);
    }
}

void combi(int start, vector<int>v){
    if (v.size() == r){
        solve(v);
        return;
    }

    for (int i=start+1; i<n; i++){
        v.push_back(arr[i]);
        combi(i, v);
        v.pop_back();
    }

    return;
}

int main(){
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }
    
    vector<int>v;
    combi(-1, v);

    return 0;
}