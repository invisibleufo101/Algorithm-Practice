#include <bits/stdc++.h>
using namespace std;
int n,m,t;
vector<int>v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i=0; i<n; i++){
        cin >> t;
        v.push_back(t);
    }

    int s=0, e=0;
    int cnt=0, sum = 0;
    for (s=0; s<n; s++){

        while(sum < m && e < n){
            sum += v[e];
            e++;
        }

        if (sum == m) cnt++;
        sum -= v[s];
    }

    cout << cnt << "\n";
    
    return 0;
}