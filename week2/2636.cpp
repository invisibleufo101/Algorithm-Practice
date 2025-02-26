#include <bits/stdc++.h>
using namespace std;
int n, m;
int arr[104][104];
int visited[104][104];
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};

void print(int a[104][104]){
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

vector<int> bfs(int y, int x){
    int cnt = 0;
    int iter = 0;
    int size_check[104];
    while (true){
        int cheese_size = 0;
        memset(visited, 0, sizeof(visited));
        visited[y][x] = 1;
        queue<pair<int,int>>q;
        q.push({y,x});
        while(q.size()){
            tie(y,x) = q.front();
            q.pop();
            for(int i=0; i<4; i++){
                int ny = y + dy[i];
                int nx = x + dx[i];

                if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
                if (visited[ny][nx]) continue;

                visited[ny][nx] = 1;

                if (arr[ny][nx] == 1) {
                    cheese_size++;
                    arr[ny][nx] = 0;
                } else {
                    q.push({ny,nx});
                }
            }
        }

        size_check[iter] = cheese_size;

        cnt++;

        int melt_check = 0;
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (arr[i][j]){
                    melt_check++;
                }
            }
        }

        if (melt_check == 0) break;

        iter++;
    }

    vector<int>v = {cnt, size_check[iter]};
    return v;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }

    vector<int>v = bfs(0,0);
    cout << v[0] << "\n" << v[1] << "\n";
    
    return 0;
}


// 5 5 
// 0 0 0 0 0 
// 0 1 1 0 0
// 0 1 0 1 0
// 0 1 1 1 0
// 0 0 0 0 0

// 13 11
// 0 0 0 0 0 0 0 0 0 0 0
// 0 1 1 1 0 0 0 0 0 0 0
// 0 1 1 1 1 1 1 1 0 0 0
// 0 1 0 1 1 1 1 1 0 0 0 
// 0 1 0 1 0 0 0 1 0 0 0 
// 0 1 1 1 0 0 0 1 0 0 0 
// 0 1 1 1 1 1 1 1 0 0 0 
// 0 1 1 0 0 1 1 1 0 0 0 
// 0 1 1 1 1 1 1 1 0 0 0 
// 0 1 1 0 1 1 1 1 0 0 0 
// 0 1 1 1 1 1 1 1 0 0 0 
// 0 1 1 1 1 1 1 1 0 0 0 
// 0 0 0 0 0 0 0 0 0 0 0