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

    int startPoint = 0, endPoint = 0;
    int sum = 0, cnt = 0;

    while(endPoint <= n){
        if (sum < m) sum += v[endPoint++];
        else if (sum > m) sum -= v[startPoint++];
        else if (sum == m){
            cnt++;
            sum += v[endPoint++];
        }
    }

    cout << cnt << "\n";

    return 0;
}