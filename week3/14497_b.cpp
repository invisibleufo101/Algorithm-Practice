#include <bits/stdc++.h>
using namespace std;
/**
 * Solution using 0-1 BFS
 * This is pretty damn fast despite it being so simple!
*/

int n,m;
string s;
int jy, jx, cy, cx;
int arr[301][301];
int visited[301][301];
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};

void zeroOne(int y, int x){
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

            if (ny == cy - 1 && nx == cx - 1){
                cout << visited[y][x] << "\n";
                return;
            }

            if (arr[ny][nx] == 0){
                visited[ny][nx] = visited[y][x];

                dq.push_front({ny,nx});

            } else if (arr[ny][nx] == 1){
                visited[ny][nx] = visited[y][x] + 1;

                dq.push_back({ny, nx});

            }
        }

    }

}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m;
    cin >> jy >> jx >> cy >> cx;

    for (int i=0; i<n; i++){
        cin >> s;
        for (int j=0; j<m; j++){
            if (s[j] == '#') arr[i][j] = 9;
            else if (s[j] == '*') arr[i][j] = 3;
            else arr[i][j] = s[j] - '0';
        }
    }

    zeroOne(jy - 1, jx - 1);

    return 0;
}