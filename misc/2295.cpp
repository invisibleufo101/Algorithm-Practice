#include <bits/stdc++.h>
using namespace std;
#define ll long long
ll n, arr[1004],ret=-1;
map<ll,ll>mp;

void solve(ll idx, ll sum, ll cnt){
    if (idx == n){
        if (mp.find(sum) != mp.end()) ret = max(ret, sum);
        return;
    } else if (cnt == 3){
        if (mp.find(sum) != mp.end()) ret = max(ret, sum);
    }

    solve(idx+1, sum, cnt);
    solve(idx+1, sum+arr[idx], cnt+1);
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> arr[i];
        mp[arr[i]]++;
    }

    sort(arr, arr+n);


    
    return 0;
}