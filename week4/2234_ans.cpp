#include <bits/stdc++.h>
using namespace std;
int n,m;
int arr[51][51];
int visited[51][51];
int compSize[2502];
int dy[] = {0, -1, 0, 1}; 
int dx[] = {-1, 0, 1, 0}; 
int cnt, mx;
int maxRoom = 0;

void print(int a[51][51]){
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            cout << a[i][j] << " ";
        }
        cout << "\n";
    }
}

int dfs(int y, int x, int cnt){
    if (visited[y][x]) return 0;

    visited[y][x] = cnt;
    int ret = 1;
    for (int i=0; i<4; i++){
        if (!(arr[y][x] & (1 << i))){
            int ny = y + dy[i];
            int nx = x + dx[i];

            ret += dfs(ny, nx, cnt);
        }
    }

    return ret;
}

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(0); cout.tie(0);

    cin >> n >> m;
    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }

    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if (!visited[i][j]){
                cnt++;
                compSize[cnt] = dfs(i,j,cnt);
                mx = max(mx, compSize[cnt]);
            }
        }
    }

    print(visited);

    cout << "------------------\n";

    // Iterate through the visited array and also compare two points :
    // one that is 1 step ahead in row
    // another that is 1 step ahead in col
    // If the assigned room number is different for these two other coordinates
    // Access the compSize array which linearly lines up all the room area info for each room (#1 - #n)
    // and add them up 

    // int a = visited[i][j] <- current coordinate
    // int b = visited[i][j+1] <- 1 point ahead in row
    // int c = visited[i+1][j] <- 1 point ahead in col

    // if (a != b)
    // maxRoom = max(maxRoom, compSize[a] + compSize[b])

    // if (a != c)
    // maxRoom = max(maxRoom, compSize[a] + compSize[c])
    for (int i=0; i<m-1; i++){
        for (int j=0; j<n-1; j++){
            int a = visited[i][j];
            int b = visited[i+1][j];
            int c = visited[i][j+1];

            if (a != b){
                maxRoom = max(maxRoom, compSize[a] + compSize[b]);
            }

            if (a != c){
                maxRoom = max(maxRoom, compSize[a] + compSize[c]);
            }
        }
    }

    cout << cnt << "\n";
    cout << mx << "\n";
    cout << maxRoom << "\n";

    return 0;
}