#include <bits/stdc++.h>
using namespace std;
int n,k,ar,ac,l,x,idx;
char c;
int dy[4] = {-1,0,1,0};
int dx[4] = {0,1,0,-1};
int arr[104][104];
int visited[104][104];
deque<pair<int,int>>snake;
vector<pair<int,int>>dirs;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> k;
    for (int i=0; i<k; i++){
        cin >> ar >> ac;
        arr[ar][ac] = 1;
    }

    cin >> l;
    for (int i=0; i<l; i++){
        cin >> x >> c;
        if (c == 'D') dirs.push_back({x, 1});
        else if (c == 'L') dirs.push_back({x, 3});
    }

    int y,x;
    int time = 0;
    int dir = 1;

    snake.push_back({1,1});

    while(snake.size()){
        time++;
        tie(y,x) = snake.front();
        int ny = y + dy[dir];
        int nx = x + dx[dir];

        if (ny <= 0 || nx <= 0 || ny > n || nx > n) break;
        if (visited[ny][nx]) break;

        // If there's an apple on the next step
        if (arr[ny][nx]){
            arr[ny][nx] = 0;
        } else if (!arr[ny][nx]){
            visited[snake.back().first][snake.back().second] = 0;
            snake.pop_back();
        }

        visited[ny][nx] = 1;
        snake.push_front({ny,nx});

        if (time == dirs[idx].first) dir = (dir + dirs[idx++].second) % 4;
    }

    cout << time << "\n";

    return 0;
}