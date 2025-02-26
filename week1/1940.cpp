#include<bits/stdc++.h>
using namespace std;
int n, m, x;
int arr[15004];
int cnt = 0;

void solve(){
    for (int i=0; i<n; i++){
        for (int j=0; j<i; j++){
            if (arr[i] + arr[j] == m){
                cnt++;
            }
        }
    }
}

int main(){
    cin >> n;
    cin >> m;

    for (int i=0; i<n; i++){
        cin >> x;
        arr[i] = x;
    }

    solve();

    cout << cnt << "\n";

    return 0;
}