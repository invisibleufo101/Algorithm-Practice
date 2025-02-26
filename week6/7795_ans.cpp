#include <bits/stdc++.h>
using namespace std;
int t,n,m;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;
    while(t--){
        int ret = 0;
        cin >> n >> m;
        vector<int>a(n),b(m);
        for (int i=0; i<n; i++) cin >> a[i];
        for (int i=0; i<m; i++) cin >> b[i];

        sort(a.begin(), a.end()); sort(b.begin(), b.end());
        for (int i=0; i<n; i++){
            int pos = lower_bound(b.begin(), b.end(), a[i]) - b.begin();
            ret += pos;
        }
        cout << ret << "\n";
    }

    return 0;
}