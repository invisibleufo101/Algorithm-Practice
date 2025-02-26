#include <bits/stdc++.h>
using namespace std;
int n,s;
int arr[21];
int visited[21];
int cnt = 0;

void solve(int idx, int sum){
    visited[idx] = 1;

    if (idx == n){
        if (sum == s) cnt++;
        return;
    }
    
    for (int i=0; i<n; i++){
        if (visited[i]) continue;

        visited[i] = 1;
        sum += arr[i];

        solve(i, sum);

        visited[i] = 0;
        sum -= arr[i];
    }
    return;
}

int main(){
    cin >> n >> s;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }

    solve(0, 0);
    cout << cnt << "\n";

    return 0;
}