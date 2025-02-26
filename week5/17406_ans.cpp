#include <bits/stdc++.h>
using namespace std;
int arr[104][104], buffer[104][104], visited[104][104];
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
int n,m,k,r,c,s;
int sy,sx,ey,ex,dir;
struct A{
    int y,x,s;
};
int ret = 987654321;
vector<pair<int,int>>coords;
vector<A>ins;
vector<int>insIdx;

// Basically getting coords that need to be rotated by using recursion
void getCoords(int y, int x, int first){
    if (!first && y == sy && x == sx) dir++;
    if (!first && y == sy && x == ex) dir++;
    if (!first && y == ey && x == ex) dir++;
    if (!first && y == ey && x == sx) dir++;

    int ny = y + dy[dir];
    int nx = x + dx[dir];

    if (visited[ny][nx]) return;
    visited[ny][nx] = 1;

    coords.push_back({ny,nx});
    getCoords(ny,nx,0);
}

void rotateVal(int y, int x, int cnt){
    for (int i=1; i<=cnt; i++){
        sy = y - 1 * i;
        sx = x - 1 * i;
        ey = y + 1 * i;
        ex = x + 1 * i;

        coords.clear();
        memset(visited, 0, sizeof(visited));
        dir = 0;

        visited[sy][sx] = 1;
        coords.push_back({sy,sx});

        getCoords(sy,sx,1);

        // From the coordinates that we got from getCoords(),
        // we now get the values in the coordinates and rotate them clockwise
        // Then we over-write the rotated values onto the buffer array
        vector<int>vals;
        for (pair<int,int> coord : coords) vals.push_back(buffer[coord.first][coord.second]);

        rotate(vals.rbegin(), vals.rbegin()+1, vals.rend());

        for (int j=0; j<coords.size(); j++){
            buffer[coords[j].first][coords[j].second] = vals[j];        
        }
    }
}

int solve(){
    for (int i : insIdx) rotateVal(ins[i].y, ins[i].x, ins[i].s);
    int mn = 987654321;

    for (int i=0; i<n; i++){
        int rowSum = 0;
        for (int j=0; j<m; j++){
            rowSum += buffer[i][j];
        }
        mn = min(mn, rowSum);
    }

    return mn;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n >> m >> k;

    for (int i=0; i<n; i++){
        for (int j=0; j<m; j++){
            cin >> arr[i][j];
        }
    }

    for (int i=0; i<k; i++){
        cin >> r >> c >> s;
        ins.push_back({r-1,c-1,s});
        insIdx.push_back(i);
    }

    do{
        memcpy(buffer, arr, sizeof(buffer));
        ret = min(ret, solve());
    }while(next_permutation(insIdx.begin(), insIdx.end()));

    cout << ret << "\n";

    return 0;
}