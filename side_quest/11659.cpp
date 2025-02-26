#include <bits/stdc++.h>
using namespace std;
int n,m,s,e;
int arr[100004];
int psum[100004];
vector<pair<int,int>>v;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);
    cin >> n >> m;

    for (int i=1; i<=n; i++){
        cin >> arr[i];
        psum[i] = psum[i-1] + arr[i];
    }


    for (int i=0; i<m; i++){
        cin >> s >> e;
        int ret = psum[e] - psum[s-1];
        cout << ret << "\n";
    }

    return 0;
}