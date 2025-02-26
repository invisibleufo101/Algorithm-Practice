#include <bits/stdc++.h>
using namespace std;
int n,arr[40004],cnt[40004],ret=1;

int binSearch(int lo, int hi, int target){
    while (lo < hi){
        int mid = (lo + hi) / 2;
        if (cnt[mid] < target){
            lo = mid + 1;
        } else if (cnt[mid] >= target){
            hi = mid;
        }
    }
    
    return hi;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i=0; i<n; i++) cin >> arr[i];

    int j=0;
    cnt[0] = arr[0];
    for (int i=1; i<n; i++){
        // If the current number is bigger than the last number in cnt array,
        if (arr[i] > cnt[j]){
            // Add the current number into cnt array
            // and also increment j (because we just added a number in cnt array)
            cnt[++j] = arr[i];
        // Else if the current number is less or equal to the last number,
        } else {
            // Then, use binary search to find the appropriate index to place the current number
            // in the cnt array.
            int idx = binSearch(0, j, arr[i]);
            // Assign the current number to that respective index in cnt array
            cnt[idx] = arr[i];
        }
    }

    cout << j + 1 << "\n";

    return 0;
}

// 8
// 1 8 9 9 9 2 3 4