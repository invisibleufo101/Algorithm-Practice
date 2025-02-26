#include <bits/stdc++.h>
using namespace std;
int n,m,t,arr[100004];

bool binSearch(int target){
    int lo = 0;
    int hi = n - 1;
    while (lo <= hi){
        int mid = (lo + hi) / 2;
        if (arr[mid] == target) return 1;
        else if (arr[mid] > target) hi = mid - 1; 
        else if (arr[mid] < target) lo = mid + 1;
    }

    return 0;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i=0; i<n; i++) cin >> arr[i];
    sort(arr, arr+n);
    cin >> m;
    for (int i=0; i<m; i++){
        cin >> t;
        cout << binSearch(t) << "\n";
    }

    return 0;
}