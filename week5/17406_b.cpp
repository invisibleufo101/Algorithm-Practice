#include <bits/stdc++.h>
using namespace std;
int n,m,k,t;
int r,c,s;
int mn = 987654321;
int arr[54][54];
int dy[4] = {0,1,0,-1};
int dx[4] = {1,0,-1,0};
vector<tuple<int,int,int>>instructions;

void print(int a[54][54]){
    cout << "----------------\n";
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}

void _rotate(int a[54][54], int r, int c, int s){

    pair<int,int>start = {r-s, c-s};
    pair<int,int>end = {r+s, c+s};

    int depth = 2*(s+1)-1;
    while(depth > 1){
    
        int sy = start.first, sx = start.second;
        int y = sy, x = sx;
        int cnt = 0;

        vector<int>vals;
        vector<pair<int,int>>coords;

        coords.push_back({y,x});
        vals.push_back(a[y][x]);

        // Get the coordinates of the area that needs to be rotated
        while(true){
            int ny = y + dy[cnt];
            int nx = x + dx[cnt];

            // If the next step is over the selected border
            if (ny < start.first || nx < start.second || ny > end.first || nx > end.second){
                cnt++;
                ny = y + dy[cnt];
                nx = x + dx[cnt];
            }
            if (ny == start.first && nx == start.second) break;

            y = ny; 
            x = nx;

            coords.push_back({ny,nx});
            vals.push_back(a[ny][nx]);
        }

        rotate(vals.rbegin(), vals.rbegin()+1, vals.rend());

        for (int i=0; i<vals.size(); i++){
            a[coords[i].first][coords[i].second] = vals[i];
        }

        vals.clear();
        coords.clear();
        
        start = {start.first+1, start.second+1};
        end = {end.first-1, end.second-1};
        
        depth -= 2;
    }
}

void findMin(int a[54][54]){
    for (int i=1; i<=n; i++){
        int sum = 0;
        for (int j=1; j<=m; j++){
            sum += a[i][j];
        }
        mn = min(mn, sum);
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m >> k;
    for (int i=1; i<=n; i++){
        for (int j=1; j<=m; j++){
            cin >> arr[i][j];
        }
    }

    for (int i=0; i<k; i++){
        cin >> r >> c >> s;
        instructions.push_back({r,c,s});
    }

    sort(instructions.begin(), instructions.end());

    do {
        int buffer[54][54];
        memcpy(buffer, arr, sizeof(buffer));
        
        for (int i=0; i<instructions.size(); i++){
            int row,col,sVal;
            tie(row,col,sVal) = instructions[i];

            _rotate(buffer, row, col, sVal);
        }
        findMin(buffer);

    } while(next_permutation(instructions.begin(), instructions.end()));
    
    cout << mn << "\n";

    return 0;
}

// 4 4 4
// 1 3 1 4
// 2 4 2 3
// 7 3 7 9
// 4 9 3 7
// 2 2 1
// 2 3 1
// 3 2 1
// 3 3 1
// Ans: 7