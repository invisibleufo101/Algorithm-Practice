#include <bits/stdc++.h>
using namespace std;
int n,m;
int cnt=0;
bool break_flag = 0;
string s;
int jy, jx, ty, tx;
int arr[301][301];
int visited[301][301];
int dy[] ={-1,0,1,0};
int dx[] = {0,1,0,-1};

void bfs(int y, int x){
    visited[y][x] = 1;
    queue<pair<int,int>>q;
    q.push({y,x});
    while (q.size()){
        tie(y,x) = q.front();
        q.pop();
        for (int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (visited[ny][nx]) continue;

            // If the thief's coordinates are reached
            if (ny == ty - 1 && nx == tx - 1){
                break_flag = 1;
                return;
            }

            visited[ny][nx] = 1;

            if (arr[ny][nx] == 1){
                // Mark the obstacles (students) as "destroyed"
                arr[ny][nx] = 0;
            } else if (arr[ny][nx] == 0){

                q.push({ny, nx});
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
            if (s[j] == '#'){
                arr[i][j] = 9;
            } else if (s[j] == '*'){
                arr[i][j] = 3;
            } else {
                arr[i][j] = s[j] - '0';
            }
        }
    }

    // Each while loop iteration represents JooNan's bounce
    while (true){
        fill(&visited[0][0], &visited[0][0] + 301 * 301, 0);
        bfs(jy-1, jx-1);
        cnt++; // Count how many times JooNan has bounced
        if (break_flag) break;
    }

    cout << cnt << "\n";

    return 0;
}