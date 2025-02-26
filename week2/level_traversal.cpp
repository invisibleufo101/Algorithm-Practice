#include <bits/stdc++.h>
using namespace std;
vector<int>adj[1004];
int visited[1004];

void postOrder(int u) {
    if (!visited[u]) {
        for (int v : adj[u]){
            postOrder(v);
        }
        visited[u] = 1;
        cout << u << "\n";
    }
    return;
}

void preOrder(int u){
    if (!visited[u]){
        cout << u << "\n";
        visited[u] = 1;
        for (int v : adj[u]){
            preOrder(v);
        }
    }

    return;
}

void inOrder(int u){
    if (!visited[u]){
        if (adj[u].size() == 2){
            inOrder(adj[u][0]);
            visited[u] = 1;
            cout << u << "\n";
            inOrder(adj[u][1]);
        } else if (adj[u].size() == 1){
            inOrder(adj[u][0]);
            visited[u] = 1;
            cout << u << "\n";
        } else {
            cout << u << "\n";
            visited[u] = 1;
        }
        
    }
    return;
}

int main(){
    // adj[1].push_back(2);
    // adj[1].push_back(3);

    // adj[2].push_back(1);
    // adj[2].push_back(4);

    // adj[3].push_back(1);

    // adj[4].push_back(2);
    // adj[5].push_back(2);

    // Only works for one-directional node tree
    // adj[1].push_back(2);
    // adj[1].push_back(3);
    // adj[2].push_back(4);
    // adj[2].push_back(5);

    adj[1].push_back(2);
    adj[1].push_back(3);

    adj[2].push_back(4);
    
    adj[3].push_back(5);
    adj[3].push_back(6);

    adj[4].push_back(8);

    adj[5].push_back(7);

    adj[6].push_back(9);
    adj[6].push_back(10);

    int root = 1;
    cout << "\n PostOrder : \n";
    postOrder(root);
    memset(visited, 0, sizeof(visited));

    cout << "\n PreOrder : \n";
    preOrder(root);
    memset(visited, 0, sizeof(visited));

    cout << "\n InOrder : \n";
    inOrder(root);
    
    return 0;
}