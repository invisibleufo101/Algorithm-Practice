#include <bits/stdc++.h>
using namespace std;
int n,m;
int arr[51][51];
int visited[51][51];
int dy[] = {0,-1,0,1}; // W, N, E, S
int dx[] = {-1,0,1,0}; 
int area;
int roomCnt = 0;
vector<int>areas;

// Vectors for storing coordinates only with inner walls
pair<int,int>roomStartingCoord; 
vector<pair<int,int>>roomCoords;

map<int,int>roomAreas; // Quick access for finding area of a specific room
map<pair<int,int>,int>roomCoord; //  Quick access to find out which room the current coordinate is in
int ret = 0;

void print(int a[51][51]){
    cout << "-------------------\n";
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    cout << "-------------------\n";
}

void dfs(int y, int x){

    roomCoord[{y,x}] = roomCnt;
    roomStartingCoord = {y,x};
    area++;
    
    visited[y][x] = 1;
    for (int i=0; i<4; i++){
        if ( !(arr[y][x] & (1 << i)) ){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (visited[ny][nx]) continue;

            dfs(ny, nx);
        } 
    }
}

void searchDFS(int y, int x, int room){
    visited[y][x] = 1;

    if (roomCoord[{y,x}] != room){
        int joined = roomAreas[room] + roomAreas[roomCoord[{y,x}]];
        ret = max(ret, joined);
        return;
    }

    for (int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
        if (visited[ny][nx]) continue;

        searchDFS(ny, nx, room);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }

    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if (!visited[i][j]){

                area = 0;
                roomStartingCoord = {};
                roomCnt++;
                
                dfs(i,j);

                roomAreas[roomCnt] = area;

                areas.push_back(area);
                roomCoords.push_back(roomStartingCoord);
            }
        }
    }

    cout << roomCnt << "\n";
    cout << *max_element(areas.begin(), areas.end()) << "\n";
    
    int ty,tx;
    for (auto coord : roomCoords){
        memset(visited, 0, sizeof(visited));    
        tie(ty,tx) = coord;
        searchDFS(ty,tx, roomCoord[{ty,tx}]);
    }

    cout << ret << "\n";

    return 0; 
}

// --------------------
// 7 5
// 3 6 3 2 6 3 6
// 1 12 9 8 12 1 4
// 13 3 2 6 15 9 12
// 3 0 0 4 7 11 6
// 9 8 8 12 9 14 13

// 1: 7
// 2 : 11
// 3 : 17

// --------------------
// 4 1
// 15 15 11 14

// 1: 3
// 2: 2
// 3: 3

