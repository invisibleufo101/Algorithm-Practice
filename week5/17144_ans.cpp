#include <bits/stdc++.h>
using namespace std;
int n,m,t;
int arr[54][54];
vector<pair<int,int>>area1, area2;
int dy1[4] = {0, -1, 0, 1};
int dx1[4] = {1, 0, -1, 0};
int dy2[4] = {0, 1, 0, -1};
int dx2[4] = {1, 0, -1, 0};

void spread(int dy[4], int dx[4]){
    // Initialize buffer array
    int tmp[54][54];
    memset(tmp, 0, sizeof(tmp));

    queue<pair<int,int>>dustQ;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (arr[i][j] != -1 && arr[i][j]){
                dustQ.push({i,j});
            }
        }
    }

    while(dustQ.size()){
        int y,x;
        tie(y,x) = dustQ.front();
        dustQ.pop();
        int spreadVal = arr[y][x] / 5;
        
        for (int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (arr[ny][nx] == -1) continue;

            // Record the changed value of each block on tmp array
            // Or else each spread of dust will affect each other
            tmp[ny][nx] = spreadVal;
            arr[y][x] -= spreadVal;
        }
    }

    // Apply the changed value to arr again
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            arr[i][j] += tmp[i][j];
        }
    }
}

void circulate(vector<pair<int,int>> &v){
    for (int i=v.size()-1; i>0; i--){
        arr[v[i].first][v[i].second] = arr[v[i-1].first][v[i-1].second];
    }
    arr[v[0].first][v[0].second] = 0;
    return;
}

vector<pair<int,int>> getCoord(int sy, int sx, int dy[4], int dx[4]){
    vector<pair<int,int>>v;
    int cnt = 0;
    int y = sy;
    int x = sx;
    while(true){
        int ny = y + dy[cnt];
        int nx = x + dx[cnt];

        if (ny == sy && nx == sx) break;
        if (ny < 0 || nx < 0 || ny >= n || nx >= m){
            cnt++;
            ny = y + dy[cnt];
            nx = x + dx[cnt];
        }
        if (ny == sy && nx == sx) break;
        y = ny;
        x = nx;
        v.push_back({ny, nx});
    }
    return v;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> t;
    bool flag = 1;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> arr[i][j];

            if (arr[i][j] == -1){
                if (flag){
                    area1 = getCoord(i, j, dy1, dx1);
                    flag = 0;
                } else if (!flag){
                    area2 = getCoord(i, j, dy2, dx2);
                }
            }
        }
    }

    while(t--){
        spread(dy1, dx1);
        circulate(area1); circulate(area2);
    }

    int ret = 0;
    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            if (arr[i][j] != -1){
                ret += arr[i][j];
            }
        }
    }

    cout << ret << "\n";

    return 0;
}