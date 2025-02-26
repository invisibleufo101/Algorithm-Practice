#include <bits/stdc++.h>
using namespace std;
const int INF = 987654321;
int r,c;
int y,x;
string s;
char arr[1001][1001];
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};
queue<pair<int,int>>fires;
pair<int,int>jh;
int f_visited[1001][1001];
int j_visited[1001][1001];

void print(int a[1001][1001]){
    for (int i=0; i<r; i++){
        for (int j=0; j<c; j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
    return;
}

void f_go(){
    while (fires.size()){
        tie(y,x) = fires.front();
        fires.pop();

        for (int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            // If out of bounds
            if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
            // If next step is a wall
            if (arr[ny][nx] == '#') continue;

            // If next step has been visited
            // Think of INF as another 0 
            // This is to mark the unvisited area
            if (f_visited[ny][nx] != INF) continue; 

            f_visited[ny][nx] = f_visited[y][x] + 1;
            fires.push({ny,nx});
        }
    }
}

int j_go(int y, int x){
    j_visited[y][x] = 1;
    queue<pair<int,int>>q;
    q.push({y,x});
    while (q.size()){
        tie(y,x) = q.front();
        q.pop();

        if (y == 0 || x == 0 || y == r-1 || x == c-1){
            return j_visited[y][x];
        }

        for (int i=0; i<4; i++){
            int ny = y + dy[i];
            int nx = x + dx[i];

            // If next step is out of bounds    
            if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
            // If next step is a wall
            if (arr[ny][nx] == '#') continue;
            // If next step's been visited
            if (j_visited[ny][nx]) continue;
            // If there's a fire in the next step
            if (j_visited[y][x] + 1 >= f_visited[ny][nx]) continue;
            
            j_visited[ny][nx] = j_visited[y][x] + 1;
            q.push({ny, nx});
        }
    }
    // If there's no OUT, then return -1
    return -1;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> r >> c;

    // Ok, so using fill like this:
    // fill(&f_visited[0][0], &f_visited[1001][1001], INF);
    // can cause Out Of Bounds error. So let's use the function like this below:
    fill(&f_visited[0][0], &f_visited[0][0] + 1001 * 1001, INF);

    for (int i=0; i<r; i++){
        cin >> s;
        for (int j=0; j<c; j++){
            arr[i][j] = s[j];

            if (arr[i][j] == 'J') jh = {i,j};
            else if (arr[i][j] == 'F'){
                fires.push({i,j});
                f_visited[i][j] = 1;
            }
        }
    }

    f_go();
    int ret = j_go(jh.first, jh.second);

    if (ret == -1) cout << "IMPOSSIBLE\n";
    else cout << ret << "\n";

    return 0;
}