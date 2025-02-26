#include <bits/stdc++.h>
using namespace std;
int n,m,t,cnt=0;;
vector<int>v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i=0; i<n; i++){
        cin >> t;
        v.push_back(t);
    }

    int s = 0;
    int e = 0;
    int sum = 0;

    while(e < n){
        if (sum >= m){
            sum -= v[s];
            s++;
        } 
        if (sum < m){
            sum += v[e];
            e++;
        }   

        if (sum == m) cnt++;
    }

    cout << cnt << "\n";

    return 0;
}