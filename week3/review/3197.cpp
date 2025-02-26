#include <bits/stdc++.h>
using namespace std;
int r,c;
string s;
char arr[1501][1501];
int visited[1501][1501];
int s_visited[1501][1501];
int sy, sx;
int y,x;
int dy[] = {-1, 0 ,1, 0};
int dx[] = {0, 1, 0, -1};
pair<int,int>swan_start_pos;
queue<pair<int,int>>swans, new_swans;
queue<pair<int,int>>waters, new_waters;

bool haveMet(){
    while (swans.size()){
        tie(sy, sx) = swans.front();
        swans.pop();

        for (int i=0; i<4; i++){
            int nsy = sy + dy[i];
            int nsx = sx + dx[i];

            if (nsy < 0 || nsx < 0 || nsy >= r || nsx >= c) continue;
            if (s_visited[nsy][nsx]) continue;


            s_visited[nsy][nsx] = 1;

            if (arr[nsy][nsx] == 'X'){
                new_swans.push({nsy, nsx});
            } else if (arr[nsy][nsx] == '.'){
                swans.push({nsy, nsx});
            } else if (arr[nsy][nsx] == 'L'){
                return true;
            }
        }
    }
    return false;
}

void melt(){
    while (waters.size()){
        tie(y,x) = waters.front();
        waters.pop();

        for (int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
            if (visited[ny][nx]) continue;

            visited[ny][nx] = 1;

            if (arr[ny][nx] == 'X'){
                arr[ny][nx] = '.';
                new_waters.push({ny, nx});
            } else if (arr[ny][nx] == '.'){
                waters.push({ny,nx});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr); cout.tie(nullptr);

    cin >> r >> c;
    for (int i=0; i<r; i++){
        cin >> s;
        for (int j=0; j<c; j++){
            arr[i][j] = s[j];

            if (arr[i][j] == '.'){
                waters.push({i,j});
            } else if (arr[i][j] == 'L'){
                swan_start_pos = {i,j};
                waters.push({i,j});
            } 
        }
    }

    swans.push(swan_start_pos);
    s_visited[swan_start_pos.first][swan_start_pos.second] = 1;

    int day = 0;
    while (true){
        if (haveMet()){
            cout << day << "\n";
            break;
        }

        melt();
        // Pass newly acquired coordinates to the old containers
        waters = new_waters;
        swans = new_swans;

        // Reset new coordinates
        queue<pair<int,int>>temp;
        new_waters = temp;
        new_swans = temp;

        day++;
    }

    return 0;
}