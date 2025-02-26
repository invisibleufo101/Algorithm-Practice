#include <bits/stdc++.h>
using namespace std;
// #define ll long long
int x,y,ret;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> x >> y;
    
    int z = ((double) y * 100 / x);
    if (z >= 99){
        cout << -1; 
        return 0;
    }

    int lo = 1, hi = INT_MAX - 1;

    // Binary search the number of extra games needed to play to change the win rate
    while (lo <= hi){
        int mid = (lo + hi) / 2;

        int winRate = ((double)(y + mid) * 100 / (x + mid));

        // If the altered win rate doesn't change,
        // move up the range
        if (winRate == z) lo = mid + 1;
        else if (winRate > z) hi = mid - 1;    
    }

    cout << lo << "\n";

    return 0;
}