#include <bits/stdc++.h>
using namespace std;
int n,m;
int comp1, comp2;
int visited[10004];
vector<int>adj [100004];
int cnt;

void print(){
    for (int i=1; i<=n; i++){
        cout << i << "::";
        for (int j : adj[i]){
            cout << j << " ";
        }
        cout << "\n";
    }
}

void dfs(int u){
    cnt++;
    visited[u] = 1;
    for (int v: adj[u]){
        if (visited[v] == 0){
            dfs(v);
        }
    }
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    for (int i=1; i<=m; i++){
        cin >> comp1 >> comp2;
        adj[comp2].push_back(comp1);
    }

    int max_num = 0;
    vector<int>ret;
    for (int i=1; i<=n; i++){
        memset(visited, 0, sizeof(visited));
        cnt = 0;
        dfs(i);
        if (cnt > max_num){
            max_num = cnt;
            ret.clear();
            ret.push_back(i);
        } else if (cnt == max_num) {
            ret.push_back(i);
        }
    }

    for (int i : ret) cout << i << " ";
    cout << "\n";

    return 0;
}