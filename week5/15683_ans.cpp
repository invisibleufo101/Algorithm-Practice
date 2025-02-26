#include <bits/stdc++.h>
using namespace std;
int n,m,arr[10][10];
int ret = 987654321;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
vector<pair<int,int>>cameras;

vector<pair<int,int>> rotateCam(int idx, int dir){
    vector<pair<int,int>> watchAreas;
    int y = cameras[idx].first;
    int x = cameras[idx].second;

    switch(arr[y][x]){

        // Cam 1: ->
        // Only need to care about 1 direction
        case 1:
            while(true){
                int ny = y + dy[dir];
                int nx = x + dx[dir];

                if (ny >= 0 && ny < n && nx >= 0 && nx < m && arr[ny][nx] != 6){
                    if (arr[ny][nx] == 0){
                        arr[ny][nx] = 9;
                        watchAreas.push_back({ny,nx});
                    }
                    y = ny;
                    x = nx;
                } else break;
            }
            break;
        
        // Cam 2: <- ->
        // Only care about 2 directions
        case 2:
            for (int i=0; i<=2; i+=2){
                int yVal = y;
                int xVal = x;
                while(true){
                    int ny = yVal + dy[(dir + i) % 4];
                    int nx = xVal + dx[(dir + i) % 4];

                    if (ny >=0 && ny < n && nx >= 0 && nx < m && arr[ny][nx] != 6){
                        if (arr[ny][nx] == 0){
                            arr[ny][nx] = 9;
                            watchAreas.push_back({ny,nx});
                        }
                        yVal = ny;
                        xVal = nx;
                    } else break;
                }
            }
            break;
        
        // Cam 3: ^ >
        // Only care about 2 directions
        case 3:
            for(int i=0; i<2; i++){
                int yVal = y;
                int xVal = x;
                while(true){
                    int ny = yVal + dy[(dir + i) % 4];
                    int nx = xVal + dx[(dir + i) % 4];

                    if (ny >=0 && ny < n && nx >= 0 && nx < m && arr[ny][nx] != 6){
                        if (arr[ny][nx] == 0){
                            arr[ny][nx] = 9;
                            watchAreas.push_back({ny,nx});
                        }
                        yVal = ny;
                        xVal = nx;
                    } else break;
                }
            }
            break;
        
        // Cam 4: < ^ >
        // Only care about 3 directions
        case 4:
            for (int i=0; i<3; i++){
                int yVal = y;
                int xVal = x;
                while(true){
                    int ny = yVal + dy[(dir + i) % 4];
                    int nx = xVal + dx[(dir + i) % 4];

                    if (ny >=0 && ny < n && nx >= 0 && nx < m && arr[ny][nx] != 6){
                        if (arr[ny][nx] == 0){
                            arr[ny][nx] = 9;
                            watchAreas.push_back({ny,nx});
                        }
                        yVal = ny;
                        xVal = nx;
                    } else break;
                }
            }
            break;
        
        // Cam 5: All four directions
        // Need to mark all four direcitons
        case 5:
            for (int i=0; i<4; i++){
                int yVal = y;
                int xVal = x;
                while(true){
                    int ny = yVal + dy[(dir + i) % 4];
                    int nx = xVal + dx[(dir + i) % 4];

                    if (ny >= 0 && ny < n && nx >= 0 && nx < m && arr[ny][nx] != 6){
                        if (arr[ny][nx] == 0){
                            arr[ny][nx] = 9;
                            watchAreas.push_back({ny,nx});
                        }
                        yVal = ny;
                        xVal = nx;
                    } else break;
                }
            }
            break;
    }

    return watchAreas;
}

void dfs(int idx){
    if (idx == cameras.size()){
        int cnt = 0;
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (arr[i][j] == 0) cnt++;
            }
        }
        ret = min(ret, cnt);
        return;
    }

    // Iterate through all possible directions
    for (int i=0; i<4; i++){
        vector<pair<int,int>> watchAreas = rotateCam(idx, i);
        // Backtrack
        dfs(idx+1);
        for (auto pr : watchAreas) arr[pr.first][pr.second] = 0;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> arr[i][j];
            if (arr[i][j] != 6 && arr[i][j] != 0) cameras.push_back({i,j});
        }
    }

    dfs(0);

    cout << ret << "\n";

    return 0;
}