#include <bits/stdc++.h>
using namespace std;
int n;
int arr[12];
vector<int>adj [12];
int numOfNeigh;
int neighbors;
vector<int>areas;
int toVisit[12];
int visited[12];
int ret = 987654321;
vector<int>b;

void printV(vector<int>v){
    cout << "Party: ";
    for (int i : v) cout << i << " ";
    cout << "\n";
}

void printAdj(){
    for (int i=1; i<7; i++){
        cout << i << "::";
        for (int j : adj[i]){
            cout << j << " ";
        }
        cout << "\n";
    }
}
void searchChildren(int u){
    visited[u] = 1;
    b.push_back(u);
    for (int v : adj[u]){
        if (toVisit[v] && !visited[v]){
            searchChildren(v);
        }
    }
}

bool checkIfValid(vector<int>party){
    if (party.size() == 1) return true;
    b.clear();
    memset(visited, 0, sizeof(visited));
    memset(toVisit, 0, sizeof(toVisit));

    // Setting up nodes that the searchChildren function NEEDS to visit
    for (int i : party) toVisit[i] = 1;

    searchChildren(party[0]);

    if (b.size() != party.size()) return false;
    return true;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    for (int i=1; i<=n; i++){
        cin >> arr[i];
    }

    // Making an adjacent list
    for (int i=1; i<=n; i++){
        areas.push_back(i);
        cin >> numOfNeigh;
        for (int j=0; j<numOfNeigh; j++){
            cin >> neighbors;
            adj[i].push_back(neighbors);
        }
    }

    // Make combination of areas
    for (int i=1; i < ((1 << n)/2); i++){
        vector<int>party1;
        int party1Pop = 0;

        vector<int>party2;
        int party2Pop = 0;

        for (int j=0; j<n; j++){
            if (i & (1 << j)){
                party1.push_back(areas[j]);
                party1Pop += arr[areas[j]];
            } else {
                party2.push_back(areas[j]);
                party2Pop += arr[areas[j]];
            }
        }

        int popDiff = abs(party1Pop - party2Pop);        
        if (popDiff >= ret) continue;

        if (checkIfValid(party1) && checkIfValid(party2)){
            ret = min(ret, popDiff);
        }
    }

    if (ret == 987654321) cout << -1 << "\n";
    else cout << ret << "\n";

    
    return 0;
}