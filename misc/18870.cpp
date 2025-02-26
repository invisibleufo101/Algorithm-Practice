#include <bits/stdc++.h>
using namespace std;
int n,t;
vector<int>v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> t;
        v.push_back(t);
    }

    vector<int>tmp = v;

    // Must sort before using unique()
    sort(tmp.begin(), tmp.end());
    tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end());

    for (int i=0; i<n; i++){
        int pos = lower_bound(tmp.begin(), tmp.end(), v[i]) - tmp.begin();
        cout << pos << " ";
    }
    cout << "\n";

    return 0;
}