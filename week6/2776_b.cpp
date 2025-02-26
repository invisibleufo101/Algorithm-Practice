#include <bits/stdc++.h>/
using namespace std;
int t,n,m,target, arr[1000004];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;
    while (t--){
        memset(arr,0,sizeof(arr));

        cin >> n;
        for (int i=0; i<n; i++) cin >> arr[i];
        sort(arr,arr+n);
        cin >> m;
        for (int i=0; i<m; i++){
            cin >> target;
            if (binary_search(arr, arr+n, target)) cout << 1 << "\n";
            else cout << 0 << "\n";
        }
    }
    return 0;
}