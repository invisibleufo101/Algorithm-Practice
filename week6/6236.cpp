#include <bits/stdc++.h>
using namespace std;
int n,m,expenses[100004];
int lo,hi;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for (int i=0; i<n; i++){
        cin >> expenses[i];
        lo = max(lo, expenses[i]);
        hi += expenses[i];
    }

    // Binary search the withdrawl amount, K
    while (lo <= hi){
        int mid = (lo + hi) / 2;

        int leftOver = 0, cnt = 0;
        for (int i=0; i<n; i++){
            if (leftOver == expenses[i]){
                leftOver = 0;
            } else if (leftOver > expenses[i]){
                leftOver -= expenses[i];
            } else if (leftOver < expenses[i]){
                // Deposit leftover and withdraw K amount
                leftOver = mid;
                cnt++; // Tally up withdrawls
                leftOver -= expenses[i];
            }
        }
        
        if (cnt > m) lo = mid + 1;
        else if (cnt <= m) hi = mid - 1;
    }

    cout << lo << "\n";

    return 0;
}