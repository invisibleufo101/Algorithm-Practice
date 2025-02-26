#include <bits/stdc++.h>
using namespace std;
int n,k;
long long coin;
vector<long long>v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;
    for (int i=0; i<n; i++){
        cin >> coin;
        v.push_back(coin);
    }

    reverse(v.begin(), v.end());
    
    int cnt = 0;
    for (int i=0; i<v.size(); i++){
        if (k >= v[i]){
            cnt += (k / v[i]);
            k %= v[i];
        }
    }

    cout << cnt << "\n";
    
    return 0;
}