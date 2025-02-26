#include <bits/stdc++.h>
using namespace std;
int n;
int arr[12];
int numOfNeighbors;
int neighbors;
int partyColor[12];
int visited[12];
vector<int> adj[12];
int ret = 987654321;

pair<int,int> dfs(int u, int color){
    visited[u] = 1;
    // Pair value : {weight of the area (1), party color}
    pair<int,int> ret = {1, arr[u]};
    for (int v : adj[u]){
        if (partyColor[v] != color) continue; // If the next node doesn't have the same party color
        if (visited[v]) continue;

        pair<int,int> next = dfs(v, color);
        // Sum up number of areas that the current party is holding
        ret.first += next.first; 
        // Sum up the population of areas that the current party is holding
        ret.second += next.second; 
    }

    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;

    for (int i=1; i<=n; i++){
        cin >> arr[i];
    }

    for (int i=1; i<=n; i++){
        cin >> numOfNeighbors;
        for (int j=0; j<numOfNeighbors; j++){
            cin >> neighbors;
            adj[i].push_back(neighbors);
        }
    }

    for (int i=1; i <(1<<n)/2; i++){
        
        memset(partyColor, 0, sizeof(partyColor));
        memset(visited, 0, sizeof(visited));

        int idx1, idx2;

        // Party color is either 1 or 0
        for (int j=0; j<n; j++){
            if (i & (1 << j)){
                partyColor[j+1] = 1; // party 1
                idx1 = j+1;
            } else {
                idx2 = j+1; // party 2
            }
        }

        pair<int,int> party1 = dfs(idx1, 1);
        pair<int,int> party2 = dfs(idx2, 0);

        int numOfParty1Area = party1.first;
        int numOfParty2Area = party2.first;

        if (numOfParty1Area + numOfParty2Area == n){
            int pop1 = party1.second;
            int pop2 = party2.second;

            ret = min(ret, abs(pop1 - pop2));
        }
    }

    if (ret == 987654321) cout << -1 << "\n";
    else cout << ret << "\n";

    return 0;
}