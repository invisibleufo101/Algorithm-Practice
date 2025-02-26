#include <bits/stdc++.h>
using namespace std;
#define lli long long int
lli n;
const lli max_n = 100000;
int arr[max_n+1];
vector<int>v;

lli getGCD(lli a, lli b){
    if (a == 0){
        return b;
    }

    return gcd(b % a, a);
}

lli solve(vector<int>v, lli n){
    lli ret = v[0];
    for (lli i=1; i<n; i++){
        ret = getGCD(v[i], ret);

        if (ret == 1){
            return 1;
        }
    }

    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    
    cin >> n;
    for (int i=0; i<n; i++){
        cin >> arr[i];
    }

    for (int i=1; i<n; i++){
        int diff = arr[i] - arr[i-1];
        v.push_back(diff);
    }

    lli _gcd = solve(v, v.size());

    lli cnt = 0;
    for (lli i=arr[0]; i<=arr[n-1]; i+=_gcd){
        cnt++;
    }

    cout << cnt - n << "\n";
    
    return 0;
}