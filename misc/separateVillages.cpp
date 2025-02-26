#include <bits/stdc++.h>
using namespace std;

// https://www.codetree.ai/missions/2/problems/seperate-village/description

int n;
int arr[26][26];
int visited[26][26];
int dy[] = {-1,0,1,0};
int dx[] = {0,1,0,-1};
int area;
vector<int>v;

void dfs(int y, int x){
    area++;
    visited[y][x] = 1;
    for (int i=0; i<4; i++){
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || nx < 0 || ny >= n || nx >= n) continue;
        if (visited[ny][nx]) continue;
        if (arr[ny][nx] == 0) continue;

        

        dfs(ny, nx);
    }
}

int main() {

    cin >> n;

    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            cin >> arr[i][j];
        }
    }

    int villageCnt = 0;
    for (int i=0; i<n; i++){
        for (int j=0; j<n; j++){
            if (arr[i][j] && visited[i][j] == 0){
                area = 0;
                villageCnt++;
                dfs(i,j);
                v.push_back(area);
            }
        }
    }

    cout << villageCnt << "\n";
    sort(v.begin(), v.end());
    for (int i : v) cout << i << "\n";
    
    return 0;
}