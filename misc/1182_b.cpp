#include <bits/stdc++.h>
using namespace std;
int n,s;
int arr[21];
int cnt = 0;

void solve(int idx, int sum){
    if (idx == n){
        if (sum == s) cnt++;
        return;
    } else if (sum == s){
        cnt++;
        return;
    }
    
    solve(idx + 1, sum + arr[idx]);
    solve(idx + 1, sum);
}

int go(int idx, vector<int>v){
    if (idx == n){
        for (int i : v) cout << i << " ";
        cout << "\n";
        return;
    }

    go(idx+1, v);
    v.push_back(arr[idx]);
    go(idx+1, v);
    v.pop_back();
}

int main(){
    ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);

    cin >> n >> s;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }

    // if (s == 0){
    //     cnt--;
    // }

    // solve(0, 0);
    // cout << cnt << "\n";

    
    vector<int>t;
    go(0, t);

    


    return 0;
}