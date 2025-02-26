#include <bits/stdc++.h>
using namespace std;
int n,a,b,arr[104],cnt[104],ret;
vector<pair<int,int>>v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i=0; i<n; i++) cin >> a >> b, v.push_back({a,b});
    sort(v.begin(), v.end());

    for (int i=0; i<n; i++){
        cnt[i] = 1;
        for (int j=0; j<i; j++){
            if (v[j].second < v[i].second){
                cnt[i] = max(cnt[i], cnt[j]+1);
                ret = max(ret, cnt[i]);
            }
        }
    }

    cout << n - ret << "\n";

    return 0;
}