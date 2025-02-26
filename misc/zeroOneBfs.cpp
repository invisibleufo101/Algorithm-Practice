#include <bits/stdc++.h>
using namespace std;
int r,c;
int arr[1001][1001];
int visited[1001][1001];
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};

void zeroOneBfs(int y, int x){
    visited[y][x] = 1;
    deque<pair<int,int>>dq;
    dq.push_front({y,x});
    while(dq.size()){
        tie(y,x) = dq.front();
        dq.pop_front();
        for (int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
            if (visited[ny][nx]) continue;

            // If the weight of the edge is 0
            if (arr[ny][nx] == 0){
                visited[ny][nx] = visited[y][x];
                dq.push_front({ny, nx}); // Consider that the
            // If the weight of the edge is 1
            } else if (arr[ny][nx] == 1){
                visited[ny][nx] = visited[y][x] + 1;
                dq.push_back({ny, nx});
            }
        }
    }
}

int main(){
    r = 5;
    c = 5;

    return 0;
}