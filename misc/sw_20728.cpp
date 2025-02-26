#include <bits/stdc++.h>
using namespace std;
int t,n,k;
int arr[51];

int main(){
    cin >> t;
    while (t--){
        cin >> n >> k;
        for (int i=0; i<n; i++){
            cin >> arr[i];
        }

        // Case 1
        sort(arr, arr+n, greater<int>());

        int g1 = arr[0];
        int l1 = arr[k-1];

        // Case 2
        int g2 = arr[n-k];
        int l2 = arr[n-1];

        int ret = min(g1 - l1, g2 - l2);
        cout << ret << "\n";
    }
    return 0;
}