#include <bits/stdc++.h>
using namespace std;
int n,x,cnt=0;
int arr[54];
int del_node,root;
vector<int> adj[54];
int visited[54];

void solve(int u){
    int child = 0;

    if (del_node == u) return;

    for (int v : adj[u]){
        if (v == del_node) continue;
        child++;
        solve(v);
    }

    // If we reach the leaf node, tally up the cnt
    if (child == 0){
        cnt++;
        return;
    }

    return;
}

int main(){
    cin >> n;

    // Create an adjacency list
    for (int i=0; i<n; i++){
        cin >> x;
        if (x == -1) root = i;
        else adj[x].push_back(i);
    }

    cin >> del_node;

    solve(root);
    cout << cnt << "\n";


    return 0;
}