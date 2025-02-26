#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n,m,rides[10004]; 
ll lo, hi = 62000000000;
ll ret;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for (int i=0; i<m; i++){
        cin >> rides[i];
    }

    if (n <= m){
        cout << n << "\n";
        return 0;
    }

    // Binary search the time
    while (lo <= hi){
        ll mid = (lo + hi) / 2; // <- t - 1

        // Count how many people the rides have served 
        // at some specific time frame
        ll cnt = 0;
        for (int i=0; i<m; i++){
            cnt += (mid / rides[i] + bool(mid % rides[i]));
        }

        if (cnt >= n){
            hi = mid - 1;
            
        } else if (cnt < n){
            lo = mid + 1;

            // If the number of people served is less than total,
            // Check if the next time (t + 1) can equal to the total
            for (int i=0; i<m; i++){
                if (mid % rides[i] == 0) cnt++;
                if (cnt == n){
                    cout << i + 1 << "\n";
                    break;
                }
            }
        }        
    }

    return 0;
}