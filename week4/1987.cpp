#include <bits/stdc++.h>
using namespace std;
int r,c;
string s;
char arr[21][21];
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};
int ret = 0;
int cnt = 0;
int letters;

void dfs(int y, int x){
    for (int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= r || nx >= c) continue;
        if (letters & (1 << int(arr[ny][nx] - 'A'))) continue;

        
        letters |= (1 << int(arr[ny][nx] - 'A'));
        cnt++;

        ret = max(ret, cnt);
        dfs(ny, nx);
        
        letters &= ~(1 << int(arr[ny][nx] - 'A'));
        cnt--;
    }
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin >> r >> c;
    for (int i=0; i<r; i++){
        cin >> s;
        for (int j=0; j<c; j++){
            arr[i][j] = s[j];
        }
    }

    letters = (1 << (arr[0][0] - 'A'));
    dfs(0,0);

    cout << ret+1 << "\n";

    return 0;
}