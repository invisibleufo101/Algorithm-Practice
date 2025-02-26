#include <bits/stdc++.h>
using namespace std;
int n,m;
string s;
int jy, jx, ty, tx;
char arr[301][301];
int visited[301][301];
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};

int solve(int y, int x){
    visited[y][x] = 1;
    deque<pair<int,int>>dq;
    dq.push_front({y,x});

    while(dq.size()){
        tie(y,x) = dq.front();
        dq.pop_front();
        for (int i=0; i<4; i++){
            
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (visited[ny][nx]) continue;

            if (ny == ty - 1 && nx == tx - 1){
                return visited[y][x];
            }

            if (arr[ny][nx] == '0'){
                visited[ny][nx] = visited[y][x];
                dq.push_front({ny,nx});
            } if (arr[ny][nx] == '1'){
                visited[ny][nx] = visited[y][x] + 1;
                dq.push_back({ny, nx});
            }
        }
    }
}

int main(){
    cin >> n >> m;
    cin >> jy >> jx >> ty >> tx;

    for (int i=0; i<n; i++){
        cin >> s;
        for (int j=0; j<m; j++){
            arr[i][j] = s[j];
        }
    }

    cout << solve(jy-1, jx-1) << "\n";

    return 0;
}