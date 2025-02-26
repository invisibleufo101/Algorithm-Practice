#include <bits/stdc++.h>
using namespace std;
int n,arr[1004],cnt[1004],ret=1;

int binSearch(int lo, int hi, int target){
    while (lo <= hi){
        int mid = (lo + hi) / 2;
        if (cnt[mid] > target){
            hi = mid - 1;
        } else if (cnt[mid] < target){
            lo = mid + 1;
        } else if (cnt[mid] == target){
            // If there's a duplicate, then no need to do anything
            hi = mid;
            break;
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
        } else {
            // If the current num is not bigger than the last num in cnt,
            // then find the appropriate index that the current num can go into
            // in the cnt array
            int idx = binSearch(0, j, arr[i]);
            cnt[idx] = arr[i];
        }
    }

    // We add 1 to j because J indicates the last index of the cnt array
    // therefore, we need to add 1 to it to indicate cnt array's size.
    // cnt array: 0 ~ j
    // array size: j + 1 number of elements inside
    cout << j + 1 << "\n";

    return 0;
}