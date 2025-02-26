#include <bits/stdc++.h>
using namespace std;
int n,k;
int visited[200002];
int steps[200002];
vector<int>ret;
vector<int> cnt[200002];


void bfs(int u){
    visited[u] = 1;
    queue<int>q;
    q.push(u);

    while (q.size()){
        u = q.front();
        q.pop();

        int dir[] = {u - 1, u + 1, u * 2};
        for (int i=0; i<3; i++){
            int nu = dir[i];

            // If out of bounds
            if (nu < 0 || nu >= 200002) continue;
            // If not been visited before
            if (!visited[nu]){

                cnt[nu].push_back(u);

                visited[nu] = visited[u] + 1;
                q.push({nu});
            }
        }
    }
}

// Using DFS to print all the connected nodes
void print(int u){
    for (int v : cnt[u]){
        print(v);
    }
    cout << u << " ";
    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;
    
    bfs(n);

    // Time to find lil bro
    cout << visited[k] - 1 << "\n";

    // Steps to find him
    print(k);
    cout << "\n";

    return 0;
}