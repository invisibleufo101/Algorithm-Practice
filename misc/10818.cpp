#include <bits/stdc++.h>
using namespace std;
int n,x;

int main(){
    cin >> n;
    int mx = -1e7;
    int mn = 1e7;
    
    for (int i=0; i<n; i++){
        cin >> x;
        mx = max(mx, x);
        mn = min(mn, x);
    }

    cout << mn << " " << mx << "\n";

    return 0;
}