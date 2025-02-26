#include <bits/stdc++.h>
using namespace std;
#define lli long long int
int t;
lli n;
const lli max_n = 1000000;
bool sift[max_n+1];

void getPrimes(lli max_n){
    for(int i=2; i<=max_n; i++){
        if (sift[i]) continue;
        for (int j=2*i; j<=max_n; j+=i){
            sift[j] = 1;
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    getPrimes(max_n);

    cin >> t;
    while (t--){
        
        cin >> n;

        lli cnt = 0;

        for (int i=2; i<=n/2; i++){
        
            if (sift[i] == 0){
                lli leftOver = n - i;
                if (sift[leftOver] == 0){
                    cnt++;
                }
            }
        }

        cout << cnt << "\n";
    }

    return 0;
}