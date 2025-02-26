#include <bits/stdc++.h>
using namespace std;
int n,x,t;
vector<int>v;
map<int,int>mp;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> t;
        mp[t] = 1;
        v.push_back(t);
    }
    cin >> x;

    sort(v.begin(), v.end());

    int s = 0, e = 0;
    int cnt = 0;

    for (int i=0; i<n; i++){
        int complementary = x - v[i];
        if (mp.find(complementary) != mp.end()){
            cnt++;
        }
    }

    cout << cnt / 2 << "\n";
    

    return 0;
}