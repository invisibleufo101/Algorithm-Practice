#include <bits/stdc++.h>
using namespace std;
const int V = 100;
int visited [V];
int nodeList[] = {10, 12, 14, 16, 18, 20, 22, 24};
vector<int> adj[V];

void bfs(int u){
    queue<int>q;
    visited[u] = 1;
    q.push(u);

    while(q.size()){

        cout << "Queue: { ";
        for(int i=0; i<q.size(); i++){
            cout << q.front() << " ";
            q.push(q.front());
            q.pop();
        }
        cout << " }\n";

        u = q.front();
        cout << "EXPLORING: " << u << "\n";
        cout << "Depth Level: " << visited[u] << "\n";
        q.pop();
        cout << "Children nodes: ";
        for (int v : adj[u]){
            if (visited[v] == 0){
                cout << v << " ";
                visited[v] = visited[u] + 1;
                q.push(v);
            }
        }
        cout << "\n";
        cout << "EXPLORING " << u << " ENDED\n";
        cout << "------------------------------\n";
    }
    return;
}

int main(){
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
    bfs(10);

    for (int i : nodeList){
        cout << i << " : " << visited[i] << "\n";
    }
 
    cout << "Shortest Distance from 10 to 24 is " << visited[24] - 1 << "\n";

    return 0;
}