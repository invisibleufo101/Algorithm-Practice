#include <bits/stdc++.h>
using namespace std;
int n,m,arr[10][10], spaceCnt;
vector<pair<int,int>>cameras;
int dy[4] = {-1,0,1,0}; // Up, Right, Down, Left
int dx[4] = {0,1,0,-1};
int ret = 987654321;

void print(){
    cout << "-------------------------\n";
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

vector<int> getCameraDir(int cameraType){
    switch (cameraType){
        case 1: return {1};
        case 2: return {1,3};
        case 3: return {0,1};
        case 4: return {0,1,3};
        case 5: return {0,1,2,3};
    }
}

vector<int> rotateCamera(vector<int>dirs){
    vector<int>tmp;
    for (int dir : dirs) tmp.push_back((dir + 1) % 4);
    return tmp;
}

void markWatchArea(int y, int x, vector<int>dirs){
    for (int dir : dirs){
        int yVal = y;
        int xVal = x;
        while (1){
            int ny = yVal + dy[dir];
            int nx = xVal + dx[dir];

            yVal = ny;
            xVal = nx;

            if (ny < 0 || ny >= n || nx < 0 || nx >= m) break; // If out of bounds
            if (arr[ny][nx] == 6) break; // If it's a wall
            if (arr[ny][nx] != 0) continue; // If next step is another camera

            arr[ny][nx] = 9;
        }
    }
}

void solve(int idx){
    if (idx == cameras.size()){
        int blanks = 0;
        for (int i=0; i<n; i++){
            for (int j=0; j<m; j++){
                if (arr[i][j] == 0) blanks++;   
            }
        }
        
        ret = min(ret, blanks);
        return;
    }

    int tmpArr[10][10];

    int y = cameras[idx].first;
    int x = cameras[idx].second;
    int camType = arr[y][x];
    vector<int>dirs = getCameraDir(camType);

    switch(camType){
        case 1:
            for (int i=0; i<4; i++){
                memcpy(tmpArr, arr, sizeof(tmpArr));
                dirs = rotateCamera(dirs);
                markWatchArea(y,x,dirs);
                solve(idx+1);
                memcpy(arr, tmpArr, sizeof(arr));
            }
            break;

        case 2:
            for (int i=0; i<2; i++){
                memcpy(tmpArr, arr, sizeof(tmpArr));
                dirs = rotateCamera(dirs);
                markWatchArea(y,x,dirs);
                solve(idx+1);
                memcpy(arr, tmpArr, sizeof(arr));
            }
            break;

        case 3:
            for (int i=0; i<4; i++){
                memcpy(tmpArr, arr, sizeof(tmpArr));
                dirs = rotateCamera(dirs);
                markWatchArea(y,x,dirs);
                solve(idx+1);
                memcpy(arr, tmpArr, sizeof(arr));
                
            }
            break;

        case 4:
            for (int i=0; i<4; i++){
                memcpy(tmpArr, arr, sizeof(tmpArr));
                dirs = rotateCamera(dirs); 
                markWatchArea(y,x,dirs);
                solve(idx+1);
                memcpy(arr, tmpArr, sizeof(arr));
            }
            break;

        case 5:
            memcpy(tmpArr, arr, sizeof(tmpArr));
            markWatchArea(y,x,dirs);
            solve(idx+1);
            memset(arr, 0, sizeof(arr));
            memcpy(arr, tmpArr, sizeof(arr));
            break;
    }   

    return;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> arr[i][j];
            if (arr[i][j] != 0 && arr[i][j] != 6) cameras.push_back({i,j});
        }
    }

    solve(0);
    cout << ret << "\n";

    return 0;
}