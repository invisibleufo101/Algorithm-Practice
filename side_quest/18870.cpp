#include <bits/stdc++.h>
using namespace std;
int n,x;
vector<int>v;
vector<int>v2;
map<int,int>mp;
map<int,int>check;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n; 
    for (int i=0; i<n; i++){
        cin >> x;
        v.push_back(x);

        if (check.find(x) == check.end()){
            v2.push_back(x);
            check[x] = 1;
        }
    }

    sort(v2.begin(), v2.end());

    for (int i=0; i<v2.size(); i++){
        mp[v2[i]] = i;
    }

    for (int i : v){
        cout << mp[i] << " ";
    }

    return 0;
}