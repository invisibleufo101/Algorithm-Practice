#include <bits/stdc++.h>
using namespace std;
int n,x;
int arr[54];
int del_node;
vector<int> adj[54];
int visited[54];
int root;

void print(){
    for (int i=0; i<n; i++){
        cout << i << " :: ";

        if (adj[i].size() == 0){
            cout << "Empty";
        }

        for (int j : adj[i]){
            cout << j << " ";
        }
        cout << "\n";
    }
}

// DFS
int solve(int u){
    int cnt = 0;
    int child = 0;
    cout << "We reached Node" << u << "\n";
    for (int v : adj[u]){
        if (v == del_node) continue;
        child++;
        cout << "Child of " << u << " : " << v << "\n";
        cnt += solve(v);
    } 
    if (child == 0) return 1;
    return cnt;
}

int main(){
    cin >> n;

    // Create an adjacency list
    for (int i=0; i<n; i++){
        cin >> x;
        if (x == -1) root = i;
        else  adj[x].push_back(i);
    }

    cin >> del_node;

    if (del_node == root){
        cout << 0 << "\n";
    } else {
        cout << solve(root) << "\n";
    }

    return 0;
}