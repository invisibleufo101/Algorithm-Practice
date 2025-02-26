#include <bits/stdc++.h>
using namespace std;
int n, arr[1001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0);

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }

    sort(arr, arr+n);

    for (int i=0; i<n; i++) cout << arr[i] << "\n";

    return 0;
}