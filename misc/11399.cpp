#include <bits/stdc++.h>
using namespace std;
int n, t;
vector<int>v;
int arr[1001];

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n;
    for (int i=0; i<n; i++){
        cin >> t;
        v.push_back(t);
    }

    sort(v.begin(), v.end());

    int ret = 0;
    int sm = 0;
    for (int i=0; i<v.size(); i++){
        ret += v[i];
        sm += ret;
    }
    
    cout << sm << "\n";
    
    return 0;
}