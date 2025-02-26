#include<bits/stdc++.h>
using namespace std;
const int V = 100;
int visited[V];
vector<int>adj[V];

void bfs(int u){
    queue<int>q;
    visited[u] = 1;
    q.push(u);
    while(q.size()){
        u = q.front();
        q.pop();
        for (int v : adj[u]){
            if (visited[v]) continue;
            visited[v] = visited[u] + 1;
            q.push(v);
        }
    }
}

void bfs_multiple(int u){
    queue<int>q;
    for (int i : {7,8,9}){
        q.push(i);
        visited[i] = 1;
    }
    while(q.size()){
        u = q.front();
        q.pop();
        for (int v : adj[u]){
            if (visited[v]) continue;
            visited[v] = visited[u] + 1;
            q.push(v);
        }
    }
    
    return;
}



int main(){
    /**
     * Multiple Starting Points
    */
    adj[7].push_back(10);
    adj[8].push_back(10);
    adj[9].push_back(10);

    adj[10].push_back(7);
    adj[10].push_back(8);
    adj[10].push_back(9);
    // ------------------

    adj[10].push_back(12);
    adj[10].push_back(14);
    adj[10].push_back(16);

    adj[12].push_back(10);
    adj[12].push_back(18);
    adj[12].push_back(20);

    adj[14].push_back(10);

    adj[16].push_back(10);

    adj[18].push_back(12);

    adj[20].push_back(12);
    adj[20].push_back(22);
    adj[20].push_back(24);

    adj[22].push_back(20);

    adj[24].push_back(20);

    bfs(7);

    cout << "Shortest distance from 7 to 24: " << visited[20] - 1 << "\n";

    return 0;
}