#include <bits/stdc++.h>
using namespace std;
int t,n,m,a1,b1;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> t;
    while (t--){
        
        vector<int>a;
        vector<int>b;

        cin >> n >> m;

        for (int i=0; i<n; i++){
            cin >> a1;
            a.push_back(a1);
        }

        for (int i=0; i<m; i++){
            cin >> b1;
            b.push_back(b1);
        }

        sort(a.begin(), a.end()); 
        sort(b.begin(), b.end());

        int cnt = 0;
        for (int target : a){
            cnt += (lower_bound(b.begin(), b.end(), target) - b.begin());
        }

        cout << cnt << "\n";
    }
    return 0;
}