#include <bits/stdc++.h>
using namespace std;
long long x, t;
vector<long long>v;

int solve(int n){
    int cnt = 0;
    while (n > 0){
        n = n / 5;
        cnt += n;
    }
    return cnt;
}

int main(){
    cin >> t;

    for (int i=0; i<t; i++){
        cin >> x;
        v.push_back(x);
    }

    for (int i : v){
        cout << solve(i) << "\n";
    }

    return 0;
}