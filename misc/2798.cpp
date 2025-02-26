#include <bits/stdc++.h>
using namespace std;
int n,m;
int arr[101];
int ret = 0;

void combi(int start, vector<int>v){
    if (v.size() == 3){
        int sum = accumulate(v.begin(), v.end(), 0);
        if (sum <= m){
            ret = max(ret, sum);
        }
        return;
    }

    for (int i=start+1; i<n; i++){
        v.push_back(arr[i]);
        combi(i,v);
        v.pop_back();
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;

    for (int i=0; i<n; i++){
        cin >> arr[i];
    }    

    vector<int>t;
    combi(-1, t);

    cout << ret << "\n";

    return 0;
}