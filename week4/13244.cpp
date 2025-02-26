#include <bits/stdc++.h>
using namespace std;
int t;
int n,m;
int a,b;
vector<int> adj[1002];
int visited[1002];
int c_visited[1002];

void printAdj(){
    for (int i=1; i<=n; i++){
        cout << i <<  " :: ";
        for (int j : adj[i]){
            cout << j << " ";
        }
        cout << "\n";
    }
}

// Check if all components are connected
void check(int u){
    c_visited[u] = 1;
    for (int v : adj[u]){
        if (c_visited[v]) continue;

        check(v);
    }
}

// Checks if there's a cycle
bool hasCycle(int u, int parent){
    visited[u] = 1;
    for (int v : adj[u]){
        if (!visited[v]){
            if (hasCycle(v, u)) return true;
        } else if (v != parent){
            return true;
        }
    }

    return false;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    vector<int>temp[1002];
    cin >> t;    
    while (t--){

        int startingPoint;        
        // Inputs
        cin >> n;
        cin >> m;
        for (int i=0; i<m; i++){
            cin >> a >> b;
            adj[a].push_back(b);
            adj[b].push_back(a);

            startingPoint = a;
        }


        int componentCnt = 0;
        bool isConnected = 0;
        for (int i=1; i<=n; i++){
            for (int j : adj[i]){
                if (!c_visited[j]){
                    componentCnt++;
                    check(j);
                }
            }
        }

        if (componentCnt == 1) isConnected = 1;
        else isConnected = 0;

        bool isCycle = hasCycle(startingPoint,-1);

        if (!isCycle && isConnected) cout << "tree\n";
        else cout << "graph\n";

        
        // Reset visited arrays
        memset(visited, 0, sizeof(visited));
        memset(c_visited, 0 , sizeof(c_visited));

        // Reset adjacnecy list
        for (int i=1; i<=n; i++){
            adj[i].clear();
        }
    }

    return 0;
}