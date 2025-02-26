#include <bits/stdc++.h>
using namespace std;
int n,m;
string s;
int jy, jx, ty, tx;
char arr[301][301];
int visited[301][301];
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};
bool isFound = 0;

void bfs(int y, int x){
    visited[y][x] = 1;
    queue<pair<int,int>>q;
    q.push({y,x});
    while(q.size()){
        tie(y,x) = q.front();
        q.pop();

        for (int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= n || nx >= m) continue;
            if (visited[ny][nx]) continue;

            if (arr[ny][nx] == '0'){
                visited[ny][nx] = visited[y][x];
                q.push({ny,nx});
            } else if (arr[ny][nx] == '1'){
                visited[ny][nx] = visited[y][x] + 1;
                arr[ny][nx] = '0';
            } else if (arr[ny][nx] == '#'){
                isFound = 1;
                return;
            }
        }
    }
    return;
}


int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    cin >> jy >> jx >> ty >> tx;

    for (int i=0; i<n; i++){
        cin >> s;
        for (int j=0; j<m; j++){
            arr[i][j] = s[j];
        }
    }

    int cnt = 0;
    while (true){
        memset(visited, 0, sizeof(visited));
        bfs(jy-1, jx - 1);
        cnt++;

        if (isFound){
            cout << cnt << "\n";
            break;
        }
    }

    return 0;
}