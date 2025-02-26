#include <bits/stdc++.h>
using namespace std;
int visited[4];
vector<int>adj[4];
vector<int>nodes;

void printNodes(){
    cout << "Nodes Status: ";
    for (int node : nodes){
        cout << char(node + 'A') << " ";
    }
    cout << "\n";
}

void dfs(int u){

    printNodes();

    if (nodes.size() == 3){

        for (int node : nodes){
            cout << char(node + 'A') << " ";
        }
        cout << "\n";

        return;
    }

    for (int v : adj[u]){
        if (visited[v] == 0){
            visited[v] = 1;
            nodes.push_back(v);
            dfs(v);
            visited[v] = 0;
            nodes.pop_back();
        }
    }
    return;
}

void restore(int u){
    for (int v : adj[u]){
        if (!visited[v]){
            visited[v] = 1;
            restore(v);
            visited[v] = 0; // <- Restore 
        }
    }
}

int main(){
    adj[0].push_back(1);

	adj[1].push_back(0);
	adj[1].push_back(2);
	adj[1].push_back(3); 

	adj[2].push_back(1);

	adj[3].push_back(1); 

    // Commenting this out makes the function to also print ABA
    // Which is understandable because when the function is SUPPOSED to end
    // at ABD, it back tracks to node B. 
    // Since node A was never marked visited, then it includes A again
    // visited[0] = 1; 
    nodes.push_back(0);
    dfs(0);

    for (int i : visited){
        cout << i << "\n";
    }

    return 0;
}