#include <bits/stdc++.h>
using namespace std;
int n,x,y,d,g;
vector<int>dragon[4][11];
int arr[104][104];
const int dy[] = {0, -1, 0, 1};
const int dx[] = {1, 0, -1, 0};
// Finding a pattern is KEY!

void print(){
    for (int i=0; i<4; i++){
        for (int j=0; j<=10; j++){
            for (int k=0; k<n; k++){
                cout << dragon[i][j][k] << " ";
            }
            // cout << "\n";
        }
        cout << "\n";
    }
}

int countSquares(){
    int cnt = 0;
    for (int i=0; i<101; i++){
        for (int j=0; j<101; j++){
            if (arr[i][j] && arr[i+1][j] && arr[i][j+1] && arr[i+1][j+1]) cnt++;
        }
    }
    return cnt;
}

void solve(int x, int y, int d, int g){
    arr[y][x] = 1;
    for (int i=0; i<=g; i++){
        for (int dir : dragon[d][i]){
            y += dy[dir];
            x += dx[dir];
            arr[y][x] = 1;
        }
    }
}

// Make every possible combination first
void setup(){
    for (int i=0; i<4; i++){
        // 0th & 1st generation
        dragon[i][0].push_back(i);
        dragon[i][1].push_back((i+1)%4);
        // 2 - 10th generation
        for (int j=2; j<=10; j++){
            int n = dragon[i][j-1].size();
            for (int k=n-1; k>=0; k--){
                dragon[i][j].push_back((dragon[i][j-1][k] + 1) % 4);
            }
            for (int k=0; k<n; k++){
                dragon[i][j].push_back(dragon[i][j-1][k]);
            }
        }
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> n;
    setup();

    for (int i=0; i<n; i++){
        cin >> x >> y >> d >> g;
        solve(x,y,d,g);
    }

    cout << countSquares() << "\n";

    return 0;
}