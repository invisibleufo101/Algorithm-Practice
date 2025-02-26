#include <bits/stdc++.h>
using namespace std;
vector<int> v[10];
int visited[10];

void solve(int idx){
    visited[idx] = 1;
    cout << idx << "\n";

    for (int there : v[idx]){
        if (visited[there]) continue;
        solve(there);
    }
}

int main(){
    v[1].push_back(2);
    v[2].push_back(1);

    v[1].push_back(3);
    v[3].push_back(1);

    v[3].push_back(4);
    v[4].push_back(3);

    for (int i=0; i<10; i++){
        if (v[i].size() && visited[i] == 0){
            solve(i);
        }
    }
    return 0;
}