#include <bits/stdc++.h>
using namespace std;
int n,m,j;
int apple_pos;
int visited[11];
vector<int>adj[11];

void print_adj(){
    for (int i=0; i<11; i++){
        cout << i << ":: ";
        for (int j : adj[i]){
            cout << j << " ";
        }
        cout << "\n";
    }
}

int bfs(int start_pos, int end_pos){
    memset(visited, 0, sizeof(visited));
    queue<int>q;
    visited[start_pos] = 1;
    q.push(start_pos);
    while(q.size()){
        start_pos = q.front();
        q.pop();
        for (int v : adj[start_pos]){
            if (visited[v] == 0){
                visited[v] = visited[start_pos] + 1;
                q.push(v);
            }
        }
    }

    return visited[end_pos] - 1;
}

int main(){
    cin >> n >> m >> j;

    // Set up Adjacent List
    for (int i=1; i<11; i++){
        int start = i-1;
        int end = i;

        adj[start].push_back(end);
        adj[end].push_back(start);   
    }

    int start_pos = m;
    int end_pos = 1;
    int ret = 0;

    while (j--){
        cin >> apple_pos;

        if (apple_pos >= end_pos && apple_pos <= start_pos){
            continue;
        }

        if (apple_pos > start_pos){
            ret += bfs(start_pos, apple_pos);
            start_pos = apple_pos;
            end_pos = apple_pos - m + 1;
        } else if (apple_pos < end_pos){
            ret += bfs(end_pos, apple_pos);
            end_pos = apple_pos;
            start_pos = apple_pos + m -1;
        }
    }
    cout << ret << "\n";

    return 0;
}