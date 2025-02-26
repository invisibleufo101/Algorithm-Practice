#include <bits/stdc++.h>
using namespace std;
int n,x,t;
vector<int>v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> t;
        v.push_back(t);
    }
    cin >> x;

    sort(v.begin(), v.end());

    for (int i : v) cout << i << " ";
    cout << "\n";

    int s = 0, e = 0;
    int cnt = 0;

    while(e < n){
        if (v[s] + v[e] < x){
            e++;
        } else if (v[s] + v[e] > x){
            s++;
        } else if (v[s] + v[e] == x){
            cnt++;
            e++;
        }
    }

    cout << cnt << "\n";

    return 0;
}