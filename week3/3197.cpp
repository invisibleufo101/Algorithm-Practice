#include <bits/stdc++.h>
using namespace std;
int r,c;
string s;
int arr[1504][1504];
int visited[1504][1504];
int swan_visit[1504][1504];
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};
int y,x,sy,sx;

pair<int,int>swan_pos; // Initial swan position
queue<pair<int,int>>waters;
queue<pair<int,int>>updated_waters;
queue<pair<int,int>>swans;
queue<pair<int,int>>updated_swans;

void print(){
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

bool isMet(){
    while(swans.size()){
        tie(sy, sx) = swans.front();
        swans.pop();

        for (int i=0; i<4; i++){
            int nsy = sy + dy[i];
            int nsx = sx + dx[i];

            if (nsy < 0 || nsx < 0 || nsy >= r || nsx >= c) continue;
            if (swan_visit[nsy][nsx]) continue;

            swan_visit[nsy][nsx] = 1;

            if (arr[nsy][nsx] == 0){
                swans.push({nsy, nsx});
            } else if (arr[nsy][nsx] == 1){
                updated_swans.push({nsy, nsx});
            } else if (arr[nsy][nsx] == 9){
                return true;
            }
        }
    }
    return false;
}

void melt(){
    while(waters.size()){
        tie(y,x) = waters.front();
        waters.pop();

        for (int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
            if (visited[ny][nx]) continue;

            visited[ny][nx] = 1;

            if (arr[ny][nx] == 1){
                arr[ny][nx] = 0;
                updated_waters.push({ny, nx});
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> r >> c;
    for (int i=0; i<r; i++){
        cin >> s;
        for (int j=0; j<c; j++){
            if (s[j] == '.'){
                arr[i][j] = 0;
                waters.push({i,j});
            } else if (s[j] == 'X'){
                arr[i][j] = 1;
            } else if (s[j] == 'L'){
                arr[i][j] = 9;
                swan_pos = {i,j};
                waters.push({i,j});
            }
        }
    }

    int day = 0;
    swan_visit[swan_pos.first][swan_pos.second] = 1;
    swans.push(swan_pos);

    while (true){
        // Check if swans have met 
        if (isMet()){
            cout << day << "\n";
            break;
        }

        melt();

        // Transferring the newly melted water coords to the original queue
        waters = updated_waters;
        swans = updated_swans;

        queue<pair<int,int>>tmp;
        updated_waters = tmp;
        updated_swans = tmp;

        day++;
    }

    return 0;
}