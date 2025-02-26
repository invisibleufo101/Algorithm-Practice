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


    int cnt = 0;
    for (int i=0; i<n; i++){
        long long sum = 0;
        for (int j=i; j<n; j++){
            sum += v[j];
            if (sum == m){
                cnt++;
                break;
            } else if (sum > 300000000){
                break;
            }
        }
    }

    cout << cnt << "\n";
    
    return 0;
}