#include <bits/stdc++.h>
using namespace std;
int t,n,m;
int arr[1000004], toSearch[1000004];

bool binarySearch(int target){
    int lo = 0, hi = n-1;
    while(lo <= hi){
        int mid = (lo + hi) / 2;
        if (arr[mid] == target){
            return 1;
        } else if (arr[mid] > target){
            hi = mid - 1;
        } else if (arr[mid] < target){
            lo = mid + 1;
        }
    }
    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;
    while (t--){
        cin >> n;
        for (int i=0; i<n; i++){
            cin >> arr[i];
        }

        cin >> m;
        for (int i=0; i<m; i++){
            cin >> toSearch[i];
        }

        sort(arr, arr+n);

        for (int i=0; i<m; i++) cout << binarySearch(toSearch[i]) << "\n";

        memset(arr, 0, sizeof(arr));
        memset(toSearch, 0 , sizeof(toSearch));
    }

    return 0;
}