#include <bits/stdc++.h>
using namespace std;
int m,n,k, ret, area;
int left_x, left_y, right_x, right_y;
int arr[104][104];
int visited[104][104];
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};
vector<int>v;

// Only for debugging
void print(int a[104][104]){
    for (int i=0; i<20; i++){
        for (int j=0; j<20; j++){
            cout << arr[i][j] << " ";
        }
        cout << "\n";
    }
}

void dfs(int y, int x){
    // Counts the number of times the function has iterated over 
    // when it encounters a new tree that's not been visited before.
    area++; 
    visited[y][x] = 1;
    for (int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= m || nx >= n) continue;
        if (visited[ny][nx]) continue;
        if (arr[ny][nx] == 0) continue;

        dfs(ny, nx);
    }
}

int main(){
    cin >> m >> n >> k;
    // Initialize the graph with 1s
    fill(&arr[0][0], &arr[m][n], 1);

    // Fill the rest of the area that's out of bounds as 0s
    for (int i = 0; i < 104; i++) {
        for (int j = 0; j < 104; j++) {
            if (i >= m || j >= n) {
                arr[i][j] = 0;
            }
        }
    }

    // Take the rectangle coordinates and make them 0
    while(k--){
        cin >> left_x >> left_y >> right_x >> right_y;
        for (int i=left_y; i<right_y; i++){
            for (int j=left_x; j<right_x; j++){
                arr[i][j] = 0;
            }
        }
    }

    // print(arr);

    for (int i=0; i<m; i++){
        for (int j=0; j<n; j++){
            if (arr[i][j] && visited[i][j] == 0){
                area = 0;
                ret++;
                // This recursive function only runs as many times as  
                // children nodes in each tree
                dfs(i,j); 
                v.push_back(area);
            }
        }
    }

    // Print out the results:
    //  Number of connected components AND number of nodes in each tree
    cout << ret << "\n";
    sort(v.begin(), v.end());
    for (int i : v) cout << i << " ";

    return 0;
}