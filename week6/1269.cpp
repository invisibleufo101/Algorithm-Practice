#include <bits/stdc++.h>
using namespace std;
int a,b,aSet[200004],bSet[200004];

bool binSearch(int lo, int hi, int target, int arr[]){
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

    cin >> a >> b;
    for (int i=0; i<a; i++) cin >> aSet[i];
    for (int i=0; i<b; i++) cin >> bSet[i];

    sort(aSet, aSet+a); sort(bSet, bSet+b);

    int cnt = 0;
    for (int i=0; i<a; i++){
        if (!binSearch(0, b-1, aSet[i], bSet)) cnt++;
    }
    
    for (int i=0; i<b; i++){
        if (!binSearch(0, a-1, bSet[i], aSet)) cnt++;
    }

    cout << cnt << "\n";

    return 0;
}